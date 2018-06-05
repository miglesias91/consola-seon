#include <comunicacion/include/trama_pupitre.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

trama_pupitre::trama_pupitre() : trama() {}

trama_pupitre::trama_pupitre(const std::string & tira_de_datos) {
    this->setear(tira_de_datos);
}

trama_pupitre::~trama_pupitre() {

}

bool trama_pupitre::setear(const std::string & tira_de_datos) {

    this->trama::setear(tira_de_datos);
    return true;
}


}
