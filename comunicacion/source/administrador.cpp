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

void administrador::iniciar() {

    // creo un serial por cada comunicacion.
    SERIAL * comunicacion_gps = new SERIAL(this->configuracion.gps);
    SERIAL * comunicacion_pulsadores = new SERIAL(this->configuracion.pulsadores);
    SERIAL * comunicacion_pupitre = new SERIAL(this->configuracion.pupitre);
    SERIAL * comunicacion_seon = new SERIAL(this->configuracion.seon);

    this->comunicaciones["gps"] = comunicacion_gps;
    this->comunicaciones["pulsadores"] = comunicacion_pulsadores;
    this->comunicaciones["pupitre"] = comunicacion_pupitre;
    this->comunicaciones["seon"] = comunicacion_seon;
}

void administrador::esperar_trama(const std::string & nombre_trama, trama * trama_recibida) {

    this->comunicaciones[nombre_trama]->esperar_y_recibir(trama_recibida);

}



}
