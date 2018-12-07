#include <comunicacion/include/administrador.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

administrador::administrador(const seon::aplicacion::configuracion::comunicacion & configuracion) : configuracion(configuracion) {
    aplicacion::logger::info("INICIO ADMIN COMUNICACION");
}

administrador::~administrador() {

    // libero memoria de los seriales.
    std::for_each(this->comunicaciones.begin(), this->comunicaciones.end(), [](std::pair<std::string, SERIAL*> puerto_serial) { delete puerto_serial.second; });

    aplicacion::logger::info("CIERRE ADMIN COMUNICACION");
}

bool administrador::iniciar() {

    SERIAL * comunicacion_gps = nullptr;
    SERIAL * comunicacion_pulsadores = nullptr;
    SERIAL * comunicacion_pupitre = nullptr;
    SERIAL * comunicacion_seon = nullptr;

    // creo un serial por cada comunicacion.
    try {
        comunicacion_gps = new SERIAL(this->configuracion.gps);
        comunicacion_pulsadores = new SERIAL(this->configuracion.pulsadores);
        comunicacion_pupitre = new SERIAL(this->configuracion.pupitre);
        comunicacion_seon = new SERIAL(this->configuracion.seon);
    }
    catch (std::exception &e) {
        return false;
    }

    this->comunicaciones["gps"] = comunicacion_gps;
    this->comunicaciones["pulsadores"] = comunicacion_pulsadores;
    this->comunicaciones["pupitre"] = comunicacion_pupitre;
    this->comunicaciones["seon"] = comunicacion_seon;

    return true;
}

void administrador::recibir(trama_gps & trama) {

    this->comunicaciones["gps"]->recibir(&trama);
}

void administrador::recibir(trama_pulsadores & trama) {

    this->comunicaciones["pulsadores"]->recibir(&trama);
}

void administrador::recibir(trama_pupitre & trama) {
    this->comunicaciones["pupitre"]->recibir(&trama);
}

void administrador::recibir(trama_seon & trama) {

    this->comunicaciones["seon"]->recibir(&trama);
}

void administrador::esperar_trama(const std::string & nombre_trama, trama * trama_recibida) {

    this->comunicaciones[nombre_trama]->recibir(trama_recibida);
}



}
