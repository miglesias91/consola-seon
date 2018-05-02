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

    //this->ui.widget_superior->setWindowFlags(Qt::FramelessWindowHint);

    //this->ui.widget_superior->setAttribute(Qt::WA_TranslucentBackground);
    //this->ui.widget_superior->setAttribute(Qt::WA_NoSystemBackground);
    //this->ui.widget_superior->setAttribute(Qt::WA_PaintOnScreen, false);


    // muestro video
    QVideoWidget * video = new QVideoWidget(this->ui.frame);

    this->reproductor.setVideoOutput(video);
    video->resize(QSize(this->ui.frame->size().width(), this->ui.frame->size().height()));
    
    //this->ui.widget_video->addWidget(video);

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
