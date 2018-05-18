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
    
    this->config_tramas.levantar(configuracion_json.getAtributoValorString("config_tramas"));
    this->config_gui.levantar(configuracion_json.getAtributoValorString("config_gui"));
    this->config_video.levantar(configuracion_json.getAtributoValorString("config_video"));

    std::string path_config_log = configuracion_json.getAtributoValorString("config_log");
    herramientas::utiles::FuncionesSistemaArchivos::leer(path_config_log, this->config_logger.detallado);

    herramientas::utiles::Json json_config_log(this->config_logger.detallado);

    this->config_logger.activado = json_config_log.getAtributoValorBool("activado");

    if (this->config_logger.activado) {
        this->config_logger.path = path_config_log;
    }

    return true;
}

std::string configuracion::detallado()
{
    return
        "## CONFIGURACION ##\n"
        "LOG: " + this->config_logger.path.u8string() + "\n" + this->config_logger.detallado + "\n" +
        "GUI: " + this->config_gui.path.u8string() + "\n" + this->config_gui.detallado + "\n" +
        "TRAMAS: " + this->config_tramas.path.u8string() + "\n" + this->config_tramas.detallado + "\n" +
        "VIDEO: " + this->config_video.path.u8string() + "\n" + this->config_video.detallado + "\n"
        ;
}

}
