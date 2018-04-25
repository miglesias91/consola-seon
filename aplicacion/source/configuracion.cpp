#include <aplicacion/include/configuracion.h>

// herramientas
#include <utiles/include/FuncionesSistemaArchivos.h>
#include <utiles/include/Json.h>

namespace seon::aplicacion {

configuracion::configuracion() {
}

configuracion::configuracion(const std::string & path_configuracion) {

}

configuracion::~configuracion() {
}

bool configuracion::levantar(const std::string & path_configuracion)
{
    std::string contenido_configuracion;
    herramientas::utiles::FuncionesSistemaArchivos::leer(path_configuracion, contenido_configuracion);

    herramientas::utiles::Json configuracion_json(contenido_configuracion);

    return true;
}



}
