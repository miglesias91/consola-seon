#include <aplicacion/include/logger.h>

using namespace seon::aplicacion;

// stl
#include <iostream>

// utiles
#include <utiles/include/FuncionesString.h>

herramientas::log::Logger * logger::log = NULL;

logger::logger()
{
}

logger::~logger()
{
}

void logger::iniciar(const std::string &  config_log)
{
    log = herramientas::log::AdministradorLog::iniciarNuevo(config_log);
}

void logger::marca(const std::string &  mensaje)
{
    log->marca(mensaje);
}

void logger::debug(const std::string &  mensaje)
{
    log->debug(mensaje);
}

void logger::info(const std::string &  mensaje)
{
    log->info(mensaje);
}

void logger::advertencia(const std::string &  mensaje)
{
    log->advertencia(mensaje);
}

void logger::error(const std::string &  mensaje)
{
    log->error(mensaje);
}

void logger::critico(const std::string &  mensaje)
{
    log->critico(mensaje);
}