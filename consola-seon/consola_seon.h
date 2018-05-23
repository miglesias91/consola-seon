#pragma once

// qt
#include <QtWidgets/QMainWindow>
#include <QtMultimedia/qmediaplayer.h>

#include "ui_consola_seon.h"

// aplicacion
#include <aplicacion/include/configuracion.h>
#include <aplicacion/include/logger.h>

// video
#include <video/include/administrador.h>
#include <video/include/vista.h>

// consola seon
#include <consola-seon/video_opencv.h>

class consola_seon : public QMainWindow
{
    Q_OBJECT

signals:

    void imagen_procesada();

public:
    consola_seon(seon::video::administrador * admin_video, seon::aplicacion::configuracion::gui config_gui, QWidget *parent = Q_NULLPTR);
    virtual ~consola_seon();

private:

    void setear_inicio();

    void comenzar_filmacion();

    void dibujar_fotograma(QImage imagen);

    Ui::consola_seonClass ui;

    // atributos
    seon::video::administrador * admin_video;

    seon::aplicacion::configuracion::gui config_gui;

    video_opencv video;
};
