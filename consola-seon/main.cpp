#include "consola_seon.h"
#include <QtWidgets/QApplication>

// vld
#if defined(DEBUG) || defined(_DEBUG)

#include <vld.h>

#endif

// aplicacion
#include <aplicacion/include/administrador.h>

// video
#include <video/include/administrador.h>

int main(int argc, char *argv[])
{
    // inicio aplicacion
    seon::aplicacion::administrador admin_aplicacion;
    admin_aplicacion.iniciar("configuracion.json");

    // inicio video
    //seon::video::camara camara(placa_de_video);
    std::string directorio_ejecutable = std::experimental::filesystem::current_path().u8string();

    seon::video::administrador admin_video(admin_aplicacion.configuracion.config_video);
    //admin_video.entrada(directorio_ejecutable + "\\video-de-prueba.mp4");
    admin_video.salida(directorio_ejecutable + "\\salida.avi");

    QApplication app(argc, argv);
    consola_seon ventana_principal(&admin_video, admin_aplicacion.configuracion.config_gui);
    ventana_principal.showFullScreen();

    return app.exec();
}
