/********************************************************************************
** Form generated from reading UI file 'gestor_ejercicios.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTOR_EJERCICIOS_H
#define UI_GESTOR_EJERCICIOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
    QPushButton *btn_ver;
    QPushButton *btn_eliminar;
    QPushButton *btn_cerrar;
    QTableWidget *tabla_ejercicios;

    void setupUi(QWidget *gestor_ejercicios)
    {
        if (gestor_ejercicios->objectName().isEmpty())
            gestor_ejercicios->setObjectName(QStringLiteral("gestor_ejercicios"));
        gestor_ejercicios->resize(606, 417);
        layout_gestor = new QVBoxLayout(gestor_ejercicios);
        layout_gestor->setSpacing(0);
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

        btn_ver = new QPushButton(gestor_ejercicios);
        btn_ver->setObjectName(QStringLiteral("btn_ver"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_ver->sizePolicy().hasHeightForWidth());
        btn_ver->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
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
        sizePolicy.setHeightForWidth(btn_cerrar->sizePolicy().hasHeightForWidth());
        btn_cerrar->setSizePolicy(sizePolicy);
        btn_cerrar->setFont(font1);

        layout_botones->addWidget(btn_cerrar);


        layout_gestor->addLayout(layout_botones);

        tabla_ejercicios = new QTableWidget(gestor_ejercicios);
        tabla_ejercicios->setObjectName(QStringLiteral("tabla_ejercicios"));

        layout_gestor->addWidget(tabla_ejercicios);


        retranslateUi(gestor_ejercicios);

        QMetaObject::connectSlotsByName(gestor_ejercicios);
    } // setupUi

    void retranslateUi(QWidget *gestor_ejercicios)
    {
        gestor_ejercicios->setWindowTitle(QApplication::translate("gestor_ejercicios", "gestor_ejercicios", Q_NULLPTR));
        lbl_ejercicios->setText(QApplication::translate("gestor_ejercicios", "Ejercicios", Q_NULLPTR));
        btn_ver->setText(QApplication::translate("gestor_ejercicios", "Ver", Q_NULLPTR));
        btn_eliminar->setText(QApplication::translate("gestor_ejercicios", "Eliminar", Q_NULLPTR));
        btn_cerrar->setText(QApplication::translate("gestor_ejercicios", "Cerrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gestor_ejercicios: public Ui_gestor_ejercicios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTOR_EJERCICIOS_H
