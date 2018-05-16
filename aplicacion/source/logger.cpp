#include <aplicacion/include/logger.h>


// stl
#include <iostream>

// utiles
#include <utiles/include/FuncionesSistemaArchivos.h>
#include <utiles/include/FuncionesString.h>

namespace seon::aplicacion {

herramientas::log::Logger * logger::log = nullptr;
bool logger::activado = false;

logger::logger() {}

logger::~logger() {}

void logger::iniciar(const std::string &  config_log) {
    activado = true;
    log = herramientas::log::AdministradorLog::iniciarNuevo(config_log);
}

void logger::liberar() {
    herramientas::log::AdministradorLog::liberarTodo();
}

void logger::marca(const std::string &  mensaje) {
    if (activado) {
        log->marca(mensaje);
    }
}

void logger::debug(const std::string &  mensaje) {
    if (activado) {
        log->debug(mensaje);
    }
}

void logger::info(const std::string &  mensaje) {
    if (activado) {
        log->info(mensaje);
    }
}

void logger::advertencia(const std::string &  mensaje) {
    if (activado) {
        log->advertencia(mensaje);
    }
}

void logger::error(const std::string &  mensaje) {
    if (activado) {
        log->error(mensaje);
    }
}

void logger::critico(const std::string &  mensaje) {
    if (activado) {
        log->critico(mensaje);
    }
}

};