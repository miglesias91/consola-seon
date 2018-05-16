#include <aplicacion/include/administrador.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::aplicacion {

administrador::administrador() {}

administrador::~administrador() {

    logger::info("CIERRE CONSOLA");

    logger::liberar();
}

void administrador::iniciar(const std::string & path_configuracion) {

    try {
        this->configuracion.levantar(path_configuracion);
    }
    catch (herramientas::utiles::excepciones::ImposibleAbrirArchivo & e) {
        throw;
    }

    if (this->configuracion.logger.activado) {
        logger::iniciar(this->configuracion.logger.path.u8string());
        logger::info("INICIO CONSOLA");
        logger::debug(this->configuracion.detallado());
    }
}



}
