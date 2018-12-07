#include <video/include/administrador.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::video {

administrador::administrador(seon::aplicacion::configuracion::video configuracion)
    : configuracion(configuracion), cam(configuracion), capturador(configuracion) {

    aplicacion::logger::info("INICIO ADMIN VIDEO");
}

administrador::~administrador() {
    this->cam.detener();
    this->capturador.detener();
    aplicacion::logger::info("CIERRE ADMIN VIDEO");
}

void administrador::comenzar_captura() {
    this->capturador.capturar();
}

void administrador::detener_captura() {
    this->capturador.detener();
}

void administrador::comenzar_filmacion() {
    this->cam.filmar();
}

void administrador::detener_filmacion() {
    this->cam.detener();
}

}
