#pragma once

#include <Windows.h>

// stl
#include <string>
#include <thread>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace seon::video {

class capturador_pantalla {

public:
    capturador_pantalla(seon::aplicacion::configuracion::video configuracion);
    virtual ~capturador_pantalla();

    virtual void capturar();
    virtual void detener();

private:
    seon::aplicacion::configuracion::video configuracion;
    STARTUPINFO info_cap;
    PROCESS_INFORMATION processInfo_cap;
};

};

