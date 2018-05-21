#include <consola-seon/video_opencv.h>

video_opencv::video_opencv(seon::video::administrador * admin_video, QWidget * padre) : admin_video(admin_video), vista(padre) {

    this->vista.lower();
    //this->vista.resize();
    //this->capturador.fps();

    qRegisterMetaType<cv::Mat>();
    this->convertidor.setProcessAll(false);

    this->hilo_capturador.start(QThread::Priority::HighPriority);
    this->hilo_convertidor.start(QThread::Priority::HighPriority);

    this->capturador.moveToThread(&hilo_capturador);
    this->convertidor.moveToThread(&hilo_convertidor);

    QObject::connect(&this->capturador, &Capture::matReady, &this->convertidor, &Converter::processFrame);
    QObject::connect(&this->convertidor, &Converter::imageReady, &this->vista, &ImageViewer::setImage);

    this->vista.show();

    QObject::connect(&this->capturador, &Capture::started, []() { qDebug() << "capture started"; });
    this->capturador.entrada(this->admin_video->entrada());
}

video_opencv::~video_opencv() {

}

void video_opencv::iniciar() {
    QMetaObject::invokeMethod(&this->capturador, "start");
}

void video_opencv::hijo_de(QWidget * padre) {
    this->vista.setParent(padre);
}
