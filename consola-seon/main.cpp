#include "consola_seon.h"
#include <QtWidgets/QApplication>

// aplicacion
#include <aplicacion/include/administrador.h>

// vld
#ifdef DEBUG | _DEBUG
#include <vld.h>
#endif

int main(int argc, char *argv[])
{
    // inicio aplicacion
    seon::aplicacion::administrador admin;


    // inicio video

    QApplication app(argc, argv);
    consola_seon ventana_principal;
    ventana_principal.showMaximized();
    return app.exec();
}
