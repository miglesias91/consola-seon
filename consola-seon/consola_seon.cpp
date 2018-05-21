#include "consola_seon.h"

// stl
#include <memory>

// qt
#include <qpushbutton.h>

consola_seon::consola_seon(seon::video::administrador * admin_video, QWidget *parent)
    : admin_video(admin_video), video(admin_video), QMainWindow(parent)
{
    ui.setupUi(this);

    // seteo incio
    this->setear_inicio();

    // conecto signals con slots
    QObject::connect(this->ui.boton, &QPushButton::released, this, &consola_seon::comenzar_filmacion);

    this->video.hijo_de(this->ui.panel_central);
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
