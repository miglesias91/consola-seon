/********************************************************************************
** Form generated from reading UI file 'consola_seon.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLA_SEON_H
#define UI_CONSOLA_SEON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_consola_seonClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *consola_seonClass)
    {
        if (consola_seonClass->objectName().isEmpty())
            consola_seonClass->setObjectName(QStringLiteral("consola_seonClass"));
        consola_seonClass->resize(600, 400);
        menuBar = new QMenuBar(consola_seonClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        consola_seonClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(consola_seonClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        consola_seonClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(consola_seonClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        consola_seonClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(consola_seonClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        consola_seonClass->setStatusBar(statusBar);

        retranslateUi(consola_seonClass);

        QMetaObject::connectSlotsByName(consola_seonClass);
    } // setupUi

    void retranslateUi(QMainWindow *consola_seonClass)
    {
        consola_seonClass->setWindowTitle(QApplication::translate("consola_seonClass", "consola_seon", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class consola_seonClass: public Ui_consola_seonClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLA_SEON_H
