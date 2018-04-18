#include "consola_seon.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    consola_seon w;
    w.show();
    return a.exec();
}
