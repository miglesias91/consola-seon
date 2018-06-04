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

Q_DECLARE_METATYPE(cv::Mat)

namespace gui {

class convertidor : public QObject {
    Q_OBJECT

public:
    explicit convertidor(QObject * parent = nullptr) : QObject(parent) {}

    void procesar_todo(bool procesar_todo_fotograma);

    Q_SIGNAL void imagen_lista(const QImage &);

    Q_SLOT void procesar_fotograma(const cv::Mat & frame);

private:

    QBasicTimer m_timer;
    cv::Mat m_frame;
    bool procesar_todo_fotograma = true;

    static void destruidor_mat(void* mat);

    void encolar(const cv::Mat & frame);

    void procesar(const cv::Mat & frame);

    void timerEvent(QTimerEvent * ev);
};

}