#include <consola-seon/include/convertidor.h>

convertidor::convertidor(QObject * parent = nullptr) : QObject(parent) {}

void convertidor::setProcessAll(bool all) {
    m_processAll = all;
}

void convertidor::processFrame(const cv::Mat & frame) {
    if (m_processAll) {
        process(frame);
    }
    else {
        queue(frame);
    }
}


void convertidor::matDeleter(void* mat) {
    delete static_cast<cv::Mat*>(mat)
}

void convertidor::queue(const cv::Mat & frame) {
    if (!m_frame.empty()) {
        qDebug() << "Converter dropped frame!";
    }
    m_frame = frame;
    if (!m_timer.isActive()) m_timer.start(0, this);
}

void convertidor::process(const cv::Mat & frame) {

    cv::Mat copia_frame = frame;
    cv::resize(copia_frame, copia_frame, cv::Size(), 0.3, 0.3, cv::INTER_AREA);
    cv::cvtColor(copia_frame, copia_frame, CV_BGR2RGB);

    const QImage image(copia_frame.data, copia_frame.cols, copia_frame.rows, copia_frame.step, QImage::Format_RGB888, &matDeleter, new cv::Mat(copia_frame));

    Q_ASSERT(image.constBits() == copia_frame.data);

    copia_frame.release();

    emit imageReady(image);
}

void convertidor::timerEvent(QTimerEvent * ev) {
    if (ev->timerId() != m_timer.timerId()) return;
    process(m_frame);
    m_frame.release();
    m_timer.stop();
}