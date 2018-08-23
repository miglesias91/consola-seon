#include <consola-seon/include/lanchas.h>

namespace gui::hud {

lanchas::lanchas(const seon::aplicacion::configuracion::lanchas &config, QWidget *parent) :
    config(config), QWidget(parent) {
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->resize(this->config.tamanio.ancho, this->config.tamanio.alto);
    //this->move(this->config.posicion.x, this->config.posicion.y);
}

lanchas::~lanchas() {}

void lanchas::paintEvent(QPaintEvent *paintEvent) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::blue, 12, Qt::DashDotLine, Qt::RoundCap));
    painter.drawLine(0, 0, 620, 600);
}
}