#include "consola_seon.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    consola_seon ventana_principal;
    ventana_principal.showMaximized();
    return app.exec();
}
