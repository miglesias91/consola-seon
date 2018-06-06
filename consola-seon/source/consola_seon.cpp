#include <consola-seon/include/consola_seon.h>

// stl
#include <memory>

// qt
#include <qpushbutton.h>

consola_seon::consola_seon(seon::video::administrador * admin_video, seon::aplicacion::configuracion::gui config_gui, QWidget *parent)
    : admin_video(admin_video), video(admin_video), config_gui(config_gui),
    grabador_video(admin_video->salida(), 30, admin_video->configuracion.resolucion.ancho, admin_video->configuracion.resolucion.alto),
    grabacion_activada(false), QMainWindow(parent)
{
    ui.setupUi(this);

    // seteo incio
    this->setear_inicio();

    // conecto signals con slots
    QObject::connect(this->ui.btn_filmar, &QPushButton::released, this, &consola_seon::comenzar_filmacion);
    QObject::connect(this->ui.btn_grabar, &QPushButton::released, this, &consola_seon::comenzar_grabacion);

    // seteo las propiedades de gui
    this->video.hijo_de(this->ui.panel_central);
    this->video.tamanio(this->config_gui.area_video.tamanio.ancho, this->config_gui.area_video.tamanio.alto);
    this->video.posicion(this->config_gui.area_video.posicion.x, this->config_gui.area_video.posicion.y);

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

    this->grabacion_activada = false;
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
    this->video.iniciar();
}

void consola_seon::comenzar_grabacion() {

    this->hilo_grabador.start(QThread::Priority::HighPriority);
    this->grabador_video.moveToThread(&this->hilo_grabador);

    grabacion_activada = true;
    QWidget * panel_central = this->ui.panel_central;

    QtConcurrent::run([this]() {

        while (this->grabacion_activada) {

            this->ui.panel_central->grab().toImage();

            this->grabador_video.fotograma_listo(this->ui.panel_central->grab().toImage());

            QThread::msleep(1000 / 30); // 30 fps.
        }

    });
}
