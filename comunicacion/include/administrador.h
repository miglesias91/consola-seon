#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace seon::comunicacion {

class administrador {

public:
    administrador(const seon::aplicacion::configuracion::comunicacion & configuracion);
    virtual ~administrador();

    void iniciar();

private:

    seon::aplicacion::configuracion::comunicacion configuracion;
};

};

