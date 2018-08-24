#include <comunicacion/include/trama_gps.h>

// herramientas
#include <utiles/include/FuncionesString.h>
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

bool trama_gps::parsear(const std::string & tira_de_datos) {
    std::vector<std::string> campos = herramientas::utiles::FuncionesString::separar(tira_de_datos, ",");

    if (campos.size() != 13) {
        return false;
    }

    this->id = campos[0];
    herramientas::utiles::Fecha::parsear(campos[9] + campos[1], "%d%m%y%H%M%S", &this->date);
    this->status = campos[2];
    this->latitude.angulo = std::stod(campos[3]);
    this->latitude.cardinalidad = campos[4];
    this->longitude.angulo = std::stod(campos[5]);
    this->longitude.cardinalidad = campos[6];
    this->velocity = std::stod(campos[7]);
    this->angle = std::stod(campos[8]);
    this->magnetic_variation.angulo = std::stod(campos[10]);
    this->magnetic_variation.cardinalidad = campos[11];
    this->checksum = campos[12];

    return true;
}


}
