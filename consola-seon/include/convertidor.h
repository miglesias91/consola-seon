#pragma once
// qt
#include <QtWidgets>

// idea e implementacion sacada de este posteo:
// https://stackoverflow.com/questions/21246766/how-to-efficiently-display-opencv-video-in-qt/21253353#21253353

Q_DECLARE_METATYPE(cv::Mat)

namespace gui {

class convertidor : public QObject {
    Q_OBJECT

public:
    explicit convertidor(QObject * parent = nullptr) : QObject(parent) {}

    void setProcessAll(bool all);

    Q_SIGNAL void imageReady(const QImage &);

    Q_SLOT void processFrame(const cv::Mat & frame);

private:

    QBasicTimer m_timer;
    cv::Mat m_frame;
    bool m_processAll = true;

    static void matDeleter(void* mat);

    void queue(const cv::Mat & frame);

    void process(const cv::Mat & frame);

    void timerEvent(QTimerEvent * ev);
};

}