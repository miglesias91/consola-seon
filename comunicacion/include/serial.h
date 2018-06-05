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

    SERIAL();
    SERIAL(const seon::aplicacion::configuracion::trama & configuracion);
    virtual ~SERIAL();

    bool datos_disponibles();

    size_t escribir(const std::string & tira_de_datos);

    size_t leer(std::string & tira_de_datos);
    size_t esperar_y_leer(std::string & tira_de_datos);

    bool enviar(trama * trama_a_enviar);

    bool recibir(trama * trama_recibida);
    bool esperar_y_recibir(trama * trama_recibida);

private:

    seon::aplicacion::configuracion::trama configuracion;

    serial::Serial comunicacion_serial;
};

};

