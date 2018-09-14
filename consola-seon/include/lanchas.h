#pragma once

// qt
#include <QtWidgets>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace gui::hud {

class lanchas : public QWidget {
    Q_OBJECT

public:
    lanchas(const seon::aplicacion::configuracion::lanchas &config, QWidget *parent = nullptr);
    virtual ~lanchas();

    void azimut(const uint8_t &valor);
    void elevacion(const uint8_t &valor);

protected:
    void paintEvent(QPaintEvent *paintEvent) override;

private:

    // rota el punto (x, y) ASUMIENDO que el pivot esta en el origen.
    void rotar(const uint8_t &angulo, int32_t *x, int32_t *y) const;

    seon::aplicacion::configuracion::lanchas config;

    uint8_t azimut_lancha, elevacion_lancha;  // angulos

};

}