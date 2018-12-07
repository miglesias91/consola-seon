/********************************************************************************
** Form generated from reading UI file 'gestor_ejercicios.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTOR_EJERCICIOS_H
#define UI_GESTOR_EJERCICIOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gestor_ejercicios
{
public:
    QVBoxLayout *layout_gestor;
    QHBoxLayout *layout_botones;
    QLabel *lbl_ejercicios;
    QPushButton *btn_detener;
    QPushButton *btn_pausar;
    QPushButton *btn_ver;
    QPushButton *btn_eliminar;
    QPushButton *btn_cerrar;
    QHBoxLayout *layout_visu;
    QTableWidget *tabla_ejercicios;
    QWidget *widget_visualizacion;
    QVBoxLayout *layout_visualizacion;

    void setupUi(QWidget *gestor_ejercicios)
    {
        if (gestor_ejercicios->objectName().isEmpty())
            gestor_ejercicios->setObjectName(QStringLiteral("gestor_ejercicios"));
        gestor_ejercicios->resize(592, 360);
        layout_gestor = new QVBoxLayout(gestor_ejercicios);
        layout_gestor->setSpacing(4);
        layout_gestor->setContentsMargins(11, 11, 11, 11);
        layout_gestor->setObjectName(QStringLiteral("layout_gestor"));
        layout_gestor->setContentsMargins(4, 4, 4, 4);
        layout_botones = new QHBoxLayout();
        layout_botones->setSpacing(5);
        layout_botones->setObjectName(QStringLiteral("layout_botones"));
        layout_botones->setContentsMargins(0, 0, -1, -1);
        lbl_ejercicios = new QLabel(gestor_ejercicios);
        lbl_ejercicios->setObjectName(QStringLiteral("lbl_ejercicios"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(14);
        lbl_ejercicios->setFont(font);

        layout_botones->addWidget(lbl_ejercicios);

        btn_detener = new QPushButton(gestor_ejercicios);
        btn_detener->setObjectName(QStringLiteral("btn_detener"));
        btn_detener->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_detener->sizePolicy().hasHeightForWidth());
        btn_detener->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        btn_detener->setFont(font1);

        layout_botones->addWidget(btn_detener);

        btn_pausar = new QPushButton(gestor_ejercicios);
        btn_pausar->setObjectName(QStringLiteral("btn_pausar"));
        btn_pausar->setEnabled(false);
        sizePolicy.setHeightForWidth(btn_pausar->sizePolicy().hasHeightForWidth());
        btn_pausar->setSizePolicy(sizePolicy);
        btn_pausar->setFont(font1);

        layout_botones->addWidget(btn_pausar);

        btn_ver = new QPushButton(gestor_ejercicios);
        btn_ver->setObjectName(QStringLiteral("btn_ver"));
        sizePolicy.setHeightForWidth(btn_ver->sizePolicy().hasHeightForWidth());
        btn_ver->setSizePolicy(sizePolicy);
        btn_ver->setFont(font1);

        layout_botones->addWidget(btn_ver);

        btn_eliminar = new QPushButton(gestor_ejercicios);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));
        sizePolicy.setHeightForWidth(btn_eliminar->sizePolicy().hasHeightForWidth());
        btn_eliminar->setSizePolicy(sizePolicy);
        btn_eliminar->setFont(font1);

        layout_botones->addWidget(btn_eliminar);

        btn_cerrar = new QPushButton(gestor_ejercicios);
        btn_cerrar->setObjectName(QStringLiteral("btn_cerrar"));
        btn_cerrar->setEnabled(false);
        sizePolicy.setHeightForWidth(btn_cerrar->sizePolicy().hasHeightForWidth());
        btn_cerrar->setSizePolicy(sizePolicy);
        btn_cerrar->setFont(font1);

        layout_botones->addWidget(btn_cerrar);


        layout_gestor->addLayout(layout_botones);

        layout_visu = new QHBoxLayout();
        layout_visu->setSpacing(5);
        layout_visu->setObjectName(QStringLiteral("layout_visu"));
        layout_visu->setContentsMargins(-1, 0, 0, -1);
        tabla_ejercicios = new QTableWidget(gestor_ejercicios);
        tabla_ejercicios->setObjectName(QStringLiteral("tabla_ejercicios"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabla_ejercicios->sizePolicy().hasHeightForWidth());
        tabla_ejercicios->setSizePolicy(sizePolicy1);
        tabla_ejercicios->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tabla_ejercicios->setAlternatingRowColors(true);
        tabla_ejercicios->setSelectionMode(QAbstractItemView::SingleSelection);
        tabla_ejercicios->setSelectionBehavior(QAbstractItemView::SelectRows);

        layout_visu->addWidget(tabla_ejercicios);

        widget_visualizacion = new QWidget(gestor_ejercicios);
        widget_visualizacion->setObjectName(QStringLiteral("widget_visualizacion"));
        layout_visualizacion = new QVBoxLayout(widget_visualizacion);
        layout_visualizacion->setSpacing(0);
        layout_visualizacion->setContentsMargins(11, 11, 11, 11);
        layout_visualizacion->setObjectName(QStringLiteral("layout_visualizacion"));
        layout_visualizacion->setContentsMargins(0, 0, 0, 0);

        layout_visu->addWidget(widget_visualizacion);


        layout_gestor->addLayout(layout_visu);


        retranslateUi(gestor_ejercicios);

        QMetaObject::connectSlotsByName(gestor_ejercicios);
    } // setupUi

    void retranslateUi(QWidget *gestor_ejercicios)
    {
        gestor_ejercicios->setWindowTitle(QApplication::translate("gestor_ejercicios", "gestor_ejercicios", nullptr));
        lbl_ejercicios->setText(QApplication::translate("gestor_ejercicios", "Ejercicios", nullptr));
        btn_detener->setText(QApplication::translate("gestor_ejercicios", "Detener", nullptr));
        btn_pausar->setText(QApplication::translate("gestor_ejercicios", "Pausar", nullptr));
        btn_ver->setText(QApplication::translate("gestor_ejercicios", "Reproducir", nullptr));
        btn_eliminar->setText(QApplication::translate("gestor_ejercicios", "Eliminar", nullptr));
        btn_cerrar->setText(QApplication::translate("gestor_ejercicios", "Cerrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gestor_ejercicios: public Ui_gestor_ejercicios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTOR_EJERCICIOS_H
