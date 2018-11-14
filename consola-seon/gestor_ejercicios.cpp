#include "gestor_ejercicios.h"
#include "ui_gestor_ejercicios.h"

//qt
#include <qtablewidget.h>

// stl
#include <filesystem>

// utiles
#include <utiles/include/Fecha.h>

gestor_ejercicios::gestor_ejercicios(const std::string &carpeta, QWidget *parent) : 
    carpeta_ejercicios(carpeta), QWidget(parent) {
    this->ui = new Ui::gestor_ejercicios();
    this->ui->setupUi(this);

    //this->setAttribute(Qt::WA_DeleteOnClose);

    QObject::connect(this->ui->tabla_ejercicios, &QTableWidget::itemSelectionChanged, this, &gestor_ejercicios::previsualizar_ejercicio);
    QObject::connect(this->ui->btn_ver, &QPushButton::released, this, &gestor_ejercicios::reproducir_ejercicio);
    QObject::connect(this->ui->btn_pausar, &QPushButton::released, this, &gestor_ejercicios::pausar_ejercicio);
    QObject::connect(this->ui->btn_detener, &QPushButton::released, this, &gestor_ejercicios::detener_ejercicio);
    QObject::connect(this->ui->btn_eliminar, &QPushButton::released, this, &gestor_ejercicios::eliminar_ejercicio);

    this->actualizar();
}

void gestor_ejercicios::actualizar() {
    //this->ui->tabla_ejercicios->reset();

    uint16_t cantidad_de_ejercicios = std::distance(std::experimental::filesystem::directory_iterator(this->carpeta_ejercicios),
        std::experimental::filesystem::directory_iterator{});

    this->ui->tabla_ejercicios->setColumnCount(3);
    this->ui->tabla_ejercicios->setRowCount(cantidad_de_ejercicios);

    uint16_t fila = 0;
    for (auto ejercicio : std::experimental::filesystem::directory_iterator(this->carpeta_ejercicios)) {

        std::shared_ptr<gestor_ejercicios::ejercicio> ej = std::make_shared<gestor_ejercicios::ejercicio>(ejercicio.path().string(), this->ui->widget_visualizacion);
        this->ejercicios.push_back(ej);

        std::string nombre = ejercicio.path().filename().string();

        std::chrono::system_clock::time_point tp(std::experimental::filesystem::last_write_time(ejercicio.path()).time_since_epoch());
        herramientas::utiles::Fecha fecha = herramientas::utiles::Fecha::parsear(tp);

        uintmax_t tamanio_kb = std::experimental::filesystem::file_size(ejercicio.path()) / 1000;

        QTableWidgetItem* item_nombre = new QTableWidgetItem(nombre.c_str());
        item_nombre->setTextAlignment(Qt::AlignmentFlag::AlignLeft);
        item_nombre->setTextAlignment(Qt::AlignmentFlag::AlignVCenter);
        this->ui->tabla_ejercicios->setItem(fila, 0, item_nombre);

        QTableWidgetItem* item_fecha = new QTableWidgetItem(fecha.getStringAAAAMMDDHHmmSS("/", " ", ":").c_str());
        item_fecha->setTextAlignment(Qt::AlignmentFlag::AlignLeft);
        item_fecha->setTextAlignment(Qt::AlignmentFlag::AlignVCenter);
        this->ui->tabla_ejercicios->setItem(fila, 1, item_fecha);

        QTableWidgetItem* item_tamanio = new QTableWidgetItem((std::to_string(tamanio_kb) + " KB").c_str());
        item_tamanio->setTextAlignment(Qt::AlignmentFlag::AlignLeft);
        item_tamanio->setTextAlignment(Qt::AlignmentFlag::AlignVCenter);
        this->ui->tabla_ejercicios->setItem(fila, 2, item_tamanio);
        fila++;
    }

    this->ui->tabla_ejercicios->setAlternatingRowColors(true);
    this->ui->tabla_ejercicios->setHorizontalHeaderLabels({ "Nombre", u8"Fecha creación", u8"Tamaño" });
    this->ui->tabla_ejercicios->verticalHeader()->setVisible(false);
    this->ui->tabla_ejercicios->resizeColumnsToContents();

    if (this->ejercicios.size()) {
        this->ejercicio_actual = this->ejercicios.at(0);
        this->ui->tabla_ejercicios->selectRow(0);
    }
}

void gestor_ejercicios::previsualizar_ejercicio() {
    if (this->ejercicios.empty()) { return; }

    this->ejercicio_actual->detener();

    QItemSelectionModel * modelo = this->ui->tabla_ejercicios->selectionModel();

    this->ejercicio_actual->previsualizar(false);
    this->ejercicio_actual = this->ejercicios.at(modelo->currentIndex().row());
    this->ejercicio_actual->previsualizar(true);
}

void gestor_ejercicios::reproducir_ejercicio() {
    this->ejercicio_actual->reproducir();
}

void gestor_ejercicios::pausar_ejercicio() {
    this->ejercicio_actual->pausar();
}

void gestor_ejercicios::detener_ejercicio() {
    this->ejercicio_actual->detener();
}

void gestor_ejercicios::eliminar_ejercicio() {
    if (this->ejercicios.empty()) { return; }

    this->ejercicio_actual->detener();

    QItemSelectionModel * modelo = this->ui->tabla_ejercicios->selectionModel();
    this->ejercicios.erase(this->ejercicios.begin() + modelo->currentIndex().row());
    this->ejercicio_actual = this->ejercicios.at(0);
}

gestor_ejercicios::~gestor_ejercicios() {
    //std::for_each(this->previsualizaciones.begin(), this->previsualizaciones.end(), [](QLabel* l) { delete l; });
    this->ejercicios.clear();
    delete ui;
}
