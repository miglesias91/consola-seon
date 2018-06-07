#include <consola-seon/include/convertidor_grabado.h>

namespace gui {

convertidor_grabado::convertidor_grabado(uint32_t ancho, uint32_t alto, QObject * parent) : tamanio_video(ancho, alto), QObject(parent) {}

void convertidor_grabado::convertir_imagen(const QImage & imagen_a_convertir) {
    
    QImage imagen_bgr = imagen_a_convertir.rgbSwapped();

    cv::Mat fotograma(imagen_bgr.height(), imagen_bgr.width(), CV_8UC4, imagen_bgr.bits(), imagen_bgr.bytesPerLine());
    cv::resize(fotograma, fotograma, this->tamanio_video, 1.0, 1.0, cv::INTER_AREA);
    cv::cvtColor(fotograma, fotograma, CV_BGRA2RGB);

    emit fotograma_listo(fotograma);
}

}