#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/configuracion.h>

// comunicacion
#include <comunicacion/include/trama.h>

namespace seon::comunicacion {

class trama_pulsadores : public trama {

public:

    trama_pulsadores();
    trama_pulsadores(const std::string & tira_de_datos);
    virtual ~trama_pulsadores();

    uint8_t header_1, header_2;
    uint32_t contador;
    bool ref_est,
        pantalla_datos, pantalla_barrido, pantalla_normal,
        ventana_optica_lava, ventana_optica_limpia,
        pa_ir,
        camara_ir, camara_diurna,
        zoom_amplio, zoom_estrecho,
        foco_cerca, foco_lejos,
        video_cuantificado, video_diferenciado, video_normal,
        enganche_cuantificado, enganche_diferenciado,
        modo_fijo, modo_esclavo, modo_estable;

protected:
    virtual bool parsear(const std::string & tira_de_datos) override;

private:
    static seon::aplicacion::configuracion::trama configuracion;

};

};

