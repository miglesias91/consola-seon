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

class capturador : public QObject {
    Q_OBJECT

public:
    capturador(const std::string path_entrada, uint fps_captura, QObject * parent = {});

    virtual ~capturador();

    void entrada(const std::string path_entrada);

    Q_SIGNAL void empezado();
    Q_SIGNAL void mat_lista(const cv::Mat &);

    Q_SLOT void iniciar(int cam = {});
    Q_SLOT void pausar();
    Q_SLOT void detener();

    void fps(uint fps_captura);

private:

    struct fotograma_opencv {
        cv::Mat fotograma;
        bool eliminado = false;
    };

    QBasicTimer m_timer;
    QScopedPointer<cv::VideoCapture> ptr_capturador;

    void timerEvent(QTimerEvent * ev);

    uint fps_captura;
    std::string path_entrada;
};

}