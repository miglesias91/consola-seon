#include <consola-seon/include/radar.h>

namespace gui::hud {

radar::radar(const seon::aplicacion::configuracion::radar &config, QLabel *distancia, QLabel *azimut, QLabel *tipo, QWidget *tabla, QWidget *parent) :
    config(config), distancia(distancia), azimut(azimut), tipo(tipo), tabla(tabla),
    QWidget(parent) {
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->resize(this->parentWidget()->size());
    this->tabla->move(this->config.posicion.x, this->config.posicion.y);
    this->tabla->resize(this->config.tamanio.ancho, this->config.tamanio.alto);
    this->tabla->setParent(parent);
}

radar::~radar() {}

void radar::paintEvent(QPaintEvent *paintEvent) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 12, Qt::DashDotLine, Qt::RoundCap));
    painter.drawLine(0, 0, 660, 600);
}
}