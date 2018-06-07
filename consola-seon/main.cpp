#include <consola-seon/include/consola_seon.h>
#include <QtWidgets/QApplication>

// vld
#if defined(DEBUG) || defined(_DEBUG)

#include <vld.h>

#endif

// aplicacion
#include <aplicacion/include/administrador.h>

// comunicacion
#include <comunicacion/include/administrador.h>

// video
#include <video/include/administrador.h>

int main(int argc, char *argv[])
{
    // inicio aplicacion
    seon::aplicacion::administrador admin_aplicacion;
    admin_aplicacion.iniciar("configuracion.json");

    // inicio admin video
    seon::video::administrador admin_video(admin_aplicacion.configuracion.config_video);

    // inicio admin comunicacion
    seon::comunicacion::administrador admin_comunicacion(admin_aplicacion.configuracion.config_comunicacion);

    QApplication app(argc, argv);
    consola_seon ventana_principal(&admin_video, &admin_comunicacion, admin_aplicacion.configuracion.config_gui);
    ventana_principal.showFullScreen();

    return app.exec();
}
