#pragma once

// qt
#include <QtWidgets>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace gui::hud {

class hud : public QWidget {
    Q_OBJECT

public:
    hud(const seon::aplicacion::configuracion::ventana &config_hud, const seon::aplicacion::configuracion::video &config_video, QWidget *parent = nullptr);
    virtual ~hud();

private:
    seon::aplicacion::configuracion::ventana config_hud;
    seon::aplicacion::configuracion::video config_video;

};

}