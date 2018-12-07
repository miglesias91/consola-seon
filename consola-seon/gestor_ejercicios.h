#pragma once

#include <Windows.h>

#include <QWidget>

#include <qlabel.h>
#include <qlayout.h>
#include <qbasictimer.h>

// opencv
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

// seon
#include <aplicacion/include/configuracion.h>

namespace Ui { class gestor_ejercicios; };

class gestor_ejercicios : public QWidget {
    Q_OBJECT

    struct ejercicio {
    public:
        ejercicio(const std::string &path, QWidget * padre) : path_video(path) {

            cv::VideoCapture video_cv(path);
            double_t cantidad_de_frames = video_cv.get(CV_CAP_PROP_FRAME_COUNT);
            video_cv.set(CV_CAP_PROP_POS_FRAMES, cantidad_de_frames / 2);
            cv::Mat frame;
            video_cv.read(frame);
            cv::resize(frame, frame, cv::Size(640, 480), 1.0, 1.0, cv::INTER_LINEAR);
            cv::cvtColor(frame, frame, CV_BGR2RGB);

            this->previsualizacion_video = std::make_unique<QLabel>(padre);
            this->previsualizacion_video->setPixmap(QPixmap::fromImage(QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888)));
            padre->layout()->addWidget(this->previsualizacion_video.get());
            this->previsualizacion_video->setVisible(false);

        }
        ~ejercicio() {}

        std::filesystem::path path() const {
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
        std::filesystem::path path_video;
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
    bool esta_en_lista(const std::filesystem::path &path) const;

    Ui::gestor_ejercicios *ui;

    seon::aplicacion::configuracion::video configuracion;
    std::vector<std::shared_ptr<ejercicio>> ejercicios;
    std::shared_ptr<ejercicio> ejercicio_actual;
};
