#include <consola-seon/include/radar.h>

namespace gui::hud {

radar::radar(const seon::aplicacion::configuracion::radar &config, QWidget *tabla, QWidget *parent) :
    config(config), tabla(tabla), 
    QWidget(parent) {
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->resize(this->config.tamanio.ancho, this->config.tamanio.alto);
    //this->move(this->config.posicion.x, this->config.posicion.y);
}

radar::~radar() {}

void radar::paintEvent(QPaintEvent *paintEvent) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 12, Qt::DashDotLine, Qt::RoundCap));
    painter.drawLine(0, 0, 660, 600);
}
}