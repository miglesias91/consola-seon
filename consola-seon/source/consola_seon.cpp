#include <consola-seon/include/consola_seon.h>

// stl
#include <memory>

// qt
#include <qpushbutton.h>

// utiles
#include <utiles/include/FuncionesString.h>

consola_seon::consola_seon(seon::video::administrador * admin_video, seon::comunicacion::administrador * admin_comunicacion, seon::aplicacion::configuracion::gui config_gui, QWidget *parent)
    : admin_video(admin_video),
    config_gui(config_gui),
    filmacion(admin_video), 
    grabacion(admin_video),
    comu(admin_comunicacion),
    hud(nullptr),
    gestor(new gestor_ejercicios(admin_video->configuracion.grabacion.carpeta)),
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

    QObject::connect(this->ui.checkbox_gestor, &QCheckBox::stateChanged, this, &consola_seon::abrir_cerrar_gestor);

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

    this->ui.widget_comunicaciones->raise();

    this->comu.iniciar();

    this->hud = new gui::hud::hud(this->config_gui.area_video, this->admin_video->configuracion, this->ui.panel_central);

    gui::hud::lanchas* lancha = new gui::hud::lanchas(this->admin_video->configuracion.lanchas, this->hud);
    gui::hud::radar* radar = new gui::hud::radar(this->admin_video->configuracion.radar, this->ui.lbl_dist_valor, this->ui.lbl_azimut_radar_valor, this->ui.lbl_tipo_valor, this->ui.widget_datos_radar, this->hud);

    this->hud->raise();
    lancha->raise();
    radar->raise();

    gui::hud::tracking* tracking = new gui::hud::tracking(this->admin_video->configuracion.tracking, this->hud);
    tracking->raise();

    this->hud->tabla(radar);
    this->hud->dibujo(lancha);
    this->hud->reticulas(tracking);

    this->ui.btn_filmar->raise();
    this->ui.btn_grabar->raise();
    this->ui.widget_datos_radar->raise();
}

consola_seon::~consola_seon() {

    this->comu.cortar();
    this->timer.stop();
    seon::aplicacion::logger::info("cerrando consola.");
}

void consola_seon::configurar_gui() {
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

    this->ui.lbl_longitud_valor->setText((herramientas::utiles::FuncionesString::toString(trama.longitud.angulo, 2) + " " + trama.longitud.cardinalidad).c_str());
    this->ui.lbl_latitud_valor->setText((herramientas::utiles::FuncionesString::toString(trama.latitud.angulo, 2) + " " + trama.latitud.cardinalidad).c_str());

    this->ui.lineedit_gps->setText(trama.tira_de_datos.c_str());
}

void consola_seon::mostrar_mensaje_pupitre(const seon::comunicacion::trama_pupitre & trama) {

    if (trama.boton_2) {
        this->hud->reticulas()->agrandar();
    }
    if (trama.boton_3) {
        this->hud->reticulas()->achicar();
    }

    if (trama.graba_pic) {
        this->comenzar_grabacion();
    }
    if (false == trama.graba_pic) {
        this->detener_grabacion();
    }

    if (trama.acc_archivo_pic && false == this->gestor) {
        this->gestor->show();
    }
    if (false == trama.acc_archivo_pic && this->gestor) {
        this->gestor->close();
    }

    this->ui.lineedit_pupitre->setText(trama.tira_de_datos.c_str());
}

void consola_seon::mostrar_mensaje_pulsadores(const seon::comunicacion::trama_pulsadores & trama) {

    this->ui.lbl_imu_prob->setVisible(trama.ref_est);
    this->ui.lbl_octans->setVisible(!trama.ref_est);

    this->ui.lbl_pantalla_datos->setVisible(trama.pantalla_datos);
    this->ui.lbl_pantalla_barrido->setVisible(trama.pantalla_barrido);
    this->ui.lbl_pantalla_normal->setVisible(trama.pantalla_normal);

    this->ui.lbl_optica_lava->setVisible(trama.ventana_optica_lava);
    this->ui.lbl_optica_apagada_lava->setVisible(!trama.ventana_optica_lava);
    this->ui.lbl_optica_limpia->setVisible(trama.ventana_optica_limpia);
    this->ui.lbl_optica_apagada_limpia->setVisible(!trama.ventana_optica_limpia);

    this->ui.lbl_camara_ir->setVisible(trama.camara_ir);
    this->ui.lbl_camara_diurna->setVisible(trama.camara_diurna);

    this->ui.lbl_zoom_amplio->setVisible(trama.zoom_amplio);
    this->ui.lbl_zoom_estrecho->setVisible(trama.zoom_estrecho);
    this->ui.lbl_zoom_apagado->setVisible(trama.zoom_estrecho == false && trama.zoom_amplio == false);

    this->ui.lbl_foco_cerca->setVisible(trama.foco_cerca);
    this->ui.lbl_foco_lejos->setVisible(trama.foco_lejos);
    this->ui.lbl_foco_apagado->setVisible(trama.foco_cerca == false && trama.foco_lejos == false);

    this->ui.lbl_video_cuantificado->setVisible(trama.video_cuantificado);
    this->ui.lbl_video_diferenciado->setVisible(trama.video_diferenciado);
    this->ui.lbl_video_normal->setVisible(trama.video_normal);

    this->ui.lbl_enganche_cuantificado->setVisible(trama.enganche_cuantificado);
    this->ui.lbl_enganche_diferenciado->setVisible(trama.enganche_diferenciado);
    this->ui.lbl_enganche_cuantificado_inv->setVisible(trama.enganche_cuantificado == false && trama.enganche_diferenciado == false);

    this->ui.lbl_modo_fijo->setVisible(trama.modo_fijo);
    this->ui.lbl_modo_esclavo->setVisible(trama.modo_esclavo);
    this->ui.lbl_modo_estable->setVisible(trama.modo_estable);

    this->ui.lineedit_pulsadores->setText(trama.tira_de_datos.c_str());
}

void consola_seon::mostrar_mensaje_seon(const seon::comunicacion::trama_seon & trama) {

    std::string color = "";
    if (trama.origen == seon::comunicacion::trama_seon::origen_dato::TELEMETRO) {
        color = "blanco";
    }
    if (trama.origen == seon::comunicacion::trama_seon::origen_dato::MANUAL) {
        color = "amarillo";
    }
    if (trama.origen == seon::comunicacion::trama_seon::origen_dato::DEFECTO) {
        color = "celeste";
    }
    this->color_fondo(this->ui.lbl_distancia, color);
    this->color_fondo(this->ui.lbl_distancia_valor, color);

    if (trama.enganche) {
        if (trama.prediccion) {  // enganche = 1 , prediccion = 1 -> manual
            this->color_fondo(this->ui.lbl_enganche_etiqueta, "blanco");
            this->color_fondo(this->ui.lbl_prediccion, "blanco");
        }
        else {  // enganche = 1 , prediccion = 0 -> enganche
            this->color_fondo(this->ui.lbl_enganche_etiqueta, "verde_claro");
            this->color_fondo(this->ui.lbl_prediccion, "blanco");
        }
    }
    else {
        if (trama.prediccion) {  // enganche = 0 , prediccion = 1 -> manual
            this->color_fondo(this->ui.lbl_enganche_etiqueta, "blanco");
            this->color_fondo(this->ui.lbl_prediccion, "verde_claro");
        }
    }

    this->ui.lbl_velocidad_valor->setText(("n" + std::to_string(trama.velocidad)).c_str());
    //this->ui.zoom
    if (trama.radar_activado) {
        this->ui.widget_datos_radar->setVisible(true);
        this->ui.lbl_dist_valor->setText((std::to_string(trama.distancia_radar) + " y").c_str());
        this->ui.lbl_azimut_radar_valor->setText((herramientas::utiles::FuncionesString::toString(trama.azimut_radar, 2) + " °").c_str());
        this->ui.lbl_tipo_valor->setText(trama.tipo_blanco.c_str());
    }
    else {
        this->ui.widget_datos_radar->setVisible(false);
    }

    this->hud->dibujo()->azimut(trama.azimut_grafico);
    this->hud->dibujo()->elevacion(trama.elevacion_grafico);
    this->ui.lbl_azimut_valor->setText((herramientas::utiles::FuncionesString::toString(trama.azimut_absoluto, 2) + " °").c_str());
    this->ui.lbl_elevacion_valor->setText((herramientas::utiles::FuncionesString::toString(trama.elevacion_absoluta, 2) + " °").c_str());

    //trama.centro_gravedad ???
    //trama.corrimiento ???
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

void consola_seon::detener_grabacion() {
    this->timer.stop();
}

void consola_seon::color_fondo(QWidget * widget, const std::string & color) {
    widget->setStyleSheet(("background-color: rgb(" + this->config_gui.colores[color].rgb() + ");").c_str());
}

void consola_seon::abrir_cerrar_gestor() {
    if (this->ui.checkbox_gestor->isChecked()) {
        this->gestor->actualizar();
        this->gestor->show();
    }
    if (false == this->ui.checkbox_gestor->isChecked()) {
        this->gestor->close();
    }
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

