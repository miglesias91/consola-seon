#include "gestor_ejercicios.h"
#include "ui_gestor_ejercicios.h"

// stl
#include <filesystem>

// utiles
#include <utiles/include/Fecha.h>

gestor_ejercicios::gestor_ejercicios(const std::string &carpeta, QWidget *parent) : 
    carpeta_ejercicios(carpeta), QWidget(parent) {
    this->ui = new Ui::gestor_ejercicios();
    this->ui->setupUi(this);

    uint16_t fila = 0;
    for (auto ejercicio : std::experimental::filesystem::directory_iterator(carpeta)) {
        std::string nombre = ejercicio.path().filename().string();
        std::string extension = ejercicio.path().extension().string();

        std::chrono::system_clock::time_point tp(std::experimental::filesystem::last_write_time(ejercicio.path()).time_since_epoch());
        herramientas::utiles::Fecha fecha = herramientas::utiles::Fecha::parsear(tp);

        uintmax_t tamanio_kb = std::experimental::filesystem::file_size(ejercicio.path()) / 1000;

        this->ui->tabla_ejercicios->setItem(fila, 0, new QTableWidgetItem(nombre.c_str()));
        this->ui->tabla_ejercicios->setItem(fila, 2, new QTableWidgetItem(fecha.getStringAAAAMMDDHHmmSS("/", " ", ":").c_str()));
        this->ui->tabla_ejercicios->setItem(fila, 1, new QTableWidgetItem(extension.c_str()));
        this->ui->tabla_ejercicios->setItem(fila, 3, new QTableWidgetItem((std::to_string(tamanio_kb) + " KB").c_str()));
        fila++;
    }

    this->ui->tabla_ejercicios->resizeColumnsToContents();
}

gestor_ejercicios::~gestor_ejercicios() {
    delete ui;
}
