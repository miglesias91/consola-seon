#include <comunicacion/include/trama_seon.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

trama_seon::trama_seon() : trama() {}

trama_seon::trama_seon(const std::string & tira_de_datos) {
    this->setear(tira_de_datos);
}

trama_seon::~trama_seon() {

}

bool trama_seon::setear(const std::string & tira_de_datos) {

    this->trama::setear(tira_de_datos);
    return true;
}



}
