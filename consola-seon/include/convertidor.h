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

class convertidor : public QObject {
    Q_OBJECT

public:
    explicit convertidor(uint32_t ancho = 0, uint32_t alto = 0, QObject * parent = nullptr);

    void procesar_todo(bool procesar_todo_fotograma);

    Q_SIGNAL void imagen_lista(const QImage &);

    Q_SLOT void procesar_fotograma(const cv::Mat & frame);

private:

    QBasicTimer m_timer;
    cv::Mat m_frame;
    cv::Size tamanio_video;
    bool procesar_todo_fotograma = true;

    static void destruidor_mat(void* mat);

    void encolar(const cv::Mat & frame);

    void procesar(const cv::Mat & frame);

    void timerEvent(QTimerEvent * ev);
};

}