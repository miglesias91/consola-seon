#include <consola-seon/include/filmacion_opencv.h>

filmacion_opencv::filmacion_opencv(seon::video::administrador * admin_video, QWidget * padre)
    : admin_video(admin_video), vista(padre),
    convertidor_fotograma(admin_video->configuracion.filmacion.resolucion.ancho, admin_video->configuracion.filmacion.resolucion.alto),
    capturador_video(admin_video->configuracion.filmacion.path, admin_video->configuracion.filmacion.fps)
{
    this->vista.lower();

    qRegisterMetaType<cv::Mat>();
    this->convertidor_fotograma.procesar_todo(false);

    this->hilo_capturador.start(QThread::Priority::HighPriority);
    this->hilo_convertidor.start(QThread::Priority::HighPriority);

    this->capturador_video.moveToThread(&this->hilo_capturador);
    this->convertidor_fotograma.moveToThread(&this->hilo_convertidor);

    QObject::connect(&this->capturador_video, &gui::capturador::mat_lista, &this->convertidor_fotograma, &gui::convertidor_captura::convertir_fotograma);
    QObject::connect(&this->convertidor_fotograma, &gui::convertidor_captura::imagen_lista, &this->vista, &gui::visor_filmacion::setear_imagen);

    this->vista.show();

    QObject::connect(&this->capturador_video, &gui::capturador::empezado, []() { qDebug() << "captura iniciada"; });
}

filmacion_opencv::~filmacion_opencv() {

}

void filmacion_opencv::iniciar() {

    QMetaObject::invokeMethod(&this->capturador_video, "iniciar");
}

void filmacion_opencv::hijo_de(QWidget * padre) {

    this->vista.setParent(padre);
}

void filmacion_opencv::tamanio(uint ancho, uint alto) {

    this->vista.resize(ancho, alto);
}

void filmacion_opencv::posicion(uint x, uint y) {

    this->vista.move(x, y);
}

void filmacion_opencv::fps(uint fps_video) {

    this->capturador_video.fps(fps_video);
    this->fps_video = fps_video;
}

void filmacion_opencv::visible(const bool &valor) {
    this->vista.setVisible(valor);
}