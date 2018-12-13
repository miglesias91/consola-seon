#include <comunicacion/include/serial.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

SERIAL::SERIAL() {}

SERIAL::SERIAL(const seon::aplicacion::configuracion::trama & configuracion)
    : configuracion(configuracion), comunicacion_serial(configuracion.serial.puerto, configuracion.serial.baudrate, serial::Timeout::simpleTimeout(500)) {

    aplicacion::logger::info("inicio serial " + this->configuracion.serial.puerto);
}

SERIAL::~SERIAL() {

    aplicacion::logger::info("cierre serial " + this->configuracion.serial.puerto);
}

bool SERIAL::datos_disponibles() {
    
    return this->comunicacion_serial.available();
}

size_t SERIAL::escribir(const std::string & tira_de_datos) {

    aplicacion::logger::info("escribiendo datos en puerto " + this->configuracion.serial.puerto);

    uint32_t cantidad_de_bytes_escritos = this->comunicacion_serial.write(tira_de_datos);

    return cantidad_de_bytes_escritos;
}

size_t SERIAL::leer(std::string & tira_de_datos) {

    aplicacion::logger::info("leyendo datos en puerto " + this->configuracion.serial.puerto);

    return this->comunicacion_serial.read(tira_de_datos, this->configuracion.largo);
}

size_t SERIAL::esperar_y_leer(std::string & tira_de_datos) {

    aplicacion::logger::info("esperando para leer datos en puerto " + this->configuracion.serial.puerto);

    if (this->comunicacion_serial.waitReadable()) {
        aplicacion::logger::info("fin espera en puerto " + this->configuracion.serial.puerto + ", leyendo datos.");

        return this->comunicacion_serial.read(tira_de_datos);
    }

    aplicacion::logger::info("timeout en puerto " + this->configuracion.serial.puerto);

    return 0;
}

bool SERIAL::enviar(trama * trama_recibida) {

    aplicacion::logger::info("enviando trama en puerto " + this->configuracion.serial.puerto);

    if (this->configuracion.largo == this->escribir(trama_recibida->tira_de_datos)) {

        aplicacion::logger::info("trama enviada en puerto " + this->configuracion.serial.puerto + " con largo OK.");

        return true;
    }

    return false;
}

bool SERIAL::recibir(trama * trama_recibida) {

    std::string tira_de_datos = "";

    aplicacion::logger::info("recibiendo trama en puerto " + this->configuracion.serial.puerto);

    if (this->configuracion.largo == this->leer(tira_de_datos)) {
        aplicacion::logger::info("trama en puerto " + this->configuracion.serial.puerto + " recibida con largo OK.");
        return trama_recibida->setear(tira_de_datos);
    }

    return false;
}

bool SERIAL::esperar_y_recibir(trama * trama_recibida) {

    std::string tira_de_datos = "";

    aplicacion::logger::info("esperando para recibir trama en puerto " + this->configuracion.serial.puerto);

    if (this->configuracion.largo == this->esperar_y_leer(tira_de_datos)) {

        aplicacion::logger::info("fin espera en puerto " + this->configuracion.serial.puerto + ", recibida con largo OK, seteando trama.");

        return trama_recibida->setear(tira_de_datos);
    }

    return false;
}

bool SERIAL::recibir_hasta(trama * trama_recibida, const std::string &valor_de_corte) {
    std::string tira_de_datos = "";
    std::string caracter = "";

    aplicacion::logger::info("recibiendo trama en puerto " + this->configuracion.serial.puerto);

    while (this->comunicacion_serial.read(caracter, 1)) {
        tira_de_datos += caracter;
        if (std::string::npos != tira_de_datos.rfind(valor_de_corte)) {
            tira_de_datos = tira_de_datos.erase(tira_de_datos.size() - valor_de_corte.size());
            break;
        }
        caracter = "";
    }

    aplicacion::logger::info("trama en puerto " + this->configuracion.serial.puerto + " recibida con largo " + std::to_string(tira_de_datos.size()) + ".");

    return trama_recibida->setear(tira_de_datos);
}


}
