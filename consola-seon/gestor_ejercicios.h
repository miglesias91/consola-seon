#pragma once

#include <Windows.h>

#include <QWidget>

#include <qlabel.h>
#include <qlayout.h>
#include <qbasictimer.h>

// seon
#include <aplicacion/include/configuracion.h>

namespace Ui { class gestor_ejercicios; };

class gestor_ejercicios : public QWidget {
    Q_OBJECT

    struct ejercicio {
    public:
        ejercicio(const std::experimental::filesystem::path &path, const std::filesystem::path &path_thumbnail, QWidget * padre) : path_video(path) {

            this->previsualizacion_video = std::make_unique<QLabel>(padre);
            QPixmap pm = QPixmap(QString(path_thumbnail.string().c_str()));
            this->previsualizacion_video->setPixmap(pm.scaled(640, 480, Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation));
            padre->layout()->addWidget(this->previsualizacion_video.get());
            this->previsualizacion_video->setVisible(false);

        }
        ~ejercicio() {}

        std::experimental::filesystem::path path() const {
            return this->path_video;
        }

        void reproducir() {
            //this->video->iniciar();
            this->previsualizacion_video->setVisible(false);
            //this->video->visible(true);
        }

        void pausar() {
            //this->video->pausar();
        }

        void detener() {
            //this->video->detener();
            //this->video->visible(false);
            this->previsualizacion_video->setVisible(true);
        }

        void previsualizar(const bool &valor) {
            this->previsualizacion_video->setVisible(valor);
        }

        QLabel* previsualizacion() {
            this->previsualizacion_video.get();
        }

    private:
        std::experimental::filesystem::path path_video;
        std::unique_ptr<QLabel> previsualizacion_video;
    };


public:
    gestor_ejercicios(const seon::aplicacion::configuracion::video &config, QWidget *parent = Q_NULLPTR);
    ~gestor_ejercicios();

    void actualizar();
    void previsualizar_ejercicio();
    void reproducir_ejercicio();
    void pausar_ejercicio();
    void detener_ejercicio();
    void eliminar_ejercicio();

private:
    bool crear_thumbnail(const std::experimental::filesystem::path &path, std::filesystem::path *path_thumbnail) const;
    bool esta_en_lista(const std::experimental::filesystem::path &path) const;

    Ui::gestor_ejercicios *ui;

    seon::aplicacion::configuracion::video configuracion;
    std::vector<std::shared_ptr<ejercicio>> ejercicios;
    std::shared_ptr<ejercicio> ejercicio_actual;
};
