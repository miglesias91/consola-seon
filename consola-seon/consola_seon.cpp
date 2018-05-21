#include "consola_seon.h"

// stl
#include <memory>

// qt
#include <qpushbutton.h>

consola_seon::consola_seon(seon::video::administrador * admin_video, seon::aplicacion::configuracion::gui config_gui, QWidget *parent)
    : admin_video(admin_video), video(admin_video), config_gui(config_gui), QMainWindow(parent)
{
    ui.setupUi(this);

    // seteo incio
    this->setear_inicio();

    // conecto signals con slots
    QObject::connect(this->ui.boton, &QPushButton::released, this, &consola_seon::comenzar_filmacion);

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

    this->ui.boton->raise();
}

consola_seon::~consola_seon() {
    //delete this->video;
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
    this->video.iniciar();
}

void consola_seon::dibujar_fotograma(QImage imagen) {

    //if (!imagen.isNull()) {
    //    this->ui.label->setAlignment(Qt::AlignCenter);
    //    this->ui.label->setPixmap(QPixmap::fromImage(imagen).scaled(this->ui.label->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    //}

    //emit imagen_procesada();
}
