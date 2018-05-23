#include <consola-seon/video_opencv.h>

video_opencv::video_opencv(seon::video::administrador * admin_video, QWidget * padre)
    : admin_video(admin_video), vista(padre),
    capturador_video(CV_FOURCC('P', 'I', 'M', '1'), admin_video->configuracion.fps, 30, admin_video->configuracion.resolucion.ancho, admin_video->configuracion.resolucion.alto)
    {

    this->vista.lower();

    qRegisterMetaType<cv::Mat>();
    this->convertidor_fotograma.setProcessAll(false);
    //this->grabador_video.setProcessAll(true);

    this->hilo_capturador.start(QThread::Priority::HighPriority);
    this->hilo_convertidor.start(QThread::Priority::HighPriority);
    //this->hilo_grabador.start(QThread::Priority::HighPriority);

    this->capturador_video.moveToThread(&this->hilo_capturador);
    this->convertidor_fotograma.moveToThread(&this->hilo_convertidor);
    //this->grabador_video.moveToThread(&this->hilo_grabador);

    QObject::connect(&this->capturador_video, &capturador::matReady, &this->convertidor_fotograma, &convertidor::processFrame);
    //QObject::connect(&this->capturador_video, &capturador::matReady, &this->grabador_video, &grabador::processFrame);

    QObject::connect(&this->convertidor_fotograma, &convertidor::imageReady, &this->vista, &visor_imagen::setImage);

    this->vista.show();

    QObject::connect(&this->capturador_video, &capturador::started, []() { qDebug() << "capture started"; });
    this->capturador_video.entrada(this->admin_video->entrada());
    this->capturador_video.salida(this->admin_video->salida());
}

video_opencv::~video_opencv() {

}

void video_opencv::iniciar() {
    QMetaObject::invokeMethod(&this->capturador_video, "start");
    //QMetaObject::invokeMethod(&this->grabador_video, "start");
}

void video_opencv::hijo_de(QWidget * padre) {
    this->vista.setParent(padre);
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
