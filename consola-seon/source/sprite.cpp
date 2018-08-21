#include <consola-seon/include/sprite.h>

namespace gui::hud {

sprite::sprite(const uint32_t &ancho, const uint32_t &alto, const uint32_t &x, const uint32_t &y, QWidget * parent) :
    ancho(ancho), alto(alto), x(x), y(y),
    QWidget(parent) {}

sprite::~sprite() {}

}