#include <comunicacion/include/trama_seon.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

trama_seon::trama_seon(const std::string & tira_de_datos) {

    aplicacion::logger::info("inicio serial " + this->configuracion.serial.puerto);
}

trama_seon::~trama_seon() {

    aplicacion::logger::info("cierre serial " + this->configuracion.serial.puerto);
}

bool trama_seon::setear(const std::string & tira_de_datos) {

}



}
