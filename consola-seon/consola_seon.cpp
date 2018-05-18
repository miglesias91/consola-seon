#include "consola_seon.h"

// stl
#include <memory>

// qt
#include <qgraphicsvideoitem.h>
#include <qsizepolicy.h>

consola_seon::consola_seon(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // seteo incio
    this->setear_inicio();

    // muestro video
    QVideoWidget * video = new QVideoWidget(this->ui.panel_central);

    this->reproductor.setVideoOutput(video);

    unsigned long long int w = this->ui.panel_central->size().width();
    w = this->ui.panel_central->width();
    unsigned long long int h = this->ui.panel_central->size().height();
    h = this->ui.panel_central->height();

    video->resize(QSize(1024, 860));

    this->reproductor.setMedia(QUrl("oficina.mp4"));
    this->reproductor.play();

    video->lower();
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
