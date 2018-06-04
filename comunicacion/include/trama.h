#pragma once

// stl
#include <string>

namespace seon::comunicacion {

class trama {

public:

    trama();
    virtual ~trama();

    bool setear(const std::string & tira_de_datos);

private:
};

};

