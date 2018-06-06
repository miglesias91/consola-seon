#include <consola-seon/include/video_opencv.h>

video_opencv::video_opencv(seon::video::administrador * admin_video, QWidget * padre)
    : admin_video(admin_video), vista(padre),
    convertidor_fotograma(admin_video->configuracion.resolucion.ancho, admin_video->configuracion.resolucion.alto),
    capturador_video(admin_video->configuracion.fps, admin_video->configuracion.resolucion.ancho, admin_video->configuracion.resolucion.alto)
    {

    this->vista.lower();

    qRegisterMetaType<cv::Mat>();
    this->convertidor_fotograma.procesar_todo(false);
    //this->grabador_video.setProcessAll(true);

    this->hilo_capturador.start(QThread::Priority::HighPriority);
    this->hilo_convertidor.start(QThread::Priority::HighPriority);
    //this->hilo_grabador.start(QThread::Priority::HighPriority);

    this->capturador_video.moveToThread(&this->hilo_capturador);
    this->convertidor_fotograma.moveToThread(&this->hilo_convertidor);
    //this->grabador_video.moveToThread(&this->hilo_grabador);

    QObject::connect(&this->capturador_video, &gui::capturador::mat_lista, &this->convertidor_fotograma, &gui::convertidor::procesar_fotograma);
    //QObject::connect(&this->capturador_video, &capturador::matReady, &this->grabador_video, &grabador::processFrame);

    QObject::connect(&this->convertidor_fotograma, &gui::convertidor::imagen_lista, &this->vista, &gui::visor_imagen::setear_imagen);

    this->vista.show();

    QObject::connect(&this->capturador_video, &gui::capturador::empezado, []() { qDebug() << "capture started"; });
    this->capturador_video.entrada(this->admin_video->entrada());
}

video_opencv::~video_opencv() {

}

void video_opencv::iniciar() {

    QMetaObject::invokeMethod(&this->capturador_video, "empezar");
    //QMetaObject::invokeMethod(&this->grabador_video, "start");
}

void video_opencv::hijo_de(QWidget * padre) {

    this->vista.setParent(padre);
}

void video_opencv::layout(QLayout * layout) {

    layout->addWidget(&this->vista);
}

void video_opencv::tamanio(uint ancho, uint alto) {

    this->vista.resize(ancho, alto);
}

void video_opencv::posicion(uint x, uint y) {

    this->vista.move(x, y);
}

void video_opencv::fps(uint fps_video) {

    this->capturador_video.fps(fps_video);
    this->fps_video = fps_video;
}
