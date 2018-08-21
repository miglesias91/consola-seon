#pragma once

// qt
#include <QtWidgets>

namespace gui::hud {

class hud : public QWidget {
    Q_OBJECT

public:
    hud(const uint32_t &ancho = 0, const uint32_t &alto = 0, const uint32_t &x = 0, const uint32_t &y = 0, QWidget * parent = nullptr);
    virtual ~hud();

protected:
    void paintEvent(QPaintEvent *paintEvent) override;

private:
    uint32_t ancho, alto, x, y;

};

}