#include <consola-seon/include/grabador.h>

// stl
#include <experimental/filesystem>

namespace gui {

grabador::grabador(const std::string & path_salida, uint fps_grabador, uint ancho, uint alto, int codec, QObject * parent)
    : path_salida(path_salida), codec(codec), fps_grabador(fps_grabador), ancho(ancho), alto(alto), QObject(parent) {

    this->codec = cv::VideoWriter::fourcc('F', 'M', 'P', '4');
}

grabador::~grabador() {};

void grabador::salida(const std::string path_video) {
    this->path_salida = path_video;
}

void grabador::fotograma_listo(const cv::Mat & fotograma) {

    this->ptr_grabador->write(fotograma);

}

void grabador::iniciar() {
    if (!this->ptr_grabador) {

        std::string directorio_ejecutable = std::experimental::filesystem::current_path().u8string();
        ptr_grabador.reset(new cv::VideoWriter(directorio_ejecutable + "\\" + this->path_salida, cv::CAP_FFMPEG, this->codec,  this->fps_grabador, cv::Size(this->ancho, this->alto)));
    }

    if (ptr_grabador->isOpened()) {
        emit empezado();
    }
}

void grabador::fps(uint fps_grabador) {
    this->fps_grabador = fps_grabador;
};

}
