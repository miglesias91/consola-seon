#include <comunicacion/include/trama_pupitre.h>

// herramientas
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::comunicacion {

trama_pupitre::trama_pupitre() : trama(),
header_1(0), header_2(0),
contador(0),
arrp(false),
enganche_desenganche_pic(false),
boton_2(false), boton_3(false),
graba_pic(false), acc_archivo_pic(false),
seleccion_ventana_1(false), seleccion_ventana_2(false),
sen_fija(false) {}

trama_pupitre::trama_pupitre(const std::string & tira_de_datos) {
    this->setear(tira_de_datos);
}

trama_pupitre::~trama_pupitre() {

}

bool trama_pupitre::parsear(const std::string & tira_de_datos) {
    if (tira_de_datos.size() != 12) {
        return false;
    }

    this->header_1 = tira_de_datos[0];
    this->header_2 = tira_de_datos[1];
    this->contador = tira_de_datos[2];
    this->arrp = tira_de_datos[3] == 0x7a;
    this->enganche_desenganche_pic = tira_de_datos[4] == 0x7a;
    this->boton_2 = tira_de_datos[5] == 0x7a;
    this->boton_3 = tira_de_datos[6] == 0x7a;
    this->graba_pic = tira_de_datos[7] == 0x7a;
    this->acc_archivo_pic = tira_de_datos[8] == 0x7a;
    this->seleccion_ventana_1 = tira_de_datos[9] == 0x7a;
    this->seleccion_ventana_2 = tira_de_datos[10] == 0x7a;
    this->sen_fija = tira_de_datos[11] == 0x7a;

    return true;
}
}
