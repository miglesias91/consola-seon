#pragma once

#include <QtWidgets/QWidget>
#include "ui_simuladorcomu.h"

// serial
#include <serial/serial.h>

class simuladorcomu : public QWidget
{
    Q_OBJECT

public:
    simuladorcomu(QWidget *parent = Q_NULLPTR);
    virtual ~simuladorcomu();

    bool conectar_seon();
    bool conectar_botonera();
    bool conectar_pupitre();

    bool enviar_seon();
    bool enviar_botonera();
    bool enviar_pupitre();

    void setear_conexiones();

private:
    Ui::simuladorcomuClass ui;

    serial::Serial com_seon, com_botonera, com_pupitre;
};
