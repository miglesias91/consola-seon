#include "gestor_ejercicios.h"
#include "ui_gestor_ejercicios.h"

//qt
#include <qtablewidget.h>

// stl
#include <filesystem>

// utiles
#include <utiles/include/Fecha.h>

// opencv
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

gestor_ejercicios::gestor_ejercicios(const std::string &carpeta, QWidget *parent) : 
    carpeta_ejercicios(carpeta), QWidget(parent) {
    this->ui = new Ui::gestor_ejercicios();
    this->ui->setupUi(this);

    //this->setAttribute(Qt::WA_DeleteOnClose);

    QObject::connect(this->ui->tabla_ejercicios, &QTableWidget::itemSelectionChanged, this, &gestor_ejercicios::previsualizar);
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

        cv::VideoCapture video(ejercicio.path().string());
        double_t cantidad_de_frames = video.get(CV_CAP_PROP_FRAME_COUNT);
        video.set(CV_CAP_PROP_POS_FRAMES, cantidad_de_frames / 2);
        cv::Mat frame;
        video.read(frame);
        cv::resize(frame, frame, cv::Size(600, 480), 1.0, 1.0, cv::INTER_LINEAR);
        cv::cvtColor(frame, frame, CV_BGR2RGB);

        QLabel* previsualizacion = new QLabel();
        previsualizacion->setPixmap(QPixmap::fromImage(QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888)));
        this->previsualizaciones.push_back(previsualizacion);
        this->ui->layout_gestor->addWidget(previsualizacion);
        previsualizacion->setVisible(false);

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

    if (this->previsualizaciones.size()) {
        this->previsualizacion_actual = this->previsualizaciones.at(0);
        this->ui->tabla_ejercicios->selectRow(0);
    }
}

void gestor_ejercicios::previsualizar() {
    if (this->previsualizaciones.empty()) { return; }

    QItemSelectionModel * modelo = this->ui->tabla_ejercicios->selectionModel();

    this->previsualizacion_actual->setVisible(false);
    this->previsualizacion_actual = this->previsualizaciones.at(modelo->currentIndex().row());
    this->previsualizacion_actual->setVisible(true);
}

gestor_ejercicios::~gestor_ejercicios() {
    std::for_each(this->previsualizaciones.begin(), this->previsualizaciones.end(), [](QLabel* l) { delete l; });
    this->previsualizaciones.clear();
    delete ui;
}
