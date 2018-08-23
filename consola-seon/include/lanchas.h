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

protected:
    void paintEvent(QPaintEvent *paintEvent) override;

private:
    seon::aplicacion::configuracion::lanchas config;

};

}