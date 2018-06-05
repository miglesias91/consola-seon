#include <consola-seon/include/convertidor.h>

namespace gui {

convertidor::convertidor(QObject * parent) : QObject(parent) {}

void convertidor::procesar_todo(bool procesar_todo_fotograma) {
    this->procesar_todo_fotograma = procesar_todo_fotograma;
}

void convertidor::procesar_fotograma(const cv::Mat & frame) {
    if (this->procesar_todo_fotograma) {
        this->procesar(frame);
    }
    else {
        this->encolar(frame);
    }
}


void convertidor::destruidor_mat(void* mat) {
    delete static_cast<cv::Mat*>(mat);
}

void convertidor::encolar(const cv::Mat & frame) {
    if (!m_frame.empty()) {
        qDebug() << "Converter dropped frame!";
    }
    m_frame = frame;
    if (!m_timer.isActive()) m_timer.start(0, this);
}

void convertidor::procesar(const cv::Mat & frame) {

    cv::Mat copia_frame = frame;
    cv::resize(copia_frame, copia_frame, cv::Size(), 0.3, 0.3, cv::INTER_AREA);
    cv::cvtColor(copia_frame, copia_frame, CV_BGR2RGB);

    const QImage image(copia_frame.data, copia_frame.cols, copia_frame.rows, copia_frame.step, QImage::Format_RGB888, &this->destruidor_mat, new cv::Mat(copia_frame));

    Q_ASSERT(image.constBits() == copia_frame.data);

    copia_frame.release();

    emit imagen_lista(image);
}

void convertidor::timerEvent(QTimerEvent * ev) {
    if (ev->timerId() != m_timer.timerId()) return;
    procesar(m_frame);
    m_frame.release();
    m_timer.stop();
}

}