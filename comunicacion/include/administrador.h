#pragma once

// stl
#include <string>
#include <unordered_map>

// aplicacion
#include <aplicacion/include/configuracion.h>

// comunicacion
#include <comunicacion/include/serial.h>

namespace seon::comunicacion {

class administrador {

public:
    administrador(const seon::aplicacion::configuracion::comunicacion & configuracion);
    virtual ~administrador();

    void iniciar();

    void esperar_trama(const std::string & nombre_trama, trama * trama_recibida);

private:

    seon::aplicacion::configuracion::comunicacion configuracion;

    std::unordered_map<std::string, SERIAL*> comunicaciones;
};

};

