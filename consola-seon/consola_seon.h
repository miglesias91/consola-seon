#pragma once

// qt
#include <QtWidgets/QMainWindow>
#include <QtMultimedia/qmediaplayer.h>

#include "ui_consola_seon.h"

class consola_seon : public QMainWindow
{
    Q_OBJECT

public:
    consola_seon(QWidget *parent = Q_NULLPTR);

private:

    void setear_inicio();

    Ui::consola_seonClass ui;

    // atributos
    QMediaPlayer reproductor;
};
