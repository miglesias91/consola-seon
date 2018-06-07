#include <consola-seon/include/consola_seon.h>

// stl
#include <memory>

// qt
#include <qpushbutton.h>

consola_seon::consola_seon(seon::video::administrador * admin_video, seon::aplicacion::configuracion::gui config_gui, QWidget *parent)
    : admin_video(admin_video),
    config_gui(config_gui),
    filmacion(admin_video), 
    grabacion(admin_video),
    QMainWindow(parent)
{
    ui.setupUi(this);

    // seteo incio
    this->setear_inicio();

    // conecto signals con slots
    QObject::connect(this->ui.btn_filmar, &QPushButton::released, this, &consola_seon::comenzar_filmacion);
    QObject::connect(this->ui.btn_grabar, &QPushButton::released, this, &consola_seon::comenzar_grabacion);

    QObject::connect(this, &consola_seon::screenshot_listo, &this->grabacion, &grabacion_opencv::imagen_lista);

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
}

consola_seon::~consola_seon() {

    this->timer.stop();
    seon::aplicacion::logger::info("cerrando consola.");
}

void consola_seon::setear_inicio()
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
}

void consola_seon::comenzar_filmacion()
{
    seon::aplicacion::logger::info("filmacion iniciada.");
    this->filmacion.iniciar();
}

void consola_seon::comenzar_grabacion() {

    seon::aplicacion::logger::info("grabacion iniciada.");
    this->grabacion.iniciar();

    this->timer.start((1000 / this->admin_video->configuracion.grabacion.fps), this);
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

