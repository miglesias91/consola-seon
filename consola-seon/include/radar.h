#pragma once

// qt
#include <QtWidgets>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace gui::hud {

class radar : public QWidget {
    Q_OBJECT

public:
    radar(const seon::aplicacion::configuracion::radar &config, QLabel *distancia, QLabel *azimut, QLabel *tipo, QWidget *tabla, QWidget *parent = nullptr);
    virtual ~radar();

private:
    QLabel *distancia, *azimut, *tipo;
    QWidget *tabla;
    seon::aplicacion::configuracion::radar config;

};

}