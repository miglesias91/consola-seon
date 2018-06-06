#pragma once

// qt
#include <QtWidgets>

// opencv
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

// idea e implementacion sacada de este posteo:
// https://stackoverflow.com/questions/21246766/how-to-efficiently-display-opencv-video-in-qt/21253353#21253353

namespace gui {

class grabador : public QObject {
    Q_OBJECT

public:
    grabador(const std::string & path_salida, uint fps_grabadora, uint ancho, uint alto, int codec = cv::VideoWriter::fourcc('P', 'I', 'M', '1'), QObject * parent = {});

    virtual ~grabador();

    void salida(const std::string path_video);

    Q_SIGNAL void empezado();

    Q_SLOT void empezar();
    Q_SLOT void detener();
    Q_SLOT void fotograma_listo(const QImage & fotograma);

    void fps(uint fps_grabacion);

private:

    QScopedPointer<cv::VideoWriter> ptr_grabador;

    int codec;
    uint fps_grabador, ancho, alto;
    std::string path_salida;
};

}