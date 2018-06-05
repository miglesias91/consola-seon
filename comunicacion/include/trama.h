#pragma once

// stl
#include <string>

namespace seon::comunicacion {

class trama {

public:

    trama() : tira_de_datos("") {};
    virtual ~trama() {};

    virtual bool setear(const std::string & tira_de_datos) { this->tira_de_datos = tira_de_datos; return true; };

    std::string tira_de_datos;

private:
};

};

