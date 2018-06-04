#include <comunicacion/include/trama_pulsadores.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

trama_pulsadores::trama_pulsadores(const std::string & tira_de_datos) {

    aplicacion::logger::info("inicio serial " + this->configuracion.serial.puerto);
}

trama_pulsadores::~trama_pulsadores() {

    aplicacion::logger::info("cierre serial " + this->configuracion.serial.puerto);
}

bool trama_pulsadores::setear(const std::string & tira_de_datos) {

}


}
