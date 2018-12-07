#pragma once

#include <Windows.h>

// stl
#include <string>
#include <thread>
#include <vector>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace seon::video {

class camara {

public:
    camara(seon::aplicacion::configuracion::video configuracion);
    virtual ~camara();

    void filmar();
    void detener();

private:
    seon::aplicacion::configuracion::video configuracion;
    STARTUPINFO info_cam;
    PROCESS_INFORMATION processInfo_cam;
};

};

