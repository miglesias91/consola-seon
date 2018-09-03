#include <comunicacion/include/trama_pulsadores.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

trama_pulsadores::trama_pulsadores() : trama(),
header_1(0), header_2(0),
contador(0),
ref_est(false),
pantalla_datos(false), pantalla_barrido(false), pantalla_normal(false),
ventana_optica_lava(false), ventana_optica_limpia(false),
pa_ir(false),
camara_ir(false), camara_diurna(false),
zoom_amplio(false), zoom_estrecho(false),
foco_cerca(false), foco_lejos(false),
video_cuantificado(false), video_diferenciado(false), video_normal(false),
enganche_cuantificado(false), enganche_diferenciado(false),
modo_fijo(false), modo_esclavo(false), modo_estable(false) {}

trama_pulsadores::trama_pulsadores(const std::string & tira_de_datos) : trama(),
header_1(0), header_2(0),
contador(0),
ref_est(false),
pantalla_datos(false), pantalla_barrido(false), pantalla_normal(false),
ventana_optica_lava(false), ventana_optica_limpia(false),
pa_ir(false),
camara_ir(false), camara_diurna(false),
zoom_amplio(false), zoom_estrecho(false),
foco_cerca(false), foco_lejos(false),
video_cuantificado(false), video_diferenciado(false), video_normal(false),
enganche_cuantificado(false), enganche_diferenciado(false),
modo_fijo(false), modo_esclavo(false), modo_estable(false) {
    this->setear(tira_de_datos);
}

trama_pulsadores::~trama_pulsadores() {

}

bool trama_pulsadores::parsear(const std::string & tira_de_datos) {

    if (tira_de_datos.size() != 25) {
        return false;
    }

    this->header_1 = tira_de_datos[0];
    this->header_2 = tira_de_datos[1];

    std::bitset<8> char1(tira_de_datos[2]);
    std::bitset<8> char2(tira_de_datos[3]);

    std::bitset<16> contador(char1.to_string() + char2.to_string());
    this->contador = contador.to_ulong();

    this->ref_est = tira_de_datos[4] == 0x7a;
    this->pantalla_datos = tira_de_datos[5] == 0x7a;
    this->pantalla_barrido = tira_de_datos[6] == 0x7a;
    this->pantalla_normal = tira_de_datos[7] == 0x7a;
    this->ventana_optica_lava = tira_de_datos[8] == 0x7a;
    this->ventana_optica_limpia = tira_de_datos[9] == 0x7a;
    this->pa_ir = tira_de_datos[10] == 0x7a;
    this->camara_ir = tira_de_datos[11] == 0x7a;
    this->camara_diurna = tira_de_datos[12] == 0x7a;
    this->zoom_amplio = tira_de_datos[13] == 0x7a;
    this->zoom_estrecho = tira_de_datos[14] == 0x7a;
    this->foco_cerca = tira_de_datos[15] == 0x7a;
    this->foco_lejos = tira_de_datos[16] == 0x7a;
    this->video_cuantificado = tira_de_datos[17] == 0x7a;
    this->video_diferenciado = tira_de_datos[18] == 0x7a;
    this->video_normal = tira_de_datos[19] == 0x7a;
    this->enganche_cuantificado = tira_de_datos[20] == 0x7a;
    this->enganche_diferenciado = tira_de_datos[21] == 0x7a;
    this->modo_fijo = tira_de_datos[22] == 0x7a;
    this->modo_esclavo = tira_de_datos[23] == 0x7a;
    this->modo_estable = tira_de_datos[24] == 0x7a;

    return true;
}

}
