#pragma once

#include <QWidget>

#include <qlabel.h>
namespace Ui { class gestor_ejercicios; };

class gestor_ejercicios : public QWidget {
    Q_OBJECT

    struct ejercicio {
    public:
        ejercicio(const std::string path) : video(new cv::VideoCapture(path)) {

            double_t cantidad_de_frames = video->get(CV_CAP_PROP_FRAME_COUNT);
            video->set(CV_CAP_PROP_POS_FRAMES, cantidad_de_frames / 2);
            cv::Mat frame;
            video->read(frame);
            cv::resize(frame, frame, cv::Size(600, 480), 1.0, 1.0, cv::INTER_LINEAR);
            cv::cvtColor(frame, frame, CV_BGR2RGB);

            this->previsualizacion = std::make_unique<QLabel>(new QLabel());
            this->previsualizacion->setPixmap(QPixmap::fromImage(QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888)));
        }
        ~ejercicio() {}

        std::unique_ptr<QLabel> previsualizacion;

    private:
        std::unique_ptr<cv::VideoCapture> video;
    };


public:
    gestor_ejercicios(const std::string &carpeta, QWidget *parent = Q_NULLPTR);
    ~gestor_ejercicios();

    void actualizar();
    void previsualizar();
private:
    Ui::gestor_ejercicios *ui;

    std::string carpeta_ejercicios;
    std::vector<QLabel*> previsualizaciones;
    QLabel * previsualizacion_actual;
};
