#pragma once

#include <QWidget>

#include <qlabel.h>
#include <qbasictimer.h>

// opencv
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

// consola
#include <consola-seon/include/filmacion_opencv.h>

namespace Ui { class gestor_ejercicios; };

class gestor_ejercicios : public QWidget {
    Q_OBJECT

    struct ejercicio {
    public:
        ejercicio(const std::string &path, QWidget * padre) {

            seon::aplicacion::configuracion::video config_video;
            config_video.filmacion.fps = 60;
            config_video.filmacion.path = path;
            config_video.filmacion.resolucion.alto = 480;
            config_video.filmacion.resolucion.ancho = 640;

            seon::video::administrador admin_video(config_video);
            this->video = std::make_unique<filmacion_opencv>(&admin_video);
            this->video->hijo_de(padre);
            this->video->visible(false);

            cv::VideoCapture video_cv(path);
            double_t cantidad_de_frames = video_cv.get(CV_CAP_PROP_FRAME_COUNT);
            video_cv.set(CV_CAP_PROP_POS_FRAMES, cantidad_de_frames / 2);
            cv::Mat frame;
            video_cv.read(frame);
            cv::resize(frame, frame, cv::Size(600, 480), 1.0, 1.0, cv::INTER_LINEAR);
            cv::cvtColor(frame, frame, CV_BGR2RGB);

            this->previsualizacion = std::make_unique<QLabel>(padre);
            this->previsualizacion->setPixmap(QPixmap::fromImage(QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888)));
            this->previsualizacion->setVisible(false);

        }
        ~ejercicio() {}

        void reproducir() {

        }

        void detener() {

        }

        void pausar() {

        }

        void previsualizar(const bool &valor) {
            this->previsualizacion->setVisible(valor);
        }

    private:

        std::unique_ptr<QLabel> previsualizacion;
        std::unique_ptr<filmacion_opencv> video;
    };


public:
    gestor_ejercicios(const std::string &carpeta, QWidget *parent = Q_NULLPTR);
    ~gestor_ejercicios();

    void actualizar();
    void previsualizar();
    void reproducir();

private:
    Ui::gestor_ejercicios *ui;

    std::string carpeta_ejercicios;
    std::vector<std::shared_ptr<ejercicio>> ejercicios;
    std::shared_ptr<ejercicio> ejercicio_actual;
};
