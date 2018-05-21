#pragma once

// stl
#include <string>
#include <thread>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace seon::video {

class vista {

public:
    vista();
    virtual ~vista();

    virtual void mostrar(unsigned char * data, big_uint columnas, big_uint filas, uint canales, big_uint tamanio_en_bytes = 0) = 0;

private:
};

};

