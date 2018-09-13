#include "gestor_ejercicios.h"
#include "ui_gestor_ejercicios.h"

// stl
#include <filesystem>

// utiles
#include <utiles/include/Fecha.h>

gestor_ejercicios::gestor_ejercicios(const std::string &carpeta, QWidget *parent) : 
    carpeta_ejercicios(carpeta), QWidget(parent) {
    ui = new Ui::gestor_ejercicios();
    ui->setupUi(this);

    for (auto ejercicio : std::experimental::filesystem::directory_iterator(carpeta)) {
        std::string nombre = ejercicio.path().string();
        std::string extension = ejercicio.path().extension().string();
        herramientas::utiles::Fecha fecha =
            herramientas::utiles::Fecha::parsear(std::experimental::filesystem::last_write_time(ejercicio.path()).time_since_epoch().count());
        std::experimental::filesystem::file_size(ejercicio.path());
    }
}

gestor_ejercicios::~gestor_ejercicios() {
    delete ui;
}
