#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/configuracion.h>

// comunicacion
#include <comunicacion/include/trama.h>

namespace seon::comunicacion {

class trama_pulsadores : public trama {

public:

    trama_pulsadores();
    trama_pulsadores(const std::string & tira_de_datos);
    virtual ~trama_pulsadores();

    virtual bool setear(const std::string & tira_de_datos);

private:

    static seon::aplicacion::configuracion::trama configuracion;
};

};

