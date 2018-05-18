#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace seon::aplicacion {

class administrador {

public:
    administrador();
    virtual ~administrador();

    void iniciar(const std::string & path_configuracion);

    configuracion configuracion;

private:

};

};

