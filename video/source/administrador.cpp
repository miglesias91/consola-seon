#include <video/include/administrador.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::video {

administrador::administrador(seon::aplicacion::configuracion::video configuracion)
    : configuracion(configuracion) , camara_video(configuracion.filmacion.resolucion.ancho, configuracion.filmacion.resolucion.alto, configuracion.filmacion.fps), vista_video(nullptr) {

    aplicacion::logger::info("INICIO ADMIN VIDEO");
}

administrador::~administrador() {

    aplicacion::logger::info("CIERRE ADMIN VIDEO");
}

void administrador::iniciar() {

    this->camara_video.filmar(this->path_video, this->vista_video);
}

void administrador::entrada(const std::string & path_video) {
    this->path_video = path_video;
}

std::string administrador::entrada()
{
    return this->path_video;
}

std::string administrador::salida()
{
    return this->path_salida;
}

void administrador::salida(const std::string & path_salida) {

    this->path_salida = path_salida;
}



}
