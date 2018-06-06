#include <consola-seon/include/convertidor_captura.h>

namespace gui {

convertidor_captura::convertidor_captura(uint32_t ancho, uint32_t alto, QObject * parent) : tamanio_video(ancho, alto), QObject(parent) {}

void convertidor_captura::procesar_todo(bool procesar_todo_fotograma) {
    this->procesar_todo_fotograma = procesar_todo_fotograma;
}

void convertidor_captura::convertir_fotograma(const cv::Mat & frame) {
    if (this->procesar_todo_fotograma) {
        this->convertir(frame);
    }
    else {
        this->encolar(frame);
    }
}


void convertidor_captura::destruidor_mat(void* mat) {
    delete static_cast<cv::Mat*>(mat);
}

void convertidor_captura::encolar(const cv::Mat & frame) {
    if (!m_frame.empty()) {
        qDebug() << "Converter dropped frame!";
    }
    m_frame = frame;
    if (!m_timer.isActive()) m_timer.start(0, this);
}

void convertidor_captura::convertir(const cv::Mat & frame) {

    cv::Mat copia_frame = frame;
    cv::resize(copia_frame, copia_frame, this->tamanio_video, 1.0, 1.0, cv::INTER_LINEAR);
    cv::cvtColor(copia_frame, copia_frame, CV_BGR2RGB);

    const QImage image(copia_frame.data, copia_frame.cols, copia_frame.rows, copia_frame.step, QImage::Format_RGB888, &this->destruidor_mat, new cv::Mat(copia_frame));

    Q_ASSERT(image.constBits() == copia_frame.data);

    copia_frame.release();

    emit imagen_lista(image);
}

void convertidor_captura::timerEvent(QTimerEvent * ev) {
    
    if (ev->timerId() != m_timer.timerId()) return;

    convertir(m_frame);
    m_frame.release();
    m_timer.stop();
}

}