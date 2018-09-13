#pragma once

#include <QWidget>
namespace Ui { class gestor_ejercicios; };

class gestor_ejercicios : public QWidget {
    Q_OBJECT

public:
    gestor_ejercicios(const std::string &carpeta, QWidget *parent = Q_NULLPTR);
    ~gestor_ejercicios();

    void actualizar();

private:
    Ui::gestor_ejercicios *ui;

    std::string carpeta_ejercicios;
};
