#include <comunicacion/include/trama_pulsadores.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

trama_pulsadores::trama_pulsadores() : trama() {}

trama_pulsadores::trama_pulsadores(const std::string & tira_de_datos) {
    this->setear(tira_de_datos);
}

trama_pulsadores::~trama_pulsadores() {

}

bool trama_pulsadores::setear(const std::string & tira_de_datos) {

    this->trama::setear(tira_de_datos);
    return true;
}


}
