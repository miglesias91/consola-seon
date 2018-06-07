#include <consola-seon/include/comunicador.h>

// stl
#include <experimental/filesystem>

comunicador::comunicador(seon::comunicacion::administrador * admin_comunicacion, QObject * parent) : hay_comunicacion(false), admin_comunicacion(admin_comunicacion), QObject(parent)
{
    qRegisterMetaType<seon::comunicacion::trama_gps>();
    qRegisterMetaType<seon::comunicacion::trama_pulsadores>();
    qRegisterMetaType<seon::comunicacion::trama_pupitre>();
    qRegisterMetaType<seon::comunicacion::trama_seon>();
}

comunicador::~comunicador() {}

void comunicador::iniciar_comunicaciones() {

    this->admin_comunicacion->iniciar();

    this->hay_comunicacion = true;

    // inicio comunicacion con gps
    QtConcurrent::run(this, &comunicador::iniciar_comunicacion_gps);

    // inicio comunicacion con pulsadores
    QtConcurrent::run(this, &comunicador::iniciar_comunicacion_pulsadores);

    // inicio comunicacion con pupitre
    QtConcurrent::run(this, &comunicador::iniciar_comunicacion_pupitre);

    // inicio comunicacion con seon
    QtConcurrent::run(this, &comunicador::iniciar_comunicacion_seon);
}

void comunicador::cortar() {

    this->hay_comunicacion = false;
}

void comunicador::iniciar_comunicacion_gps() {

    while (this->hay_comunicacion) {
        seon::comunicacion::trama_gps trama;
        this->admin_comunicacion->recibir(trama);

        if (false == trama.tira_de_datos.empty()) {
            emit nuevo_mensaje_gps(trama);
        }

        QThread::msleep(200);
    }
}

void comunicador::iniciar_comunicacion_pulsadores() {

    while (this->hay_comunicacion) {
        seon::comunicacion::trama_pulsadores trama;
        this->admin_comunicacion->recibir(trama);

        if (false == trama.tira_de_datos.empty()) {
            emit nuevo_mensaje_pulsadores(trama);
        }

        QThread::msleep(200);
    }
}

void comunicador::iniciar_comunicacion_pupitre() {

    while (this->hay_comunicacion) {
        seon::comunicacion::trama_pupitre trama;
        this->admin_comunicacion->recibir(trama);

        if (false == trama.tira_de_datos.empty()) {
            emit nuevo_mensaje_pupitre(trama);
        }

        QThread::msleep(200);
    }
}

void comunicador::iniciar_comunicacion_seon() {

    while (this->hay_comunicacion) {
        seon::comunicacion::trama_seon trama;
        this->admin_comunicacion->recibir(trama);

        if (false == trama.tira_de_datos.empty()) {
            emit nuevo_mensaje_seon(trama);
        }

        QThread::msleep(200);
    }
}
