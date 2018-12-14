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
        uint16_t grados = 0;
        double_t minutos = 0.000f;
        std::string cardinalidad = "";
    };

public:

    trama_gps();
    trama_gps(const std::string & tira_de_datos);
    virtual ~trama_gps();

    std::string id, estado, checksum;
    coordenada latitud, longitud, variacion_magnetica;
    double_t velocidad, angulo;
    herramientas::utiles::Fecha fecha;

protected:
    virtual bool parsear(const std::string & tira_de_datos) override;

private:
    static seon::aplicacion::configuracion::trama configuracion;
};

};

