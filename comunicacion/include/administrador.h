#pragma once

// stl
#include <string>
#include <unordered_map>

// aplicacion
#include <aplicacion/include/configuracion.h>

// comunicacion
#include <comunicacion/include/serial.h>
#include <comunicacion/include/trama_gps.h>
#include <comunicacion/include/trama_pulsadores.h>
#include <comunicacion/include/trama_pupitre.h>
#include <comunicacion/include/trama_seon.h>

namespace seon::comunicacion {

class administrador {

public:
    administrador(const seon::aplicacion::configuracion::comunicacion & configuracion);
    virtual ~administrador();

    bool iniciar();

    void recibir(trama_gps & trama);
    void recibir(trama_pulsadores & trama);
    void recibir(trama_pupitre & trama);
    void recibir(trama_seon & trama);

    void esperar_trama(const std::string & nombre_trama, trama * trama_recibida);

    seon::aplicacion::configuracion::comunicacion configuracion;

private:

    std::unordered_map<std::string, SERIAL*> comunicaciones;
};

};

