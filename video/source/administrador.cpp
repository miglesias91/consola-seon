#include <video/include/administrador.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::video {

administrador::administrador(seon::aplicacion::configuracion::video configuracion)
    : configuracion(configuracion) , camara_video(configuracion.resolucion.ancho, configuracion.resolucion.alto, configuracion.fps) {}

administrador::~administrador() {

    aplicacion::logger::info("CIERRE ADMIN VIDEO");
}

void administrador::iniciar(const std::string & path_video) {

    aplicacion::logger::info("INICIO ADMIN VIDEO");

    this->camara_video.filmar(path_video);
}



}
