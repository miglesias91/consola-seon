#pragma once

// log
#include <log/include/AdministradorLog.h>

namespace seon::aplicacion {

class logger {
public:

    static void iniciar(const std::string & config_log);

    static void liberar();

    // GETTERS

    // SETTERS

    // METODOS

    static void marca(const std::string &  mensaje);
    static void debug(const std::string &  mensaje);
    static void info(const std::string &  mensaje);
    static void advertencia(const std::string &  mensaje);
    static void error(const std::string &  mensaje);
    static void critico(const std::string &  mensaje);

protected:

private:

    logger();
    virtual ~logger();

    static herramientas::log::Logger * log;
    static bool activado;
    
};

};

