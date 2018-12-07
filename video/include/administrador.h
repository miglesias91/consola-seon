#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/configuracion.h>

// video
#include <video/include/camara.h>
#include <video/include/capturador_pantalla.h>

namespace seon::video {

class administrador {

public:
    administrador(seon::aplicacion::configuracion::video configuracion);
    virtual ~administrador();

    void comenzar_captura();
    void detener_captura();

    void comenzar_filmacion();
    void detener_filmacion();

    seon::aplicacion::configuracion::video configuracion;

private:
    seon::video::camara cam;
    seon::video::capturador_pantalla capturador;
};

};

