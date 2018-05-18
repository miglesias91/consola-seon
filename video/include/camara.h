#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace seon::video {

class camara {

public:
    camara(big_uint ancho, big_uint alto, uint fps);
    virtual ~camara();

    void filmar(const std::string & path_video);

private:

    big_uint ancho, alto;
    uint fps;
};

};

