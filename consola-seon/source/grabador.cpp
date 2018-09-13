#include <consola-seon/include/grabador.h>

// stl
#include <experimental/filesystem>

// herramientas
#include <utiles/include/Fecha.h>

namespace gui {

grabador::grabador(const std::string & formato, const std::string & carpeta, uint fps_grabador, uint ancho, uint alto, int codec, QObject * parent)
    : formato(formato), carpeta(carpeta), codec(codec), fps_grabador(fps_grabador), ancho(ancho), alto(alto), QObject(parent) {}

grabador::~grabador() {};

void grabador::fotograma_listo(const cv::Mat & fotograma) {

    this->ptr_grabador->write(fotograma);
}

void grabador::iniciar() {
    if (!this->ptr_grabador) {

        std::string directorio_ejecutable = std::experimental::filesystem::current_path().u8string() + "\\" + this->carpeta;

        std::string id_ejercicio = herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS();

        ptr_grabador.reset(new cv::VideoWriter(directorio_ejecutable + "\\" + id_ejercicio + "." + this->formato, cv::CAP_FFMPEG, this->codec,  this->fps_grabador, cv::Size(this->ancho, this->alto)));
    }

    if (ptr_grabador->isOpened()) {
        emit empezado();
    }
}

void grabador::reiniciar() {

    std::string directorio_ejecutable = std::experimental::filesystem::current_path().u8string() + "\\" + this->carpeta;

    std::string id_ejercicio = herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS();

    this->ptr_grabador.reset(new cv::VideoWriter(directorio_ejecutable + "\\" + id_ejercicio + "." + this->formato, cv::CAP_FFMPEG, this->codec, this->fps_grabador, cv::Size(this->ancho, this->alto)));
}

void grabador::fps(uint fps_grabador) {
    this->fps_grabador = fps_grabador;
};

}
