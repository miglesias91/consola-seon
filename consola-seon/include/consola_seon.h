#pragma once

// qt
#include <QtWidgets/QMainWindow>
#include <QtMultimedia/qmediaplayer.h>
#include <QtConcurrent/qtconcurrentrun.h>

#include "ui_consola_seon.h"

// aplicacion
#include <aplicacion/include/configuracion.h>
#include <aplicacion/include/logger.h>

// video
#include <video/include/administrador.h>
#include <video/include/vista.h>

// consola seon
#include <consola-seon/include/filmacion_opencv.h>
#include <consola-seon/include/grabacion_opencv.h>

class consola_seon : public QMainWindow
{
    Q_OBJECT

signals:

    void screenshot_listo(const QImage & screenshot);

public:
    consola_seon(seon::video::administrador * admin_video, seon::aplicacion::configuracion::gui config_gui, QWidget *parent = Q_NULLPTR);
    virtual ~consola_seon();

private:
    Ui::consola_seonClass ui;

    void setear_inicio();

    void comenzar_filmacion();

    void comenzar_grabacion();


    // atributos
    seon::video::administrador * admin_video;

    seon::aplicacion::configuracion::gui config_gui;

    filmacion_opencv filmacion;

    grabacion_opencv grabacion;

    QBasicTimer timer;
    void timerEvent(QTimerEvent * evento);
};
