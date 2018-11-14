#include <consola-seon/include/capturador.h>

// stl
#include <experimental/filesystem>

namespace gui {

capturador::capturador(const std::string path_entrada, uint fps_captura, QObject * parent)
    : path_entrada(path_entrada), fps_captura(fps_captura), QObject(parent) {}

capturador::~capturador() {};

void capturador::entrada(const std::string path_entrada) {
    this->path_entrada = path_entrada;
}

void capturador::iniciar(int cam) {
    if (!this->ptr_capturador) {

        if (this->path_entrada.empty()) {
            ptr_capturador.reset(new cv::VideoCapture(cam));
        }
        else {
            std::string directorio_ejecutable = std::experimental::filesystem::current_path().u8string();
            ptr_capturador.reset(new cv::VideoCapture(directorio_ejecutable + "\\" + this->path_entrada, cv::CAP_FFMPEG));
        }
    }
    if (ptr_capturador->isOpened()) {
        m_timer.start((1000 / (this->fps_captura + 10)), this);
        emit empezado();
    }
}

void capturador::pausar() {
    m_timer.stop();
}

void capturador::detener() {
    if (!this->ptr_capturador) { return; }
    m_timer.stop();
    ptr_capturador->set(CV_CAP_PROP_POS_FRAMES, 0);
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