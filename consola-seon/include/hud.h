#pragma once

// qt
#include <QtWidgets>

// hud
#include <consola-seon/include/lanchas.h>
#include <consola-seon/include/radar.h>
#include <consola-seon/include/tracking.h>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace gui::hud {

class hud : public QWidget {
    Q_OBJECT

public:
    hud(const seon::aplicacion::configuracion::ventana &config_hud, const seon::aplicacion::configuracion::video &config_video, QWidget *parent = nullptr);
    virtual ~hud();

    void tabla(radar *tabla_radar);
    radar* tabla() const;

    void dibujo(lanchas *dibujo_lanchas);
    lanchas* dibujo() const;

    void reticulas(tracking *reticulas_tracking);
    tracking* reticulas() const;
        ;
private:
    seon::aplicacion::configuracion::ventana config_hud;
    seon::aplicacion::configuracion::video config_video;

    lanchas *dibujo_lanchas;
    radar *tabla_radar;
    tracking *reticulas_tracking;
};

}