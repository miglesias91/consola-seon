#include <comunicacion/include/serial.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

SERIAL::SERIAL(const seon::aplicacion::configuracion::trama & configuracion)
    : configuracion(configuracion), comunicacion_serial(configuracion.serial.puerto, configuracion.serial.baudrate) {

    aplicacion::logger::info("inicio serial " + this->configuracion.serial.puerto);
}

SERIAL::~SERIAL() {

    aplicacion::logger::info("cierre serial " + this->configuracion.serial.puerto);
}

size_t SERIAL::leer(std::string & tira_de_datos) {

    return this->comunicacion_serial.read(tira_de_datos, this->configuracion.largo);
}

size_t SERIAL::esperar_y_leer(std::string & tira_de_datos) {

    if (this->comunicacion_serial.waitReadable()) {
        return this->comunicacion_serial.read(tira_de_datos);
    }

    return 0;
}

bool SERIAL::recibir(trama * trama) {
    return false;
}

bool SERIAL::esperar_y_recibir(trama * trama) {
    return false;
}




}
