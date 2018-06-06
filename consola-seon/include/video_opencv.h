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
#include <consola-seon/include/convertidor.h>
#include <consola-seon/include/visor_imagen.h>

// idea e implementacion sacada de este posteo:
// https://stackoverflow.com/questions/21246766/how-to-efficiently-display-opencv-video-in-qt/21253353#21253353

class Thread final : public QThread { public: ~Thread() { quit(); wait(); } };

class video_opencv
{

public:
    video_opencv(seon::video::administrador * admin_video, QWidget * padre = nullptr);
    virtual ~video_opencv();
    
    void iniciar();

    void hijo_de(QWidget * padre);
    void layout(QLayout * layout);

    void tamanio(uint ancho, uint alto);
    void posicion(uint x, uint y);
    void fps(uint fps_video);

private:

    seon::video::administrador * admin_video;
 
    gui::visor_imagen vista;
    gui::capturador capturador_video;
    gui::convertidor convertidor_fotograma;

    Thread hilo_convertidor, hilo_capturador, hilo_grabador;

    uint fps_video;
};
