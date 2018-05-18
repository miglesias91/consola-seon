#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/configuracion.h>

// video
#include <video/include/camara.h>

namespace seon::video {

class administrador {

public:
    administrador(seon::aplicacion::configuracion::video configuracion);
    virtual ~administrador();

    void iniciar(const std::string & path_video);


private:

    seon::aplicacion::configuracion::video configuracion;

    camara camara_video;
};

};

