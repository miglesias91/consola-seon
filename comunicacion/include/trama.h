#pragma once

// stl
#include <string>

namespace seon::comunicacion {

class trama {

public:

    trama() : tira_de_datos("") {};
    virtual ~trama() {};

    virtual bool setear(const std::string & tira_de_datos) {
        bool parseo_ok = this->parsear(tira_de_datos);
        if (parseo_ok) {
            this->tira_de_datos = tira_de_datos;
        }
        return parseo_ok;
    };

    std::string tira_de_datos;

protected:

    virtual bool parsear(const std::string &tira_de_datos) = 0;
};

};

