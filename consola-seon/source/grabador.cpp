#include <consola-seon/include/grabador.h>

namespace gui {

grabador::grabador(const std::string & path_salida, uint fps_grabador, uint ancho, uint alto, int codec, QObject * parent)
    : path_salida(path_salida), codec(codec), fps_grabador(fps_grabador), ancho(ancho), alto(alto), QObject(parent) {}

grabador::~grabador() {};

void grabador::salida(const std::string path_video) {
    this->path_salida = path_video;
}

void grabador::fotograma_listo(const QImage & fotograma) {

    QImage imagen = fotograma;
    cv::Mat bytes_fotograma(imagen.height(), imagen.width(), 2, imagen.bits(), imagen.bytesPerLine());

    this->ptr_grabador->write(bytes_fotograma);

}

void grabador::empezar() {
    if (!this->ptr_grabador) {

        ptr_grabador.reset(new cv::VideoWriter(this->path_salida, this->codec, this->fps_grabador, cv::Size(this->ancho, this->alto)));
    }

    if (ptr_grabador->isOpened()) {
        emit empezado();
    }
}

void grabador::detener() {
    // m_timer.stop();
}

void grabador::fps(uint fps_grabador) {
    this->fps_grabador = fps_grabador;
};

}