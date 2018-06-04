#include <comunicacion/include/administrador.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

administrador::administrador(const seon::aplicacion::configuracion::comunicacion & configuracion) : configuracion(configuracion) {
    aplicacion::logger::info("INICIO ADMIN COMUNICACION");
}

administrador::~administrador() {

    aplicacion::logger::info("CIERRE ADMIN COMUNICACION");
}

void administrador::iniciar() {
    
}



}
