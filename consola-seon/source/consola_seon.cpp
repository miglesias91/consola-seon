#include <consola-seon/include/consola_seon.h>

// stl
#include <memory>

// qt
#include <qpushbutton.h>

consola_seon::consola_seon(seon::video::administrador * admin_video, seon::comunicacion::administrador * admin_comunicacion, seon::aplicacion::configuracion::gui config_gui, QWidget *parent)
    : admin_video(admin_video),
    config_gui(config_gui),
    filmacion(admin_video), 
    grabacion(admin_video),
    comu(admin_comunicacion),
    hud(nullptr),
    QMainWindow(parent)
{
    ui.setupUi(this);

    // seteo incio
    this->configurar_gui();

    // conecto signals con slots
    QObject::connect(this->ui.btn_filmar, &QPushButton::released, this, &consola_seon::comenzar_filmacion);
    QObject::connect(this->ui.btn_grabar, &QPushButton::released, this, &consola_seon::comenzar_grabacion);

    QObject::connect(this, &consola_seon::screenshot_listo, &this->grabacion, &grabacion_opencv::imagen_lista);

    QObject::connect(&this->comu, &comunicador::nuevo_mensaje_gps, this, &consola_seon::mostrar_mensaje_gps);
    QObject::connect(&this->comu, &comunicador::nuevo_mensaje_pulsadores, this, &consola_seon::mostrar_mensaje_pulsadores);
    QObject::connect(&this->comu, &comunicador::nuevo_mensaje_pupitre, this, &consola_seon::mostrar_mensaje_pupitre);
    QObject::connect(&this->comu, &comunicador::nuevo_mensaje_seon, this, &consola_seon::mostrar_mensaje_seon);

    // seteo las propiedades de gui
    this->filmacion.hijo_de(this->ui.panel_central);
    this->filmacion.tamanio(this->config_gui.area_video.tamanio.ancho, this->config_gui.area_video.tamanio.alto);
    this->filmacion.posicion(this->config_gui.area_video.posicion.x, this->config_gui.area_video.posicion.y);

    this->ui.panel_lateral->resize(this->config_gui.panel_lateral.tamanio.ancho, this->config_gui.panel_lateral.tamanio.alto);
    this->ui.panel_lateral->move(this->config_gui.panel_lateral.posicion.x, this->config_gui.panel_lateral.posicion.y);
    this->ui.panel_lateral->raise();

    this->ui.panel_superior->resize(this->config_gui.panel_superior.tamanio.ancho, this->config_gui.panel_superior.tamanio.alto);
    this->ui.panel_superior->move(this->config_gui.panel_superior.posicion.x, this->config_gui.panel_superior.posicion.y);
    this->ui.panel_superior->raise();

    this->ui.btn_filmar->raise();
    this->ui.btn_grabar->raise();
    this->ui.widget_comunicaciones->raise();

    this->comu.iniciar();

    this->hud = new gui::hud::hud(this->config_gui.area_video, this->admin_video->configuracion, this->ui.panel_central);

    QWidget* lancha = new gui::hud::lanchas(this->admin_video->configuracion.lanchas, this->hud);
    QWidget* radar = new gui::hud::radar(this->admin_video->configuracion.radar, this->ui.lbl_dist_valor, this->ui.lbl_azimut_radar_valor, this->ui.lbl_tipo_valor, this->ui.widget_datos_radar, this->hud);

    this->hud->raise();
    lancha->raise();
    radar->raise();

    QWidget* tracking = new gui::hud::tracking(this->admin_video->configuracion.tracking, this->hud);
    tracking->raise();

    this->ui.btn_filmar->raise();
    this->ui.widget_datos_radar->raise();
}

consola_seon::~consola_seon() {

    this->comu.cortar();
    this->timer.stop();
    seon::aplicacion::logger::info("cerrando consola.");
}

void consola_seon::configurar_gui()
{
    // testigo pantalla
    this->ui.lbl_pantalla_barrido->hide();
    this->ui.lbl_pantalla_datos->hide();

    // testigo camara
    this->ui.lbl_camara_ir->hide();

    // testigo foco
    this->ui.lbl_foco_cerca->hide();
    this->ui.lbl_foco_apagado->hide();

    // testigo engache
    this->ui.lbl_enganche_diferenciado->hide();
    this->ui.lbl_enganche_cuantificado_inv->hide();

    // testigo modo
    this->ui.lbl_modo_esclavo->hide();
    this->ui.lbl_modo_fijo->hide();

    // testigo video
    this->ui.lbl_video_cuantificado->hide();
    this->ui.lbl_video_diferenciado->hide();

    // testigo ventana optica
    this->ui.lbl_optica_apagada_lava->hide();
    this->ui.lbl_optica_apagada_limpia->hide();
    this->ui.lbl_optica_lava->hide();

    // testigo zoom
    this->ui.lbl_zoom_apagado->hide();
    this->ui.lbl_zoom_estrecho->hide();

    std::for_each(this->config_gui.elementos.begin(), this->config_gui.elementos.end(),
        [this](seon::aplicacion::configuracion::elemento elemento)
    {
        QLabel * etiqueta = this->ui.panel_central->findChild<QLabel*>(elemento.id.c_str());
        if (etiqueta) {
            etiqueta->setText(elemento.texto.c_str());
            etiqueta->setStyleSheet(("background-color: rgb(" + elemento.color_primario.rgb() + ");").c_str());
        }
        else {
            seon::aplicacion::logger::advertencia("El elemento con id '" + elemento.id + "' no existe.");
        }
    });
}

void consola_seon::mostrar_mensaje_gps(const seon::comunicacion::trama_gps & trama) {

    this->ui.lineedit_gps->setText(trama.tira_de_datos.c_str());
}

void consola_seon::mostrar_mensaje_pupitre(const seon::comunicacion::trama_pupitre & trama) {

    this->ui.lineedit_pupitre->setText(trama.tira_de_datos.c_str());
}

void consola_seon::mostrar_mensaje_pulsadores(const seon::comunicacion::trama_pulsadores & trama) {

    this->ui.lineedit_pulsadores->setText(trama.tira_de_datos.c_str());
}

void consola_seon::mostrar_mensaje_seon(const seon::comunicacion::trama_seon & trama) {

    this->ui.lineedit_seon->setText(trama.tira_de_datos.c_str());
}

void consola_seon::comenzar_filmacion()
{
    seon::aplicacion::logger::info("filmacion iniciada.");
    this->filmacion.iniciar();
}

void consola_seon::comenzar_grabacion() {

    seon::aplicacion::logger::info("grabacion iniciada.");
    this->grabacion.iniciar();

    this->timer.start((1000 / (this->admin_video->configuracion.grabacion.fps + 10)), this);
}

void consola_seon::timerEvent(QTimerEvent * ev) {

    if (ev->timerId() != this->timer.timerId()) return;

    QScreen * screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
        screen = window->screen();
    if (!screen)
        return;
    
    emit screenshot_listo(screen->grabWindow(this->ui.panel_central->winId()).toImage());
}

