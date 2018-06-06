#include <consola-seon/include/convertidor_grabado.h>

namespace gui {

convertidor_grabado::convertidor_grabado(uint32_t ancho, uint32_t alto, QObject * parent) : tamanio_video(ancho, alto), QObject(parent) {}

//void convertidor_grabado::procesar_todo(bool procesar_todo_fotograma) {
//    this->procesar_todo_fotograma = procesar_todo_fotograma;
//}

void convertidor_grabado::convertir_imagen(const QImage & imagen_a_convertir) {
    
    QImage imagen_bgr = imagen_a_convertir.rgbSwapped();

    cv::Mat fotograma(imagen_bgr.height(), imagen_bgr.width(), CV_8UC4, imagen_bgr.bits(), imagen_bgr.bytesPerLine());
    cv::resize(fotograma, fotograma, this->tamanio_video, 1.0, 1.0, cv::INTER_LINEAR);

    emit fotograma_listo(fotograma);
}

//void convertidor_grabado::destruidor_mat(void* mat) {
//    delete static_cast<cv::Mat*>(mat);
//}

//void convertidor_grabado::encolar(const cv::Mat & frame) {
//    if (!m_frame.empty()) {
//        qDebug() << "Converter dropped frame!";
//    }
//    m_frame = frame;
//    if (!m_timer.isActive()) m_timer.start(0, this);
//}
//
//void convertidor_grabado::procesar(const cv::Mat & frame) {
//
//    cv::Mat copia_frame = frame;
//    cv::resize(copia_frame, copia_frame, this->tamanio_video, 1.0, 1.0, cv::INTER_LINEAR);
//    cv::cvtColor(copia_frame, copia_frame, CV_BGR2RGB);
//
//    const QImage image(copia_frame.data, copia_frame.cols, copia_frame.rows, copia_frame.step, QImage::Format_RGB888, &this->destruidor_mat, new cv::Mat(copia_frame));
//
//    Q_ASSERT(image.constBits() == copia_frame.data);
//
//    copia_frame.release();
//
//    emit imagen_lista(image);
//}
//
//void convertidor_grabado::timerEvent(QTimerEvent * ev) {
//    if (ev->timerId() != m_timer.timerId()) return;
//    procesar(m_frame);
//    m_frame.release();
//    m_timer.stop();
//}

}