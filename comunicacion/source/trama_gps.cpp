#include <comunicacion/include/trama_gps.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

trama_gps::trama_gps() : trama() {}

trama_gps::trama_gps(const std::string & tira_de_datos) {
    this->setear(tira_de_datos);
}

trama_gps::~trama_gps() {

}

bool trama_gps::setear(const std::string & tira_de_datos) {

    this->trama::setear(tira_de_datos);

    return true;
}


}
