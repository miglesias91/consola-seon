#include <consola-seon/include/capturador.h>

namespace gui {

capturador::capturador(int codec, uint fps_captura, uint fps_grabadora, uint ancho, uint alto, QObject * parent)
    : codec(codec), fps_captura(fps_captura), fps_grabadora(fps_grabadora), ancho(ancho), alto(alto), QObject(parent), path_archivo_entrada(""), path_archivo_salida("") {}

capturador::~capturador() {};

void capturador::entrada(const std::string path_video) {
    this->path_archivo_entrada = path_video;
}

void capturador::salida(const std::string path_video) {
    this->path_archivo_salida = path_video;
}

void capturador::empezar(int cam) {
    if (!this->ptr_capturador) {

        if (this->path_archivo_entrada.empty()) {
            ptr_capturador.reset(new cv::VideoCapture(cam));
        }
        else {
            ptr_capturador.reset(new cv::VideoCapture(this->path_archivo_entrada));
        }
    }
    if (ptr_capturador->isOpened()) {
        m_timer.start(this->fps_captura, this);
        emit empezado();
    }
}

void capturador::detener() {
    m_timer.stop();
}

void capturador::fps(uint fps_captura) {
    this->fps_captura = fps_captura;
};

void capturador::timerEvent(QTimerEvent * ev) {
    if (ev->timerId() != m_timer.timerId()) return;
    cv::Mat frame;
    if (!this->ptr_capturador->read(frame)) { // Blocks until a new frame is ready
        m_timer.stop();
        return;
    }

    emit mat_lista(frame);
}

}