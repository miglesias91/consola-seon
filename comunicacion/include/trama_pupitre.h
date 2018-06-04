#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace seon::comunicacion {

class trama_pupitre {

public:

    trama_pupitre(const seon::aplicacion::configuracion::trama & configuracion);
    virtual ~trama_pupitre();

    bool setear(const std::string & tira_de_datos);

private:

    static seon::aplicacion::configuracion::trama configuracion;
};

};

