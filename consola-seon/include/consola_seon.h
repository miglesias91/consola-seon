#pragma once

// qt
#include <QtWidgets/QMainWindow>
#include <QtMultimedia/qmediaplayer.h>
#include <QtConcurrent/qtconcurrentrun.h>

#include "ui_consola_seon.h"

// aplicacion
#include <aplicacion/include/configuracion.h>
#include <aplicacion/include/logger.h>

// comunicacion
#include <comunicacion/include/administrador.h>

// video
#include <video/include/administrador.h>
#include <video/include/vista.h>

// consola seon
#include <consola-seon/include/filmacion_opencv.h>
#include <consola-seon/include/grabacion_opencv.h>
#include <consola-seon/include/comunicador.h>

// consola
#include <consola-seon/include/hud.h>
#include <consola-seon/include/tracking.h>
#include <consola-seon/include/radar.h>
#include <consola-seon/include/lanchas.h>

class consola_seon : public QMainWindow
{
    Q_OBJECT

    Q_SIGNAL void screenshot_listo(const QImage & screenshot);

public:
    consola_seon(seon::video::administrador * admin_video, seon::comunicacion::administrador * admin_comunicacion, seon::aplicacion::configuracion::gui config_gui, QWidget *parent = Q_NULLPTR);
    virtual ~consola_seon();

    Q_SLOT void mostrar_mensaje_gps(const seon::comunicacion::trama_gps & trama);
    Q_SLOT void mostrar_mensaje_pupitre(const seon::comunicacion::trama_pupitre & trama);
    Q_SLOT void mostrar_mensaje_pulsadores(const seon::comunicacion::trama_pulsadores & trama);
    Q_SLOT void mostrar_mensaje_seon(const seon::comunicacion::trama_seon & trama);

private:
    Ui::consola_seonClass ui;

    void configurar_gui();

    void comenzar_filmacion();

    void comenzar_grabacion();
    void detener_grabacion();

    void color_fondo(QWidget *widget, const std::string &color);

    // atributos
    seon::video::administrador * admin_video;

    seon::aplicacion::configuracion::gui config_gui;

    filmacion_opencv filmacion;

    grabacion_opencv grabacion;

    comunicador comu;

    gui::hud::hud *hud;

    QBasicTimer timer;
    void timerEvent(QTimerEvent * evento);
};
