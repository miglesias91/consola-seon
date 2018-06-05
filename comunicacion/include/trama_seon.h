#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/configuracion.h>

// comunicacion
#include <comunicacion/include/trama.h>

namespace seon::comunicacion {

class trama_seon : public trama {

public:

    trama_seon();
    trama_seon(const std::string & tira_de_datos);
    virtual ~trama_seon();

    virtual bool setear(const std::string & tira_de_datos);

private:

    static seon::aplicacion::configuracion::trama configuracion;
};

};

