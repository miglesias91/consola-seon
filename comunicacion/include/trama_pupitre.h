#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/configuracion.h>

// comunicacion
#include <comunicacion/include/trama.h>

namespace seon::comunicacion {

class trama_pupitre : public trama {

public:

    trama_pupitre();
    trama_pupitre(const std::string &tira_de_datos);
    virtual ~trama_pupitre();

    uint8_t header_1, header_2;
    uint8_t contador;
    bool arrp,
        enganche_desenganche_pic,
        boton_2, boton_3,
        graba_pic, acc_archivo_pic,
        seleccion_ventana_1, seleccion_ventana_2,
        sen_fija;

protected:
    virtual bool parsear(const std::string &tira_de_datos) override;

private:

    static seon::aplicacion::configuracion::trama configuracion;
};

};

