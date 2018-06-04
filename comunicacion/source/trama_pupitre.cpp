#include <comunicacion/include/trama_pupitre.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

trama_pupitre::trama_pupitre(const std::string & tira_de_datos) {

    aplicacion::logger::info("inicio serial " + this->configuracion.serial.puerto);
}

trama_pupitre::~trama_pupitre() {

    aplicacion::logger::info("cierre serial " + this->configuracion.serial.puerto);
}

bool trama_pupitre::setear(const std::string & tira_de_datos) {

}


}
