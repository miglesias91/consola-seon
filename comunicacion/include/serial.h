#pragma once

// stl
#include <string>

// serial
#include <serial/serial.h>

// aplicacion
#include <aplicacion/include/configuracion.h>

// comunicacion
#include <comunicacion/include/trama.h>

namespace seon::comunicacion {

class SERIAL {

public:

    SERIAL(const seon::aplicacion::configuracion::trama & configuracion);
    virtual ~SERIAL();

    size_t leer(std::string & tira_de_datos);
    size_t esperar_y_leer(std::string & tira_de_datos);

    bool recibir(trama * trama);
    bool esperar_y_recibir(trama * trama);

private:

    seon::aplicacion::configuracion::trama configuracion;

    serial::Serial comunicacion_serial;
};

};

