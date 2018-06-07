#include <consola-seon/include/grabacion_opencv.h>

grabacion_opencv::grabacion_opencv(seon::video::administrador * admin_video, QWidget * padre)
    : admin_video(admin_video),
    convertidor_imagen(admin_video->configuracion.grabacion.resolucion.ancho, admin_video->configuracion.grabacion.resolucion.alto),
    grabador_video(admin_video->configuracion.grabacion.formato, admin_video->configuracion.grabacion.carpeta, admin_video->configuracion.grabacion.fps, admin_video->configuracion.grabacion.resolucion.ancho, admin_video->configuracion.grabacion.resolucion.alto)
{
    this->hilo_grabador.start(QThread::Priority::HighPriority);
    this->hilo_convertidor.start(QThread::Priority::HighPriority);

    this->grabador_video.moveToThread(&this->hilo_grabador);
    this->convertidor_imagen.moveToThread(&this->hilo_convertidor);

    QObject::connect(this, &grabacion_opencv::imagen_lista, &this->convertidor_imagen, &gui::convertidor_grabado::convertir_imagen);
    QObject::connect(&this->convertidor_imagen, &gui::convertidor_grabado::fotograma_listo, &this->grabador_video, &gui::grabador::fotograma_listo);

    QObject::connect(&this->grabador_video, &gui::grabador::empezado, []() { qDebug() << "grabacion iniciada"; });
}

grabacion_opencv::~grabacion_opencv() {

}

void grabacion_opencv::iniciar() {

    QMetaObject::invokeMethod(&this->grabador_video, "iniciar");
}