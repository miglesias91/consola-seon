#pragma once

// stl
#include <string>
#include <thread>
#include <vector>

// aplicacion
#include <aplicacion/include/configuracion.h>

// video
#include <video/include/vista.h>

namespace seon::video {

class camara {

public:
    camara(big_uint ancho, big_uint alto, uint fps);
    virtual ~camara();

    void filmar(const std::string & path_video, vista * vista_video);

private:

    big_uint ancho, alto;
    uint fps;
    std::thread hilo_filmacion;
    std::vector<unsigned char*> buffer_cuadros;
};

};

