#include <consola-seon/include/tracking.h>

namespace gui::hud {

tracking::tracking(const seon::aplicacion::configuracion::tracking &config, QWidget *parent) :
    config(config), mayor(config.mayor), media(config.media), menor(config.menor),
    QWidget(parent) {
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->resize(this->config.mayor.tamanio.ancho, this->config.mayor.tamanio.alto);

}

tracking::~tracking() {}

void tracking::paintEvent(QPaintEvent * evento) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::yellow, 12, Qt::DashDotLine, Qt::RoundCap));
    painter.drawLine(0, 0, 640, 600);
}
}