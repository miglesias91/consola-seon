#include "consola_seon.h"
#include <QtWidgets/QApplication>

// aplicacion
#include <aplicacion/include/administrador.h>

// vld
#if defined(DEBUG) || defined(_DEBUG)

#include <vld.h>

#endif

int main(int argc, char *argv[])
{
    // inicio aplicacion
    seon::aplicacion::administrador admin;
    admin.iniciar("configuracion.json");

    // inicio video
    //seon::video::camara camara(placa_de_video);

    QApplication app(argc, argv);
    consola_seon ventana_principal;
    ventana_principal.showMaximized();
    return app.exec();
}
