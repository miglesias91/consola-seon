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

class convertidor_grabado : public QObject {
    Q_OBJECT

public:
    explicit convertidor_grabado(uint32_t ancho = 0, uint32_t alto = 0, QObject * parent = nullptr);

    Q_SIGNAL void fotograma_listo(const cv::Mat & fotograma);
    
    Q_SLOT void convertir_imagen(const QImage & imagen_a_convertir);

private:

    cv::Size tamanio_video;
};

}