#pragma once

// qt
#include <QtWidgets>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace gui::hud {

class radar : public QWidget {
    Q_OBJECT

public:
    radar(const seon::aplicacion::configuracion::radar &config, QWidget *tabla, QWidget *parent = nullptr);
    virtual ~radar();

protected:
    void paintEvent(QPaintEvent *paintEvent) override;

private:
    QWidget *tabla;
    seon::aplicacion::configuracion::radar config;

};

}