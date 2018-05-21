#pragma once

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

class Capture : public QObject {
    Q_OBJECT
        QBasicTimer m_timer;
    QScopedPointer<cv::VideoCapture> m_videoCapture;
public:
    Capture(uint fps = 30, QObject * parent = {}) : fps_captura(fps), QObject(parent), path_archivo("") {}

    void entrada(const std::string path_video) {
        this->path_archivo = path_video;
    }

    Q_SIGNAL void started();

    Q_SLOT void start(int cam = {}) {
        if (!m_videoCapture) {

            if (this->path_archivo.empty()) {
                m_videoCapture.reset(new cv::VideoCapture(cam));
            }
            else {
                m_videoCapture.reset(new cv::VideoCapture(this->path_archivo));
            }
        }
        if (m_videoCapture->isOpened()) {
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
        if (!m_videoCapture->read(frame)) { // Blocks until a new frame is ready
            m_timer.stop();
            return;
        }
        emit matReady(frame);
    }

    uint fps_captura;
    std::string path_archivo;
};

class Converter : public QObject {
    Q_OBJECT
        QBasicTimer m_timer;
    cv::Mat m_frame;
    bool m_processAll = true;

    static void matDeleter(void* mat) { delete static_cast<cv::Mat*>(mat); }

    void queue(const cv::Mat & frame) {
        if (!m_frame.empty()) qDebug() << "Converter dropped frame!";
        m_frame = frame;
        if (!m_timer.isActive()) m_timer.start(0, this);
    }

    void process(cv::Mat frame) {
        cv::resize(frame, frame, cv::Size(), 0.3, 0.3, cv::INTER_AREA);
        cv::cvtColor(frame, frame, CV_BGR2RGB);

        const QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888, &matDeleter, new cv::Mat(frame));

        Q_ASSERT(image.constBits() == frame.data);
        
        emit imageReady(image);
    }

    void timerEvent(QTimerEvent * ev) {
        if (ev->timerId() != m_timer.timerId()) return;
        process(m_frame);
        m_frame.release();
        m_timer.stop();
    }

public:
    explicit Converter(QObject * parent = nullptr) : QObject(parent) {}

    void setProcessAll(bool all) { m_processAll = all; }

    Q_SIGNAL void imageReady(const QImage &);

    Q_SLOT void processFrame(const cv::Mat & frame) {
        if (m_processAll) process(frame); else queue(frame);
    }
};

class ImageViewer : public QWidget {
    Q_OBJECT
        QImage m_img;
    void paintEvent(QPaintEvent *) {

        QPainter p(this);
        p.drawImage(0, 0, m_img);

        m_img = {};
    }
public:
    ImageViewer(QWidget * parent = nullptr) : QWidget(parent) {
        setAttribute(Qt::WA_OpaquePaintEvent);
    }

    Q_SLOT void setImage(const QImage & img) {

        if (!m_img.isNull()) qDebug() << "Viewer dropped frame!";
        m_img = img;
        if (m_img.size() != size()) {
            setFixedSize(m_img.size());
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
 
    ImageViewer vista;
    Capture capturador;
    Converter convertidor;
    Thread hilo_convertidor, hilo_capturador;

    uint fps_video;
};
