#pragma once

// stl
#include <thread>
#include <condition_variable>
#include <mutex>

// qt
#include <QtWidgets>
#include <qabstractvideosurface.h>

// opencv
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

// video
#include <video/include/administrador.h>

// consola-seon
#include <consola-seon/include/capturador.h>
#include <consola-seon/include/convertidor_captura.h>
#include <consola-seon/include/visor_filmacion.h>

// idea e implementacion sacada de este posteo:
// https://stackoverflow.com/questions/21246766/how-to-efficiently-display-opencv-video-in-qt/21253353#21253353

class thread_filmacion final : public QThread { public: ~thread_filmacion() { quit(); wait(); } };

class filmacion_opencv
{

public:
    filmacion_opencv(seon::video::administrador * admin_video, QWidget * padre = nullptr);
    virtual ~filmacion_opencv();
    
    void iniciar();

    void hijo_de(QWidget * padre);

    void tamanio(uint ancho, uint alto);
    void posicion(uint x, uint y);
    void fps(uint fps_video);
    void visible(const bool &valor);

private:

    seon::video::administrador * admin_video;
 
    gui::visor_filmacion vista;
    gui::capturador capturador_video;
    gui::convertidor_captura convertidor_fotograma;

    thread_filmacion hilo_convertidor, hilo_capturador;

    uint fps_video;
};
