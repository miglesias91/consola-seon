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
    grabador(const std::string & formato, const std::string & carpeta, uint fps_grabadora, uint ancho, uint alto, int codec = cv::VideoWriter::fourcc('F', 'M', 'P', '4'), QObject * parent = {});

    virtual ~grabador();

    Q_SIGNAL void empezado();

    Q_SLOT void iniciar();
    Q_SLOT void fotograma_listo(const cv::Mat & fotograma);

    void fps(uint fps_grabacion);

private:

    QScopedPointer<cv::VideoWriter> ptr_grabador;

    int codec;
    uint fps_grabador, ancho, alto;
    std::string formato, carpeta;
};

}