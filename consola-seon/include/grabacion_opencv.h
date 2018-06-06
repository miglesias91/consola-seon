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
#include <consola-seon/include/grabador.h>
#include <consola-seon/include/convertidor_grabado.h>

// idea e implementacion sacada de este posteo:
// https://stackoverflow.com/questions/21246766/how-to-efficiently-display-opencv-video-in-qt/21253353#21253353

class thread_grabacion final : public QThread { public: ~thread_grabacion() { quit(); wait(); } };

class grabacion_opencv : public QObject {
    Q_OBJECT

public:
    grabacion_opencv(seon::video::administrador * admin_video, QWidget * padre = nullptr);
    virtual ~grabacion_opencv();
    
    void iniciar();

    Q_SIGNAL void imagen_lista(const QImage & imagen);

private:

    seon::video::administrador * admin_video;
 
    gui::grabador grabador_video;
    gui::convertidor_grabado convertidor_imagen;

    thread_grabacion hilo_convertidor, hilo_grabador;
};
