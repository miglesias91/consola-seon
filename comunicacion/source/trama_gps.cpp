#include <comunicacion/include/trama_gps.h>

// herramientas
#include <utiles/include/FuncionesString.h>
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

trama_gps::trama_gps() : trama(),
id(""), estado(""), checksum(""),
velocidad(0), angulo(0) {}

trama_gps::trama_gps(const std::string & tira_de_datos) : trama(),
id(""), estado(""), checksum(""),
velocidad(0), angulo(0) {
    this->setear(tira_de_datos);
}

trama_gps::~trama_gps() {

}

bool trama_gps::parsear(const std::string & tira_de_datos) {
    std::vector<std::string> campos = herramientas::utiles::FuncionesString::separar(tira_de_datos, ",");

    if (campos.size() != 12) {
        return false;
    }

    this->id = campos[0];

    std::string dia(campos[9].begin(), campos[9].begin() + 2);
    std::string mes(campos[9].begin() + 2, campos[9].begin() + 4);
    std::string anio(campos[9].begin() + 4, campos[9].begin() + 6);
    herramientas::utiles::Fecha::parsear(dia + "-" + mes + "-" + anio, "%d-%m-%y", &this->fecha);

    herramientas::utiles::Fecha horasminutossegundos;
    std::string horas(campos[1].begin(), campos[1].begin() + 2);
    std::string minutos(campos[1].begin() + 2, campos[1].begin() + 4);
    std::string segundos(campos[1].begin() + 4, campos[1].begin() + 6);
    herramientas::utiles::Fecha::parsear(horas + "-" + minutos + "-" + segundos, "%H-%M-%S", &horasminutossegundos);

    this->fecha.setHoras(horasminutossegundos.getHoras());
    this->fecha.setMinutos(horasminutossegundos.getMinutos());
    this->fecha.setSegundos(horasminutossegundos.getSegundos());

    this->estado = campos[2];

    std::string latitud_grados(campos[3].begin(), campos[3].begin() + 2);
    std::string latitud_minutos(campos[3].begin() + 2, campos[3].end());
    this->latitud.grados = std::stoi(latitud_grados);
    this->latitud.minutos = std::stod(latitud_minutos);
    this->latitud.cardinalidad = campos[4];

    std::string longitud_grados(campos[5].begin(), campos[5].begin() + 3);
    std::string longitud_minutos(campos[5].begin() + 3, campos[5].end());
    this->longitud.grados = std::stod(longitud_grados);
    this->longitud.minutos = std::stod(longitud_minutos);
    this->longitud.cardinalidad = campos[6];
    this->velocidad = std::stod(campos[7]);
    this->angulo = std::stod(campos[8]);

    return true;
}


}
