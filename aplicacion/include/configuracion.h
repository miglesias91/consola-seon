#pragma once

// stl
#include <string>

namespace seon::aplicacion {

class configuracion {

    struct gui {
    };

    struct video {

    };

    struct gps {

    };

    struct pupitre {

    };

    struct pulsadores {

    };

    struct trama_seon {

    };

    struct logger {
        std::string path;
    };

public:
    configuracion();
    configuracion(const std::string & path_configuracion);
    virtual ~configuracion();

    bool levantar(const std::string & path_configuracion);

    gui gui;
    video video;
    gps gps;
    pupitre pupitre;
    pulsadores pulsadores;
    trama_seon trama_seon;
    logger logger;
};

};

