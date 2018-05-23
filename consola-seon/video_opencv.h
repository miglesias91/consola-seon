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

// idea e implementacion sacada de este posteo:
// https://stackoverflow.com/questions/21246766/how-to-efficiently-display-opencv-video-in-qt/21253353#21253353

Q_DECLARE_METATYPE(cv::Mat)

class capturador : public QObject {
    Q_OBJECT


    struct fotograma_opencv {
        cv::Mat fotograma;
        bool eliminado = false;
    };

        QBasicTimer m_timer;
    QScopedPointer<cv::VideoCapture> ptr_capturador;
public:
    capturador(int codec, uint fps_captura, uint fps_grabadora, uint ancho, uint alto, QObject * parent = {})
        : codec(codec), fps_captura(fps_captura), fps_grabadora(fps_grabadora), ancho(ancho), alto(alto), QObject(parent), path_archivo_entrada(""), path_archivo_salida("") {}

    virtual ~capturador() {};

    void entrada(const std::string path_video) {
        this->path_archivo_entrada = path_video;
    }

    void salida(const std::string path_video) {
        this->path_archivo_salida = path_video;
    }

    Q_SIGNAL void started();

    Q_SLOT void start(int cam = {}) {
        if (!this->ptr_capturador) {

            if (this->path_archivo_entrada.empty()) {
                ptr_capturador.reset(new cv::VideoCapture(cam));
            }
            else {
                ptr_capturador.reset(new cv::VideoCapture(this->path_archivo_entrada));
            }
        }
        if (ptr_capturador->isOpened()) {
            m_timer.start(this->fps_captura, this);
            emit started();
        }
    }

    Q_SLOT void stop() { m_timer.stop(); }
    Q_SIGNAL void matReady(const cv::Mat &);

    void fps(uint fps_captura) {
        this->fps_captura = fps_captura;
    };

private:
    void timerEvent(QTimerEvent * ev) {
        if (ev->timerId() != m_timer.timerId()) return;
        cv::Mat frame;
        if (!this->ptr_capturador->read(frame)) { // Blocks until a new frame is ready
            m_timer.stop();
            return;
        }

        emit matReady(frame);
    }

    int codec;
    uint fps_captura, fps_grabadora, ancho, alto;
    std::string path_archivo_entrada, path_archivo_salida;
};

class convertidor : public QObject {
    Q_OBJECT
        QBasicTimer m_timer;
    cv::Mat m_frame;
    bool m_processAll = true;

    static void matDeleter(void* mat) { delete static_cast<cv::Mat*>(mat); }

    void queue(const cv::Mat & frame) {
        if (!m_frame.empty()) {
            qDebug() << "Converter dropped frame!";
        }
        m_frame = frame;
        if (!m_timer.isActive()) m_timer.start(0, this);
    }

    void process(const cv::Mat & frame) {

        cv::Mat copia_frame = frame;
        cv::resize(copia_frame, copia_frame, cv::Size(), 0.3, 0.3, cv::INTER_AREA);
        cv::cvtColor(copia_frame, copia_frame, CV_BGR2RGB);

        const QImage image(copia_frame.data, copia_frame.cols, copia_frame.rows, copia_frame.step, QImage::Format_RGB888 , &matDeleter, new cv::Mat(copia_frame));

        Q_ASSERT(image.constBits() == copia_frame.data);
        
        copia_frame.release();

        emit imageReady(image);
    }

    void timerEvent(QTimerEvent * ev) {
        if (ev->timerId() != m_timer.timerId()) return;
        process(m_frame);
        m_frame.release();
        m_timer.stop();
    }

public:
    explicit convertidor(QObject * parent = nullptr) : QObject(parent) {}

    void setProcessAll(bool all) { m_processAll = all; }

    Q_SIGNAL void imageReady(const QImage &);

    Q_SLOT void processFrame(const cv::Mat & frame) {
        if (m_processAll) {
            process(frame);
        }
        else {
            queue(frame);
        }
    }
};

class visor_imagen : public QWidget {
    Q_OBJECT
        QImage imagen_qt;
    void paintEvent(QPaintEvent *) {

        QPainter p(this);
        p.drawImage(0, 0, imagen_qt);

        imagen_qt = {};
    }
public:
    visor_imagen(QWidget * parent = nullptr) : QWidget(parent) {
        setAttribute(Qt::WA_OpaquePaintEvent);
    }

    Q_SLOT void setImage(const QImage & img) {

        if (!imagen_qt.isNull()) qDebug() << "Viewer dropped frame!";
        imagen_qt = img;
        if (imagen_qt.size() != size()) {
            setFixedSize(imagen_qt.size());
        }
        update();
    }
};

class Thread final : public QThread { public: ~Thread() { quit(); wait(); } };

class video_opencv
{

public:
    video_opencv(seon::video::administrador * admin_video, QWidget * padre = nullptr);
    virtual ~video_opencv();
    
    void iniciar();

    void hijo_de(QWidget * padre);

    void tamanio(uint ancho, uint alto);
    void posicion(uint x, uint y);
    void fps(uint fps_video);

private:

    seon::video::administrador * admin_video;
 
    visor_imagen vista;
    capturador capturador_video;
    convertidor convertidor_fotograma;

    Thread hilo_convertidor, hilo_capturador, hilo_grabador;

    uint fps_video;
};
