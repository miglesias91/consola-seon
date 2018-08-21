#include <consola-seon/include/hud.h>

namespace gui::hud {

hud::hud(const uint32_t &ancho, const uint32_t &alto, const uint32_t &x, const uint32_t &y, QWidget * parent) :
    ancho(ancho), alto(alto), x(x), y(y),
    QWidget(parent) {
    //setAttribute(Qt::WA_OpaquePaintEvent);
    this->resize(ancho, alto);
    this->move(x, y);
}

hud::~hud() {}

void hud::paintEvent(QPaintEvent * evento) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::green, 12, Qt::DashDotLine, Qt::RoundCap));
    painter.drawLine(0, 0, 600, 600);

    painter.drawText()

    std::for_each(this->sprites.begin(), this->sprites.end(), [=](gui::hud::sprite *sprite) {
        sprite->dibujar(painter);
    });
}

}