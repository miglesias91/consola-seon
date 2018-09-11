#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/configuracion.h>

// comunicacion
#include <comunicacion/include/trama.h>

namespace seon::comunicacion {

class trama_seon : public trama {

public:

    trama_seon();
    trama_seon(const std::string & tira_de_datos);
    virtual ~trama_seon();

    enum origen_dato { INVALIDO = -1, TELEMETRO = 0, MANUAL = 1, DEFECTO = 2};

    origen_dato origen;
    uint32_t distancia, velocidad;  // distancia = yardas, velocidad = nudos
    bool prediccion, enganche, radar_activado;
    uint8_t header_1, header_2, zoom, azimut_grafico, elevacion_grafico;
    uint16_t distancia_radar;
    double_t azimut_radar, azimut_absoluto, elevacion_absoluta;
    std::string tipo_blanco;
    aplicacion::configuracion::posicion centro_gravedad, corrimiento;

protected:
    virtual bool parsear(const std::string & tira_de_datos) override;

private:

    static seon::aplicacion::configuracion::trama configuracion;

    void reconocer_origen_dato(const uint8_t &byte);
    void reconocer_modo_prediccion_enganche(const uint8_t &byte);
    void reconocer_velocidad(const uint8_t &byte);
    void reconocer_radar_activado(const uint8_t &byte);
    void reconocer_tipo_blanco(const uint8_t &byte);

};

};

