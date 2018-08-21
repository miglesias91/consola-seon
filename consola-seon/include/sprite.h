#pragma once

// qt
#include <QtWidgets/qwidget.h>

namespace gui::hud {

class sprite : public QWidget {
    Q_OBJECT

public:
    sprite(const uint32_t &ancho = 0, const uint32_t &alto = 0, const uint32_t &x = 0, const uint32_t &y = 0, QWidget * parent = nullptr);
    virtual ~sprite();

private:
    uint32_t ancho, alto, x, y;

};

}