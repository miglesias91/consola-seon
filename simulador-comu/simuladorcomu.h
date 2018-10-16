#pragma once

#include <QtWidgets/QWidget>
#include "ui_simuladorcomu.h"

class simuladorcomu : public QWidget
{
    Q_OBJECT

public:
    simuladorcomu(QWidget *parent = Q_NULLPTR);

private:
    Ui::simuladorcomuClass ui;
};
