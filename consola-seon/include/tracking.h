#pragma once

// qt
#include <QtWidgets>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace gui::hud {

class reticula : public QWidget {
    Q_OBJECT
public:
    reticula(const seon::aplicacion::configuracion::reticula &config, QWidget *parent = nullptr)
    : config(config), QWidget(parent) {
    }

    virtual ~reticula() {};

protected:
    void paintEvent(QPaintEvent *paintEvent) override {
        int32_t esquina_izq_arriba, esquina_izq_abajo, esquina_der_abajo, esquina_der_arriba;
        this->parentWidget()->rect().getCoords(&esquina_izq_arriba, &esquina_izq_abajo, &esquina_der_abajo, &esquina_der_arriba);


    }

private:
    seon::aplicacion::configuracion::reticula config;
};

class tracking : public QWidget {
    Q_OBJECT

public:
    tracking(const seon::aplicacion::configuracion::tracking &config, QWidget *parent = nullptr);
    virtual ~tracking();

protected:
    void paintEvent(QPaintEvent *paintEvent) override;

private:
    seon::aplicacion::configuracion::tracking config;
    reticula mayor, media, menor;
};

}