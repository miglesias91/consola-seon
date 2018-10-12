#include <comunicacion/include/trama_seon.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

trama_seon::trama_seon() : trama() {}

trama_seon::trama_seon(const std::string & tira_de_datos) {
    this->setear(tira_de_datos);
}

trama_seon::~trama_seon() {

}

bool trama_seon::parsear(const std::string & tira_de_datos) {
    if (tira_de_datos.size() != 27) {
        return false;
    }

    this->header_1 = tira_de_datos[0];
    this->header_2 = tira_de_datos[1];

    std::bitset<16> distancia(std::bitset<8>(tira_de_datos[3]).to_string() + std::bitset<8>(tira_de_datos[2]).to_string());
    this->distancia = distancia.to_ulong() * 1.094;  // 1 metro = 1.094 yardas

    this->reconocer_origen_dato(tira_de_datos[4]);
    this->reconocer_modo_prediccion_enganche(tira_de_datos[4]);
    std::bitset<16> byte_cuatro(std::bitset<8>(tira_de_datos[4]).to_string() + std::bitset<8>(tira_de_datos[5]).to_string());
    this->reconocer_velocidad(tira_de_datos[4], tira_de_datos[5]);
    this->zoom = tira_de_datos[6];
    this->reconocer_radar_activado(tira_de_datos[7]);
    this->reconocer_tipo_blanco(tira_de_datos[7]);

    std::bitset<16> azimut_radar(std::bitset<8>(tira_de_datos[9]).to_string() + std::bitset<8>(tira_de_datos[8]).to_string());
    this->azimut_radar = azimut_radar.to_ulong() + static_cast<float>(tira_de_datos[10]) / 100;

    std::bitset<16> distancia_radar(std::bitset<8>(tira_de_datos[12]).to_string() + std::bitset<8>(tira_de_datos[11]).to_string());
    this->distancia_radar = distancia_radar.to_ulong();

    this->azimut_grafico = tira_de_datos[13];
    this->elevacion_grafico = tira_de_datos[14];

    std::bitset<16> azimut_absoluto(std::bitset<8>(tira_de_datos[16]).to_string() + std::bitset<8>(tira_de_datos[15]).to_string());
    this->azimut_absoluto = azimut_absoluto.to_ulong() + static_cast<float>(tira_de_datos[17]) / 100;

    std::bitset<16> elevacion_absoluta(std::bitset<8>(tira_de_datos[19]).to_string() + std::bitset<8>(tira_de_datos[18]).to_string());
    this->elevacion_absoluta = elevacion_absoluta.to_ulong() + static_cast<float>(tira_de_datos[20]) / 100;

    std::bitset<16> cgx(std::bitset<8>(tira_de_datos[22]).to_string() + std::bitset<8>(tira_de_datos[21]).to_string());
    this->centro_gravedad.x = cgx.to_ulong();
    std::bitset<16> cgy(std::bitset<8>(tira_de_datos[24]).to_string() + std::bitset<8>(tira_de_datos[23]).to_string());
    this->centro_gravedad.y = cgy.to_ulong();

    this->corrimiento.x = static_cast<uint32_t>(tira_de_datos[25]);
    this->corrimiento.y = static_cast<uint32_t>(tira_de_datos[26]);

    return true;
}
void trama_seon::reconocer_origen_dato(const uint8_t &byte) {
    std::bitset<8> bits(byte);

    if (bits[6] == 0 && bits[7] == 1) {
        this->origen = TELEMETRO;
        return;
    }
    if (bits[6] == 1 && bits[7] == 1) {
        this->origen = MANUAL;
        return;
    }
    if (bits[6] == 1 && bits[7] == 0) {
        this->origen = DEFECTO;
        return;
    }
    this->origen = origen_dato::INVALIDO;
}

void trama_seon::reconocer_modo_prediccion_enganche(const uint8_t &byte) {
    std::bitset<8> bits(byte);

    if (bits[4] == 1 && bits[5] == 1) {
        this->prediccion = true;
        this->enganche = true;
        return;
    }
    if (bits[4] == 1 && bits[5] == 0) {
        this->prediccion = true;
        this->enganche = false;
        return;
    }
    if (bits[4] == 0 && bits[5] == 1) {
        this->prediccion = false;
        this->enganche = true;
        return;
    }
    this->prediccion = false;
    this->enganche = false;
}

void trama_seon::reconocer_velocidad(const uint8_t &byte_primero, const uint8_t &byte_segundo) {
    std::bitset<16> bits(std::bitset<8>(byte_segundo).to_string() + std::bitset<8>(byte_primero).to_string());

    bits[15] = 0; bits[14] = 0; bits[13] = 0; bits[12] = 0;

    this->velocidad = bits.to_ulong() * 1.944;  // 1 m/s = 1.944 nudos
}

void trama_seon::reconocer_radar_activado(const uint8_t &byte) {
    std::bitset<8> bits(byte);

    this->radar_activado = bits[7] == 1;
}

void trama_seon::reconocer_tipo_blanco(const uint8_t &byte) {
    std::bitset<8> bits(byte);
    bits[7] = 0;

    switch (bits.to_ulong()) {
        case 0: this->tipo_blanco = "S"; break;
        case 1: this->tipo_blanco = "A"; break;
        case 2: this->tipo_blanco = "Y"; break;
        case 3: this->tipo_blanco = "U"; break;
        case 4: this->tipo_blanco = "T"; break;
        default: this->tipo_blanco = "-"; break;
    }
}

}