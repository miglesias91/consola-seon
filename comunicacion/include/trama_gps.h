#pragma once

// stl
#include <string>

// herramientas
#include <utiles/include/Fecha.h>

// aplicacion
#include <aplicacion/include/configuracion.h>

// comunicacion
#include <comunicacion/include/trama.h>

namespace seon::comunicacion {

class trama_gps : public trama {

    struct coordenada {
        double_t angulo;
        std::string cardinalidad;
    };

public:

    trama_gps();
    trama_gps(const std::string & tira_de_datos);
    virtual ~trama_gps();

    virtual bool setear(const std::string & tira_de_datos);

    std::string id, status, checksum;
    coordenada latitude, longitude, magnetic_variation;
    double_t velocity, angle;
    herramientas::utiles::Fecha date;

private:
    bool parsear(const std::string & tira_de_datos);

    static seon::aplicacion::configuracion::trama configuracion;
};

};

