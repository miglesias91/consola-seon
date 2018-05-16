#include <aplicacion/include/configuracion.h>

namespace seon::aplicacion {

configuracion::configuracion() {}

configuracion::configuracion(const std::string & path_configuracion) {}

configuracion::~configuracion() {}

bool configuracion::levantar(const std::string & path_configuracion)
{
    std::string contenido_configuracion;
    herramientas::utiles::FuncionesSistemaArchivos::leer(path_configuracion, contenido_configuracion);

    herramientas::utiles::Json configuracion_json(contenido_configuracion);
    
    this->tramas.levantar(configuracion_json.getAtributoValorString("config_tramas"));
    this->gui.levantar(configuracion_json.getAtributoValorString("config_gui"));
    this->video.levantar(configuracion_json.getAtributoValorString("config_video"));

    std::string path_config_log = configuracion_json.getAtributoValorString("config_log");
    herramientas::utiles::FuncionesSistemaArchivos::leer(path_config_log, this->logger.detallado);

    herramientas::utiles::Json json_config_log(this->logger.detallado);

    this->logger.activado = json_config_log.getAtributoValorBool("activado");

    if (this->logger.activado) {
        this->logger.path = path_config_log;
    }

    return true;
}

std::string configuracion::detallado()
{
    return
        "## CONFIGURACION ##\n"
        "LOG: " + this->logger.path.u8string() + "\n" + this->logger.detallado + "\n" +
        "GUI: " + this->gui.path.u8string() + "\n" + this->gui.detallado + "\n" +
        "TRAMAS: " + this->tramas.path.u8string() + "\n" + this->tramas.detallado + "\n" +
        "VIDEO: " + this->video.path.u8string() + "\n" + this->video.detallado + "\n"
        ;
}

}
