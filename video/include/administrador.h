#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/configuracion.h>

// video
#include <video/include/camara.h>
#include <video/include/vista.h>

namespace seon::video {

class administrador {

public:
    administrador(seon::aplicacion::configuracion::video configuracion);
    virtual ~administrador();

    void iniciar();

    void entrada(const std::string & path_video);

    std::string entrada();

    void salida(vista * vista);

private:

    seon::aplicacion::configuracion::video configuracion;

    camara camara_video;
    vista * vista_video;
    std::string path_video;
};

};

