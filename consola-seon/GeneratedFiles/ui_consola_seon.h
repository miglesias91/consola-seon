/********************************************************************************
** Form generated from reading UI file 'consola_seon.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLA_SEON_H
#define UI_CONSOLA_SEON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_consola_seonClass
{
public:
    QWidget *panel_central;
    QWidget *panel_lateral;
    QVBoxLayout *layout_lateral;
    QFrame *frame_testigo_pantalla;
    QVBoxLayout *layout_testigo_pantalla;
    QLabel *lbl_pantalla;
    QFrame *linea_testigo_pantalla;
    QLabel *lbl_pantalla_datos;
    QLabel *lbl_pantalla_barrido;
    QLabel *lbl_pantalla_normal;
    QFrame *frame_testigo_ventana_optica;
    QVBoxLayout *layout_testigo_ventana_optica;
    QLabel *lbl_ventana_optica;
    QFrame *linea_testigo_optica;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_optica_apagada_lava;
    QLabel *lbl_optica_lava;
    QLabel *lbl_optica_apagada_limpia;
    QLabel *lbl_optica_limpia;
    QFrame *frame_testigo_camara;
    QVBoxLayout *layout_testigo_camara;
    QLabel *lbl_camara;
    QFrame *linea_testigo_camara;
    QLabel *lbl_camara_diurna;
    QLabel *lbl_camara_ir;
    QFrame *frame_testigo_zoom;
    QVBoxLayout *layout_testigo_zoom;
    QLabel *lbl_zoom;
    QFrame *linea_testigo_zoom;
    QLabel *lbl_zoom_valor;
    QFrame *frame_testigo_foco;
    QVBoxLayout *layout_testigo_foco;
    QLabel *lbl_foco;
    QFrame *linea_testigo_foco;
    QLabel *lbl_foco_cerca;
    QLabel *lbl_foco_lejos;
    QLabel *lbl_foco_apagado;
    QFrame *frame_testigo_video;
    QVBoxLayout *layout_testigo_video;
    QLabel *lbl_video;
    QFrame *linea_testigo_video;
    QLabel *lbl_video_cuantificado;
    QLabel *lbl_video_diferenciado;
    QLabel *lbl_video_normal;
    QFrame *frame_testigo_enganche;
    QVBoxLayout *layout_testigo_enganche;
    QLabel *lbl_enganche;
    QFrame *linea_testigo_enganche;
    QLabel *lbl_enganche_cuantificado;
    QLabel *lbl_enganche_diferenciado;
    QLabel *lbl_enganche_cuantificado_inv;
    QFrame *frame_testigo_modo;
    QVBoxLayout *layout_testigo_modo;
    QLabel *lbl_modo;
    QFrame *linea_testigo_modo;
    QLabel *lbl_modo_fijo;
    QLabel *lbl_modo_esclavo;
    QLabel *lbl_modo_estable;
    QWidget *panel_superior;
    QHBoxLayout *layout_superior;
    QFrame *frame_referencia_estab;
    QVBoxLayout *layout_referencia_estab;
    QLabel *lbl_referencia_estab;
    QFrame *linea_referencia_estable;
    QLabel *lbl_imu_prob;
    QLabel *lbl_octans;
    QFrame *frame_enganche;
    QVBoxLayout *layout_enganche;
    QLabel *lbl_enganche_etiqueta;
    QFrame *linea_enganche_prediccion;
    QLabel *lbl_prediccion;
    QFrame *frame_datos_plataforma;
    QGridLayout *layout_datos_plataforma;
    QLabel *lbl_datos_plataforma;
    QLabel *lbl_azimut_valor;
    QLabel *lbl_elevacion_valor;
    QLabel *lbl_elevacion;
    QLabel *lbl_azimut;
    QFrame *frame_datos_gps;
    QGridLayout *layout_datos_gps;
    QLabel *lbl_longitud;
    QLabel *lbl_latitud;
    QLabel *lbl_latitud_valor;
    QLabel *lbl_datos_gps;
    QLabel *lbl_longitud_valor;
    QFrame *frame_datos_blanco;
    QGridLayout *layout_datos_blanco;
    QLabel *lbl_datos_blanco;
    QLabel *lbl_distancia_valor;
    QLabel *lbl_velocidad;
    QLabel *lbl_distancia;
    QLabel *lbl_velocidad_valor;
    QWidget *widget_datos_radar;
    QGridLayout *layout_datos_radar;
    QLabel *lbl_dist;
    QLabel *lbl_azimut_radar;
    QLabel *lbl_dist_valor;
    QLabel *lbl_tipo;
    QLabel *lbl_azimut_radar_valor;
    QLabel *lbl_tipo_valor;

    void setupUi(QMainWindow *consola_seonClass)
    {
        if (consola_seonClass->objectName().isEmpty())
            consola_seonClass->setObjectName(QStringLiteral("consola_seonClass"));
        consola_seonClass->resize(887, 655);
        consola_seonClass->setMaximumSize(QSize(887, 688));
        consola_seonClass->setWindowOpacity(1);
        consola_seonClass->setStyleSheet(QStringLiteral("QMainWindow { background-color: none; }"));
        panel_central = new QWidget(consola_seonClass);
        panel_central->setObjectName(QStringLiteral("panel_central"));
        panel_central->setMaximumSize(QSize(1920, 1080));
        panel_central->setAutoFillBackground(false);
        panel_central->setStyleSheet(QLatin1String("QWidget#panel_central { background-color: rgb(0, 0, 0, 0); }\n"
""));
        panel_lateral = new QWidget(panel_central);
        panel_lateral->setObjectName(QStringLiteral("panel_lateral"));
        panel_lateral->setGeometry(QRect(10, 30, 160, 532));
        layout_lateral = new QVBoxLayout(panel_lateral);
        layout_lateral->setSpacing(6);
        layout_lateral->setContentsMargins(11, 11, 11, 11);
        layout_lateral->setObjectName(QStringLiteral("layout_lateral"));
        layout_lateral->setContentsMargins(0, 0, 0, 0);
        frame_testigo_pantalla = new QFrame(panel_lateral);
        frame_testigo_pantalla->setObjectName(QStringLiteral("frame_testigo_pantalla"));
        frame_testigo_pantalla->setFrameShape(QFrame::Box);
        layout_testigo_pantalla = new QVBoxLayout(frame_testigo_pantalla);
        layout_testigo_pantalla->setSpacing(0);
        layout_testigo_pantalla->setContentsMargins(11, 11, 11, 11);
        layout_testigo_pantalla->setObjectName(QStringLiteral("layout_testigo_pantalla"));
        layout_testigo_pantalla->setContentsMargins(0, 0, 0, 0);
        lbl_pantalla = new QLabel(frame_testigo_pantalla);
        lbl_pantalla->setObjectName(QStringLiteral("lbl_pantalla"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        lbl_pantalla->setFont(font);
        lbl_pantalla->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_pantalla->setAlignment(Qt::AlignCenter);

        layout_testigo_pantalla->addWidget(lbl_pantalla);

        linea_testigo_pantalla = new QFrame(frame_testigo_pantalla);
        linea_testigo_pantalla->setObjectName(QStringLiteral("linea_testigo_pantalla"));
        linea_testigo_pantalla->setFrameShadow(QFrame::Plain);
        linea_testigo_pantalla->setFrameShape(QFrame::HLine);

        layout_testigo_pantalla->addWidget(linea_testigo_pantalla);

        lbl_pantalla_datos = new QLabel(frame_testigo_pantalla);
        lbl_pantalla_datos->setObjectName(QStringLiteral("lbl_pantalla_datos"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setStyleStrategy(QFont::PreferAntialias);
        lbl_pantalla_datos->setFont(font1);
        lbl_pantalla_datos->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 0);"));
        lbl_pantalla_datos->setAlignment(Qt::AlignCenter);

        layout_testigo_pantalla->addWidget(lbl_pantalla_datos);

        lbl_pantalla_barrido = new QLabel(frame_testigo_pantalla);
        lbl_pantalla_barrido->setObjectName(QStringLiteral("lbl_pantalla_barrido"));
        lbl_pantalla_barrido->setFont(font1);
        lbl_pantalla_barrido->setStyleSheet(QStringLiteral("background-color: rgb(155, 196, 226);"));
        lbl_pantalla_barrido->setAlignment(Qt::AlignCenter);

        layout_testigo_pantalla->addWidget(lbl_pantalla_barrido);

        lbl_pantalla_normal = new QLabel(frame_testigo_pantalla);
        lbl_pantalla_normal->setObjectName(QStringLiteral("lbl_pantalla_normal"));
        lbl_pantalla_normal->setFont(font1);
        lbl_pantalla_normal->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        lbl_pantalla_normal->setAlignment(Qt::AlignCenter);

        layout_testigo_pantalla->addWidget(lbl_pantalla_normal);


        layout_lateral->addWidget(frame_testigo_pantalla);

        frame_testigo_ventana_optica = new QFrame(panel_lateral);
        frame_testigo_ventana_optica->setObjectName(QStringLiteral("frame_testigo_ventana_optica"));
        frame_testigo_ventana_optica->setFrameShape(QFrame::Box);
        layout_testigo_ventana_optica = new QVBoxLayout(frame_testigo_ventana_optica);
        layout_testigo_ventana_optica->setSpacing(0);
        layout_testigo_ventana_optica->setContentsMargins(11, 11, 11, 11);
        layout_testigo_ventana_optica->setObjectName(QStringLiteral("layout_testigo_ventana_optica"));
        layout_testigo_ventana_optica->setContentsMargins(0, 0, 0, 0);
        lbl_ventana_optica = new QLabel(frame_testigo_ventana_optica);
        lbl_ventana_optica->setObjectName(QStringLiteral("lbl_ventana_optica"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbl_ventana_optica->sizePolicy().hasHeightForWidth());
        lbl_ventana_optica->setSizePolicy(sizePolicy);
        lbl_ventana_optica->setFont(font);
        lbl_ventana_optica->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_ventana_optica->setAlignment(Qt::AlignCenter);

        layout_testigo_ventana_optica->addWidget(lbl_ventana_optica);

        linea_testigo_optica = new QFrame(frame_testigo_ventana_optica);
        linea_testigo_optica->setObjectName(QStringLiteral("linea_testigo_optica"));
        linea_testigo_optica->setFrameShadow(QFrame::Plain);
        linea_testigo_optica->setFrameShape(QFrame::HLine);

        layout_testigo_ventana_optica->addWidget(linea_testigo_optica);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, 0, -1);
        lbl_optica_apagada_lava = new QLabel(frame_testigo_ventana_optica);
        lbl_optica_apagada_lava->setObjectName(QStringLiteral("lbl_optica_apagada_lava"));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setBold(false);
        font2.setWeight(50);
        font2.setStyleStrategy(QFont::PreferAntialias);
        lbl_optica_apagada_lava->setFont(font2);
        lbl_optica_apagada_lava->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_optica_apagada_lava->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lbl_optica_apagada_lava);

        lbl_optica_lava = new QLabel(frame_testigo_ventana_optica);
        lbl_optica_lava->setObjectName(QStringLiteral("lbl_optica_lava"));
        lbl_optica_lava->setFont(font1);
        lbl_optica_lava->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 255);"));
        lbl_optica_lava->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lbl_optica_lava);

        lbl_optica_apagada_limpia = new QLabel(frame_testigo_ventana_optica);
        lbl_optica_apagada_limpia->setObjectName(QStringLiteral("lbl_optica_apagada_limpia"));
        lbl_optica_apagada_limpia->setFont(font1);
        lbl_optica_apagada_limpia->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_optica_apagada_limpia->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lbl_optica_apagada_limpia);

        lbl_optica_limpia = new QLabel(frame_testigo_ventana_optica);
        lbl_optica_limpia->setObjectName(QStringLiteral("lbl_optica_limpia"));
        lbl_optica_limpia->setFont(font1);
        lbl_optica_limpia->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        lbl_optica_limpia->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lbl_optica_limpia);


        layout_testigo_ventana_optica->addLayout(horizontalLayout);


        layout_lateral->addWidget(frame_testigo_ventana_optica);

        frame_testigo_camara = new QFrame(panel_lateral);
        frame_testigo_camara->setObjectName(QStringLiteral("frame_testigo_camara"));
        frame_testigo_camara->setFrameShape(QFrame::Box);
        frame_testigo_camara->setMidLineWidth(1);
        layout_testigo_camara = new QVBoxLayout(frame_testigo_camara);
        layout_testigo_camara->setSpacing(0);
        layout_testigo_camara->setContentsMargins(11, 11, 11, 11);
        layout_testigo_camara->setObjectName(QStringLiteral("layout_testigo_camara"));
        layout_testigo_camara->setContentsMargins(0, 0, 0, 0);
        lbl_camara = new QLabel(frame_testigo_camara);
        lbl_camara->setObjectName(QStringLiteral("lbl_camara"));
        lbl_camara->setFont(font);
        lbl_camara->setAutoFillBackground(false);
        lbl_camara->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_camara->setFrameShape(QFrame::NoFrame);
        lbl_camara->setFrameShadow(QFrame::Plain);
        lbl_camara->setLineWidth(1);
        lbl_camara->setAlignment(Qt::AlignCenter);

        layout_testigo_camara->addWidget(lbl_camara);

        linea_testigo_camara = new QFrame(frame_testigo_camara);
        linea_testigo_camara->setObjectName(QStringLiteral("linea_testigo_camara"));
        linea_testigo_camara->setFrameShadow(QFrame::Plain);
        linea_testigo_camara->setFrameShape(QFrame::HLine);

        layout_testigo_camara->addWidget(linea_testigo_camara);

        lbl_camara_diurna = new QLabel(frame_testigo_camara);
        lbl_camara_diurna->setObjectName(QStringLiteral("lbl_camara_diurna"));
        lbl_camara_diurna->setEnabled(true);
        lbl_camara_diurna->setFont(font1);
        lbl_camara_diurna->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        lbl_camara_diurna->setAlignment(Qt::AlignCenter);

        layout_testigo_camara->addWidget(lbl_camara_diurna);

        lbl_camara_ir = new QLabel(frame_testigo_camara);
        lbl_camara_ir->setObjectName(QStringLiteral("lbl_camara_ir"));
        lbl_camara_ir->setFont(font1);
        lbl_camara_ir->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        lbl_camara_ir->setAlignment(Qt::AlignCenter);

        layout_testigo_camara->addWidget(lbl_camara_ir);


        layout_lateral->addWidget(frame_testigo_camara);

        frame_testigo_zoom = new QFrame(panel_lateral);
        frame_testigo_zoom->setObjectName(QStringLiteral("frame_testigo_zoom"));
        frame_testigo_zoom->setFrameShape(QFrame::Box);
        layout_testigo_zoom = new QVBoxLayout(frame_testigo_zoom);
        layout_testigo_zoom->setSpacing(0);
        layout_testigo_zoom->setContentsMargins(11, 11, 11, 11);
        layout_testigo_zoom->setObjectName(QStringLiteral("layout_testigo_zoom"));
        layout_testigo_zoom->setContentsMargins(0, 0, 0, 0);
        lbl_zoom = new QLabel(frame_testigo_zoom);
        lbl_zoom->setObjectName(QStringLiteral("lbl_zoom"));
        sizePolicy.setHeightForWidth(lbl_zoom->sizePolicy().hasHeightForWidth());
        lbl_zoom->setSizePolicy(sizePolicy);
        lbl_zoom->setFont(font);
        lbl_zoom->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_zoom->setAlignment(Qt::AlignCenter);

        layout_testigo_zoom->addWidget(lbl_zoom);

        linea_testigo_zoom = new QFrame(frame_testigo_zoom);
        linea_testigo_zoom->setObjectName(QStringLiteral("linea_testigo_zoom"));
        linea_testigo_zoom->setFrameShadow(QFrame::Plain);
        linea_testigo_zoom->setFrameShape(QFrame::HLine);

        layout_testigo_zoom->addWidget(linea_testigo_zoom);

        lbl_zoom_valor = new QLabel(frame_testigo_zoom);
        lbl_zoom_valor->setObjectName(QStringLiteral("lbl_zoom_valor"));
        lbl_zoom_valor->setFont(font1);
        lbl_zoom_valor->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_zoom_valor->setAlignment(Qt::AlignCenter);

        layout_testigo_zoom->addWidget(lbl_zoom_valor);


        layout_lateral->addWidget(frame_testigo_zoom);

        frame_testigo_foco = new QFrame(panel_lateral);
        frame_testigo_foco->setObjectName(QStringLiteral("frame_testigo_foco"));
        frame_testigo_foco->setFrameShape(QFrame::Box);
        layout_testigo_foco = new QVBoxLayout(frame_testigo_foco);
        layout_testigo_foco->setSpacing(0);
        layout_testigo_foco->setContentsMargins(11, 11, 11, 11);
        layout_testigo_foco->setObjectName(QStringLiteral("layout_testigo_foco"));
        layout_testigo_foco->setContentsMargins(0, 0, 0, 0);
        lbl_foco = new QLabel(frame_testigo_foco);
        lbl_foco->setObjectName(QStringLiteral("lbl_foco"));
        lbl_foco->setFont(font);
        lbl_foco->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_foco->setAlignment(Qt::AlignCenter);

        layout_testigo_foco->addWidget(lbl_foco);

        linea_testigo_foco = new QFrame(frame_testigo_foco);
        linea_testigo_foco->setObjectName(QStringLiteral("linea_testigo_foco"));
        linea_testigo_foco->setFrameShadow(QFrame::Plain);
        linea_testigo_foco->setFrameShape(QFrame::HLine);

        layout_testigo_foco->addWidget(linea_testigo_foco);

        lbl_foco_cerca = new QLabel(frame_testigo_foco);
        lbl_foco_cerca->setObjectName(QStringLiteral("lbl_foco_cerca"));
        lbl_foco_cerca->setFont(font2);
        lbl_foco_cerca->setStyleSheet(QStringLiteral("background-color: rgb(155, 196, 226);"));
        lbl_foco_cerca->setAlignment(Qt::AlignCenter);

        layout_testigo_foco->addWidget(lbl_foco_cerca);

        lbl_foco_lejos = new QLabel(frame_testigo_foco);
        lbl_foco_lejos->setObjectName(QStringLiteral("lbl_foco_lejos"));
        lbl_foco_lejos->setFont(font2);
        lbl_foco_lejos->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        lbl_foco_lejos->setAlignment(Qt::AlignCenter);

        layout_testigo_foco->addWidget(lbl_foco_lejos);

        lbl_foco_apagado = new QLabel(frame_testigo_foco);
        lbl_foco_apagado->setObjectName(QStringLiteral("lbl_foco_apagado"));
        lbl_foco_apagado->setFont(font2);
        lbl_foco_apagado->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_foco_apagado->setAlignment(Qt::AlignCenter);

        layout_testigo_foco->addWidget(lbl_foco_apagado);


        layout_lateral->addWidget(frame_testigo_foco);

        frame_testigo_video = new QFrame(panel_lateral);
        frame_testigo_video->setObjectName(QStringLiteral("frame_testigo_video"));
        frame_testigo_video->setFrameShape(QFrame::Box);
        layout_testigo_video = new QVBoxLayout(frame_testigo_video);
        layout_testigo_video->setSpacing(0);
        layout_testigo_video->setContentsMargins(11, 11, 11, 11);
        layout_testigo_video->setObjectName(QStringLiteral("layout_testigo_video"));
        layout_testigo_video->setContentsMargins(0, 0, 0, 0);
        lbl_video = new QLabel(frame_testigo_video);
        lbl_video->setObjectName(QStringLiteral("lbl_video"));
        lbl_video->setFont(font);
        lbl_video->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_video->setAlignment(Qt::AlignCenter);

        layout_testigo_video->addWidget(lbl_video);

        linea_testigo_video = new QFrame(frame_testigo_video);
        linea_testigo_video->setObjectName(QStringLiteral("linea_testigo_video"));
        linea_testigo_video->setFrameShadow(QFrame::Plain);
        linea_testigo_video->setFrameShape(QFrame::HLine);

        layout_testigo_video->addWidget(linea_testigo_video);

        lbl_video_cuantificado = new QLabel(frame_testigo_video);
        lbl_video_cuantificado->setObjectName(QStringLiteral("lbl_video_cuantificado"));
        lbl_video_cuantificado->setFont(font1);
        lbl_video_cuantificado->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 0);"));
        lbl_video_cuantificado->setAlignment(Qt::AlignCenter);

        layout_testigo_video->addWidget(lbl_video_cuantificado);

        lbl_video_diferenciado = new QLabel(frame_testigo_video);
        lbl_video_diferenciado->setObjectName(QStringLiteral("lbl_video_diferenciado"));
        lbl_video_diferenciado->setFont(font1);
        lbl_video_diferenciado->setStyleSheet(QStringLiteral("background-color: rgb(155, 196, 226);"));
        lbl_video_diferenciado->setAlignment(Qt::AlignCenter);

        layout_testigo_video->addWidget(lbl_video_diferenciado);

        lbl_video_normal = new QLabel(frame_testigo_video);
        lbl_video_normal->setObjectName(QStringLiteral("lbl_video_normal"));
        lbl_video_normal->setFont(font2);
        lbl_video_normal->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        lbl_video_normal->setAlignment(Qt::AlignCenter);

        layout_testigo_video->addWidget(lbl_video_normal);


        layout_lateral->addWidget(frame_testigo_video);

        frame_testigo_enganche = new QFrame(panel_lateral);
        frame_testigo_enganche->setObjectName(QStringLiteral("frame_testigo_enganche"));
        frame_testigo_enganche->setFrameShape(QFrame::Box);
        layout_testigo_enganche = new QVBoxLayout(frame_testigo_enganche);
        layout_testigo_enganche->setSpacing(0);
        layout_testigo_enganche->setContentsMargins(11, 11, 11, 11);
        layout_testigo_enganche->setObjectName(QStringLiteral("layout_testigo_enganche"));
        layout_testigo_enganche->setContentsMargins(0, 0, 0, 0);
        lbl_enganche = new QLabel(frame_testigo_enganche);
        lbl_enganche->setObjectName(QStringLiteral("lbl_enganche"));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setBold(true);
        font3.setWeight(75);
        lbl_enganche->setFont(font3);
        lbl_enganche->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_enganche->setAlignment(Qt::AlignCenter);

        layout_testigo_enganche->addWidget(lbl_enganche);

        linea_testigo_enganche = new QFrame(frame_testigo_enganche);
        linea_testigo_enganche->setObjectName(QStringLiteral("linea_testigo_enganche"));
        linea_testigo_enganche->setFrameShadow(QFrame::Plain);
        linea_testigo_enganche->setFrameShape(QFrame::HLine);

        layout_testigo_enganche->addWidget(linea_testigo_enganche);

        lbl_enganche_cuantificado = new QLabel(frame_testigo_enganche);
        lbl_enganche_cuantificado->setObjectName(QStringLiteral("lbl_enganche_cuantificado"));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        lbl_enganche_cuantificado->setFont(font4);
        lbl_enganche_cuantificado->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 0);"));
        lbl_enganche_cuantificado->setAlignment(Qt::AlignCenter);

        layout_testigo_enganche->addWidget(lbl_enganche_cuantificado);

        lbl_enganche_diferenciado = new QLabel(frame_testigo_enganche);
        lbl_enganche_diferenciado->setObjectName(QStringLiteral("lbl_enganche_diferenciado"));
        lbl_enganche_diferenciado->setFont(font4);
        lbl_enganche_diferenciado->setStyleSheet(QStringLiteral("background-color: rgb(155, 196, 226);"));
        lbl_enganche_diferenciado->setAlignment(Qt::AlignCenter);

        layout_testigo_enganche->addWidget(lbl_enganche_diferenciado);

        lbl_enganche_cuantificado_inv = new QLabel(frame_testigo_enganche);
        lbl_enganche_cuantificado_inv->setObjectName(QStringLiteral("lbl_enganche_cuantificado_inv"));
        lbl_enganche_cuantificado_inv->setFont(font4);
        lbl_enganche_cuantificado_inv->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(250, 250, 0);"));
        lbl_enganche_cuantificado_inv->setAlignment(Qt::AlignCenter);

        layout_testigo_enganche->addWidget(lbl_enganche_cuantificado_inv);


        layout_lateral->addWidget(frame_testigo_enganche);

        frame_testigo_modo = new QFrame(panel_lateral);
        frame_testigo_modo->setObjectName(QStringLiteral("frame_testigo_modo"));
        frame_testigo_modo->setFrameShape(QFrame::Box);
        layout_testigo_modo = new QVBoxLayout(frame_testigo_modo);
        layout_testigo_modo->setSpacing(0);
        layout_testigo_modo->setContentsMargins(11, 11, 11, 11);
        layout_testigo_modo->setObjectName(QStringLiteral("layout_testigo_modo"));
        layout_testigo_modo->setContentsMargins(0, 0, 0, 0);
        lbl_modo = new QLabel(frame_testigo_modo);
        lbl_modo->setObjectName(QStringLiteral("lbl_modo"));
        lbl_modo->setFont(font);
        lbl_modo->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_modo->setAlignment(Qt::AlignCenter);

        layout_testigo_modo->addWidget(lbl_modo);

        linea_testigo_modo = new QFrame(frame_testigo_modo);
        linea_testigo_modo->setObjectName(QStringLiteral("linea_testigo_modo"));
        linea_testigo_modo->setFrameShadow(QFrame::Plain);
        linea_testigo_modo->setLineWidth(1);
        linea_testigo_modo->setFrameShape(QFrame::HLine);

        layout_testigo_modo->addWidget(linea_testigo_modo);

        lbl_modo_fijo = new QLabel(frame_testigo_modo);
        lbl_modo_fijo->setObjectName(QStringLiteral("lbl_modo_fijo"));
        lbl_modo_fijo->setFont(font1);
        lbl_modo_fijo->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 0);"));
        lbl_modo_fijo->setAlignment(Qt::AlignCenter);

        layout_testigo_modo->addWidget(lbl_modo_fijo);

        lbl_modo_esclavo = new QLabel(frame_testigo_modo);
        lbl_modo_esclavo->setObjectName(QStringLiteral("lbl_modo_esclavo"));
        lbl_modo_esclavo->setFont(font1);
        lbl_modo_esclavo->setStyleSheet(QStringLiteral("background-color: rgb(155, 196, 226);"));
        lbl_modo_esclavo->setAlignment(Qt::AlignCenter);

        layout_testigo_modo->addWidget(lbl_modo_esclavo);

        lbl_modo_estable = new QLabel(frame_testigo_modo);
        lbl_modo_estable->setObjectName(QStringLiteral("lbl_modo_estable"));
        lbl_modo_estable->setFont(font1);
        lbl_modo_estable->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        lbl_modo_estable->setAlignment(Qt::AlignCenter);

        layout_testigo_modo->addWidget(lbl_modo_estable);


        layout_lateral->addWidget(frame_testigo_modo);

        panel_superior = new QWidget(panel_central);
        panel_superior->setObjectName(QStringLiteral("panel_superior"));
        panel_superior->setGeometry(QRect(220, 10, 610, 80));
        layout_superior = new QHBoxLayout(panel_superior);
        layout_superior->setSpacing(6);
        layout_superior->setContentsMargins(11, 11, 11, 11);
        layout_superior->setObjectName(QStringLiteral("layout_superior"));
        layout_superior->setContentsMargins(0, 0, 0, 0);
        frame_referencia_estab = new QFrame(panel_superior);
        frame_referencia_estab->setObjectName(QStringLiteral("frame_referencia_estab"));
        frame_referencia_estab->setFrameShape(QFrame::Box);
        layout_referencia_estab = new QVBoxLayout(frame_referencia_estab);
        layout_referencia_estab->setSpacing(0);
        layout_referencia_estab->setContentsMargins(11, 11, 11, 11);
        layout_referencia_estab->setObjectName(QStringLiteral("layout_referencia_estab"));
        layout_referencia_estab->setContentsMargins(0, 0, 0, 0);
        lbl_referencia_estab = new QLabel(frame_referencia_estab);
        lbl_referencia_estab->setObjectName(QStringLiteral("lbl_referencia_estab"));
        lbl_referencia_estab->setFont(font);
        lbl_referencia_estab->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_referencia_estab->setAlignment(Qt::AlignCenter);

        layout_referencia_estab->addWidget(lbl_referencia_estab);

        linea_referencia_estable = new QFrame(frame_referencia_estab);
        linea_referencia_estable->setObjectName(QStringLiteral("linea_referencia_estable"));
        linea_referencia_estable->setFrameShadow(QFrame::Plain);
        linea_referencia_estable->setFrameShape(QFrame::HLine);

        layout_referencia_estab->addWidget(linea_referencia_estable);

        lbl_imu_prob = new QLabel(frame_referencia_estab);
        lbl_imu_prob->setObjectName(QStringLiteral("lbl_imu_prob"));
        lbl_imu_prob->setFont(font1);
        lbl_imu_prob->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_imu_prob->setAlignment(Qt::AlignCenter);

        layout_referencia_estab->addWidget(lbl_imu_prob);

        lbl_octans = new QLabel(frame_referencia_estab);
        lbl_octans->setObjectName(QStringLiteral("lbl_octans"));
        lbl_octans->setFont(font1);
        lbl_octans->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 0);"));
        lbl_octans->setAlignment(Qt::AlignCenter);

        layout_referencia_estab->addWidget(lbl_octans);


        layout_superior->addWidget(frame_referencia_estab);

        frame_enganche = new QFrame(panel_superior);
        frame_enganche->setObjectName(QStringLiteral("frame_enganche"));
        frame_enganche->setFrameShape(QFrame::Box);
        layout_enganche = new QVBoxLayout(frame_enganche);
        layout_enganche->setSpacing(0);
        layout_enganche->setContentsMargins(11, 11, 11, 11);
        layout_enganche->setObjectName(QStringLiteral("layout_enganche"));
        layout_enganche->setContentsMargins(0, 0, 0, 0);
        lbl_enganche_etiqueta = new QLabel(frame_enganche);
        lbl_enganche_etiqueta->setObjectName(QStringLiteral("lbl_enganche_etiqueta"));
        lbl_enganche_etiqueta->setFont(font2);
        lbl_enganche_etiqueta->setAutoFillBackground(false);
        lbl_enganche_etiqueta->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_enganche_etiqueta->setAlignment(Qt::AlignCenter);

        layout_enganche->addWidget(lbl_enganche_etiqueta);

        linea_enganche_prediccion = new QFrame(frame_enganche);
        linea_enganche_prediccion->setObjectName(QStringLiteral("linea_enganche_prediccion"));
        linea_enganche_prediccion->setFrameShadow(QFrame::Plain);
        linea_enganche_prediccion->setFrameShape(QFrame::HLine);

        layout_enganche->addWidget(linea_enganche_prediccion);

        lbl_prediccion = new QLabel(frame_enganche);
        lbl_prediccion->setObjectName(QStringLiteral("lbl_prediccion"));
        lbl_prediccion->setFont(font1);
        lbl_prediccion->setAutoFillBackground(false);
        lbl_prediccion->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_prediccion->setAlignment(Qt::AlignCenter);

        layout_enganche->addWidget(lbl_prediccion);


        layout_superior->addWidget(frame_enganche);

        frame_datos_plataforma = new QFrame(panel_superior);
        frame_datos_plataforma->setObjectName(QStringLiteral("frame_datos_plataforma"));
        frame_datos_plataforma->setFont(font4);
        frame_datos_plataforma->setStyleSheet(QStringLiteral(""));
        frame_datos_plataforma->setFrameShape(QFrame::Box);
        frame_datos_plataforma->setFrameShadow(QFrame::Plain);
        frame_datos_plataforma->setLineWidth(0);
        frame_datos_plataforma->setMidLineWidth(0);
        layout_datos_plataforma = new QGridLayout(frame_datos_plataforma);
        layout_datos_plataforma->setSpacing(0);
        layout_datos_plataforma->setContentsMargins(11, 11, 11, 11);
        layout_datos_plataforma->setObjectName(QStringLiteral("layout_datos_plataforma"));
        layout_datos_plataforma->setContentsMargins(0, 0, 0, 0);
        lbl_datos_plataforma = new QLabel(frame_datos_plataforma);
        lbl_datos_plataforma->setObjectName(QStringLiteral("lbl_datos_plataforma"));
        lbl_datos_plataforma->setFont(font);
        lbl_datos_plataforma->setAutoFillBackground(false);
        lbl_datos_plataforma->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_datos_plataforma->setFrameShape(QFrame::Box);
        lbl_datos_plataforma->setAlignment(Qt::AlignCenter);

        layout_datos_plataforma->addWidget(lbl_datos_plataforma, 0, 0, 1, 2);

        lbl_azimut_valor = new QLabel(frame_datos_plataforma);
        lbl_azimut_valor->setObjectName(QStringLiteral("lbl_azimut_valor"));
        lbl_azimut_valor->setFont(font1);
        lbl_azimut_valor->setAutoFillBackground(false);
        lbl_azimut_valor->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_azimut_valor->setFrameShape(QFrame::Box);
        lbl_azimut_valor->setAlignment(Qt::AlignCenter);
        lbl_azimut_valor->setWordWrap(false);

        layout_datos_plataforma->addWidget(lbl_azimut_valor, 2, 0, 1, 1);

        lbl_elevacion_valor = new QLabel(frame_datos_plataforma);
        lbl_elevacion_valor->setObjectName(QStringLiteral("lbl_elevacion_valor"));
        lbl_elevacion_valor->setFont(font1);
        lbl_elevacion_valor->setAutoFillBackground(false);
        lbl_elevacion_valor->setStyleSheet(QLatin1String("border: 1px solid black;\n"
"border-left: 0px;\n"
"background-color: rgb(255, 255, 255);"));
        lbl_elevacion_valor->setFrameShape(QFrame::NoFrame);
        lbl_elevacion_valor->setAlignment(Qt::AlignCenter);

        layout_datos_plataforma->addWidget(lbl_elevacion_valor, 2, 1, 1, 1);

        lbl_elevacion = new QLabel(frame_datos_plataforma);
        lbl_elevacion->setObjectName(QStringLiteral("lbl_elevacion"));
        lbl_elevacion->setFont(font);
        lbl_elevacion->setAutoFillBackground(false);
        lbl_elevacion->setStyleSheet(QLatin1String("border: 1px solid black;\n"
"border-left: 0px;\n"
"border-top: 0px;\n"
"border-bottom: 0px;\n"
"background-color: rgb(255, 255, 255);"));
        lbl_elevacion->setFrameShape(QFrame::NoFrame);
        lbl_elevacion->setFrameShadow(QFrame::Plain);
        lbl_elevacion->setMidLineWidth(0);
        lbl_elevacion->setAlignment(Qt::AlignCenter);

        layout_datos_plataforma->addWidget(lbl_elevacion, 1, 1, 1, 1);

        lbl_azimut = new QLabel(frame_datos_plataforma);
        lbl_azimut->setObjectName(QStringLiteral("lbl_azimut"));
        lbl_azimut->setFont(font);
        lbl_azimut->setAutoFillBackground(false);
        lbl_azimut->setStyleSheet(QLatin1String("border: 1px solid black;\n"
"border-top: 0px;\n"
"border-bottom: 0px;\n"
"background-color: rgb(255, 255, 255);\n"
""));
        lbl_azimut->setFrameShape(QFrame::NoFrame);
        lbl_azimut->setAlignment(Qt::AlignCenter);

        layout_datos_plataforma->addWidget(lbl_azimut, 1, 0, 1, 1);


        layout_superior->addWidget(frame_datos_plataforma);

        frame_datos_gps = new QFrame(panel_superior);
        frame_datos_gps->setObjectName(QStringLiteral("frame_datos_gps"));
        frame_datos_gps->setStyleSheet(QStringLiteral(""));
        frame_datos_gps->setFrameShape(QFrame::NoFrame);
        frame_datos_gps->setLineWidth(1);
        frame_datos_gps->setMidLineWidth(0);
        layout_datos_gps = new QGridLayout(frame_datos_gps);
        layout_datos_gps->setSpacing(0);
        layout_datos_gps->setContentsMargins(11, 11, 11, 11);
        layout_datos_gps->setObjectName(QStringLiteral("layout_datos_gps"));
        layout_datos_gps->setContentsMargins(0, 0, 0, 0);
        lbl_longitud = new QLabel(frame_datos_gps);
        lbl_longitud->setObjectName(QStringLiteral("lbl_longitud"));
        lbl_longitud->setFont(font);
        lbl_longitud->setAutoFillBackground(false);
        lbl_longitud->setStyleSheet(QLatin1String("border: 1px solid black;\n"
"border-top: 0px;\n"
"border-bottom: 0px;\n"
"background-color: rgb(255, 255, 255);"));
        lbl_longitud->setFrameShape(QFrame::NoFrame);
        lbl_longitud->setAlignment(Qt::AlignCenter);

        layout_datos_gps->addWidget(lbl_longitud, 1, 0, 1, 1);

        lbl_latitud = new QLabel(frame_datos_gps);
        lbl_latitud->setObjectName(QStringLiteral("lbl_latitud"));
        lbl_latitud->setFont(font);
        lbl_latitud->setAutoFillBackground(false);
        lbl_latitud->setStyleSheet(QLatin1String("border: 1px solid black;\n"
"border-left: 0px;\n"
"border-top: 0px;\n"
"border-bottom: 0px;\n"
"background-color: rgb(255, 255, 255);"));
        lbl_latitud->setFrameShape(QFrame::NoFrame);
        lbl_latitud->setAlignment(Qt::AlignCenter);

        layout_datos_gps->addWidget(lbl_latitud, 1, 1, 1, 1);

        lbl_latitud_valor = new QLabel(frame_datos_gps);
        lbl_latitud_valor->setObjectName(QStringLiteral("lbl_latitud_valor"));
        lbl_latitud_valor->setFont(font1);
        lbl_latitud_valor->setAutoFillBackground(false);
        lbl_latitud_valor->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border: 1px solid black;\n"
"border-left: 0px;"));
        lbl_latitud_valor->setFrameShape(QFrame::NoFrame);
        lbl_latitud_valor->setAlignment(Qt::AlignCenter);

        layout_datos_gps->addWidget(lbl_latitud_valor, 2, 1, 1, 1);

        lbl_datos_gps = new QLabel(frame_datos_gps);
        lbl_datos_gps->setObjectName(QStringLiteral("lbl_datos_gps"));
        lbl_datos_gps->setFont(font);
        lbl_datos_gps->setAutoFillBackground(false);
        lbl_datos_gps->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_datos_gps->setFrameShape(QFrame::Box);
        lbl_datos_gps->setAlignment(Qt::AlignCenter);

        layout_datos_gps->addWidget(lbl_datos_gps, 0, 0, 1, 2);

        lbl_longitud_valor = new QLabel(frame_datos_gps);
        lbl_longitud_valor->setObjectName(QStringLiteral("lbl_longitud_valor"));
        lbl_longitud_valor->setFont(font1);
        lbl_longitud_valor->setAutoFillBackground(false);
        lbl_longitud_valor->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_longitud_valor->setFrameShape(QFrame::Box);
        lbl_longitud_valor->setAlignment(Qt::AlignCenter);

        layout_datos_gps->addWidget(lbl_longitud_valor, 2, 0, 1, 1);


        layout_superior->addWidget(frame_datos_gps);

        frame_datos_blanco = new QFrame(panel_superior);
        frame_datos_blanco->setObjectName(QStringLiteral("frame_datos_blanco"));
        frame_datos_blanco->setFrameShape(QFrame::NoFrame);
        layout_datos_blanco = new QGridLayout(frame_datos_blanco);
        layout_datos_blanco->setSpacing(0);
        layout_datos_blanco->setContentsMargins(11, 11, 11, 11);
        layout_datos_blanco->setObjectName(QStringLiteral("layout_datos_blanco"));
        layout_datos_blanco->setContentsMargins(0, 0, 0, 0);
        lbl_datos_blanco = new QLabel(frame_datos_blanco);
        lbl_datos_blanco->setObjectName(QStringLiteral("lbl_datos_blanco"));
        lbl_datos_blanco->setFont(font);
        lbl_datos_blanco->setAutoFillBackground(false);
        lbl_datos_blanco->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_datos_blanco->setFrameShape(QFrame::Box);
        lbl_datos_blanco->setAlignment(Qt::AlignCenter);

        layout_datos_blanco->addWidget(lbl_datos_blanco, 0, 0, 1, 2);

        lbl_distancia_valor = new QLabel(frame_datos_blanco);
        lbl_distancia_valor->setObjectName(QStringLiteral("lbl_distancia_valor"));
        lbl_distancia_valor->setFont(font1);
        lbl_distancia_valor->setAutoFillBackground(false);
        lbl_distancia_valor->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_distancia_valor->setFrameShape(QFrame::Box);
        lbl_distancia_valor->setAlignment(Qt::AlignCenter);

        layout_datos_blanco->addWidget(lbl_distancia_valor, 2, 0, 1, 1);

        lbl_velocidad = new QLabel(frame_datos_blanco);
        lbl_velocidad->setObjectName(QStringLiteral("lbl_velocidad"));
        lbl_velocidad->setFont(font);
        lbl_velocidad->setAutoFillBackground(false);
        lbl_velocidad->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border: 1px solid black;\n"
"border-left: 0px;\n"
"border-top: 0px;\n"
"border-bottom: 0px;"));
        lbl_velocidad->setFrameShape(QFrame::NoFrame);
        lbl_velocidad->setAlignment(Qt::AlignCenter);

        layout_datos_blanco->addWidget(lbl_velocidad, 1, 1, 1, 1);

        lbl_distancia = new QLabel(frame_datos_blanco);
        lbl_distancia->setObjectName(QStringLiteral("lbl_distancia"));
        lbl_distancia->setFont(font);
        lbl_distancia->setAutoFillBackground(false);
        lbl_distancia->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border: 1px solid black;\n"
"border-top: 0px;\n"
"border-bottom: 0px;\n"
""));
        lbl_distancia->setFrameShape(QFrame::NoFrame);
        lbl_distancia->setAlignment(Qt::AlignCenter);

        layout_datos_blanco->addWidget(lbl_distancia, 1, 0, 1, 1);

        lbl_velocidad_valor = new QLabel(frame_datos_blanco);
        lbl_velocidad_valor->setObjectName(QStringLiteral("lbl_velocidad_valor"));
        lbl_velocidad_valor->setFont(font1);
        lbl_velocidad_valor->setAutoFillBackground(false);
        lbl_velocidad_valor->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border: 1px solid black;\n"
"border-left: 0px;"));
        lbl_velocidad_valor->setFrameShape(QFrame::NoFrame);
        lbl_velocidad_valor->setAlignment(Qt::AlignCenter);

        layout_datos_blanco->addWidget(lbl_velocidad_valor, 2, 1, 1, 1);


        layout_superior->addWidget(frame_datos_blanco);

        widget_datos_radar = new QWidget(panel_central);
        widget_datos_radar->setObjectName(QStringLiteral("widget_datos_radar"));
        widget_datos_radar->setGeometry(QRect(520, 390, 300, 80));
        QPalette palette;
        QBrush brush(QColor(85, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        widget_datos_radar->setPalette(palette);
        widget_datos_radar->setAutoFillBackground(false);
        widget_datos_radar->setStyleSheet(QLatin1String("font: 14pt \"Arial\";\n"
"color: rgb(85, 170, 0);\n"
"border: 1px solid rgb(85, 170, 0);"));
        layout_datos_radar = new QGridLayout(widget_datos_radar);
        layout_datos_radar->setSpacing(0);
        layout_datos_radar->setContentsMargins(11, 11, 11, 11);
        layout_datos_radar->setObjectName(QStringLiteral("layout_datos_radar"));
        layout_datos_radar->setContentsMargins(0, 0, 0, 0);
        lbl_dist = new QLabel(widget_datos_radar);
        lbl_dist->setObjectName(QStringLiteral("lbl_dist"));
        QFont font5;
        font5.setFamily(QStringLiteral("Arial"));
        font5.setPointSize(14);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        lbl_dist->setFont(font5);
        lbl_dist->setStyleSheet(QStringLiteral(""));
        lbl_dist->setAlignment(Qt::AlignCenter);

        layout_datos_radar->addWidget(lbl_dist, 0, 0, 1, 1);

        lbl_azimut_radar = new QLabel(widget_datos_radar);
        lbl_azimut_radar->setObjectName(QStringLiteral("lbl_azimut_radar"));
        lbl_azimut_radar->setFont(font5);
        lbl_azimut_radar->setStyleSheet(QStringLiteral(""));
        lbl_azimut_radar->setAlignment(Qt::AlignCenter);

        layout_datos_radar->addWidget(lbl_azimut_radar, 0, 1, 1, 1);

        lbl_dist_valor = new QLabel(widget_datos_radar);
        lbl_dist_valor->setObjectName(QStringLiteral("lbl_dist_valor"));
        lbl_dist_valor->setFont(font5);
        lbl_dist_valor->setAlignment(Qt::AlignCenter);

        layout_datos_radar->addWidget(lbl_dist_valor, 1, 0, 1, 1);

        lbl_tipo = new QLabel(widget_datos_radar);
        lbl_tipo->setObjectName(QStringLiteral("lbl_tipo"));
        lbl_tipo->setFont(font5);
        lbl_tipo->setAlignment(Qt::AlignCenter);

        layout_datos_radar->addWidget(lbl_tipo, 0, 2, 1, 1);

        lbl_azimut_radar_valor = new QLabel(widget_datos_radar);
        lbl_azimut_radar_valor->setObjectName(QStringLiteral("lbl_azimut_radar_valor"));
        lbl_azimut_radar_valor->setFont(font5);
        lbl_azimut_radar_valor->setAlignment(Qt::AlignCenter);

        layout_datos_radar->addWidget(lbl_azimut_radar_valor, 1, 1, 1, 1);

        lbl_tipo_valor = new QLabel(widget_datos_radar);
        lbl_tipo_valor->setObjectName(QStringLiteral("lbl_tipo_valor"));
        lbl_tipo_valor->setFont(font5);
        lbl_tipo_valor->setAlignment(Qt::AlignCenter);

        layout_datos_radar->addWidget(lbl_tipo_valor, 1, 2, 1, 1);

        consola_seonClass->setCentralWidget(panel_central);

        retranslateUi(consola_seonClass);

        QMetaObject::connectSlotsByName(consola_seonClass);
    } // setupUi

    void retranslateUi(QMainWindow *consola_seonClass)
    {
        consola_seonClass->setWindowTitle(QApplication::translate("consola_seonClass", "consola_seon", nullptr));
        lbl_pantalla->setText(QApplication::translate("consola_seonClass", "PANTALLA", nullptr));
        lbl_pantalla_datos->setText(QApplication::translate("consola_seonClass", "DATOS", nullptr));
        lbl_pantalla_barrido->setText(QApplication::translate("consola_seonClass", "BARRIDO", nullptr));
        lbl_pantalla_normal->setText(QApplication::translate("consola_seonClass", "NORMAL", nullptr));
        lbl_ventana_optica->setText(QApplication::translate("consola_seonClass", "VENTANA \303\223PTICA", nullptr));
        lbl_optica_apagada_lava->setText(QApplication::translate("consola_seonClass", "LAVA", nullptr));
        lbl_optica_lava->setText(QApplication::translate("consola_seonClass", "LAVA", nullptr));
        lbl_optica_apagada_limpia->setText(QApplication::translate("consola_seonClass", "LIMPIA", nullptr));
        lbl_optica_limpia->setText(QApplication::translate("consola_seonClass", "LIMPIA", nullptr));
        lbl_camara->setText(QApplication::translate("consola_seonClass", "C\303\201MARA", nullptr));
        lbl_camara_diurna->setText(QApplication::translate("consola_seonClass", "IR", nullptr));
        lbl_camara_ir->setText(QApplication::translate("consola_seonClass", "DIURNA", nullptr));
        lbl_zoom->setText(QApplication::translate("consola_seonClass", "ZOOM", nullptr));
        lbl_zoom_valor->setText(QApplication::translate("consola_seonClass", "APAGADO", nullptr));
        lbl_foco->setText(QApplication::translate("consola_seonClass", "FOCO", nullptr));
        lbl_foco_cerca->setText(QApplication::translate("consola_seonClass", "CERCA", nullptr));
        lbl_foco_lejos->setText(QApplication::translate("consola_seonClass", "LEJOS", nullptr));
        lbl_foco_apagado->setText(QApplication::translate("consola_seonClass", "APAGADO", nullptr));
        lbl_video->setText(QApplication::translate("consola_seonClass", "VIDEO", nullptr));
        lbl_video_cuantificado->setText(QApplication::translate("consola_seonClass", "CUANTIFICADO", nullptr));
        lbl_video_diferenciado->setText(QApplication::translate("consola_seonClass", "DIFERENCIADO", nullptr));
        lbl_video_normal->setText(QApplication::translate("consola_seonClass", "NORMAL", nullptr));
        lbl_enganche->setText(QApplication::translate("consola_seonClass", "ENGANCHE", nullptr));
        lbl_enganche_cuantificado->setText(QApplication::translate("consola_seonClass", "CUANTIFICADO", nullptr));
        lbl_enganche_diferenciado->setText(QApplication::translate("consola_seonClass", "DIFERENCIADO", nullptr));
        lbl_enganche_cuantificado_inv->setText(QApplication::translate("consola_seonClass", "CUANTIFICADO INV.", nullptr));
        lbl_modo->setText(QApplication::translate("consola_seonClass", "MODO", nullptr));
        lbl_modo_fijo->setText(QApplication::translate("consola_seonClass", "FIJO", nullptr));
        lbl_modo_esclavo->setText(QApplication::translate("consola_seonClass", "ESCLAVO", nullptr));
        lbl_modo_estable->setText(QApplication::translate("consola_seonClass", "ESTABLE", nullptr));
        lbl_referencia_estab->setText(QApplication::translate("consola_seonClass", "REFERENCIA ESTAB", nullptr));
        lbl_imu_prob->setText(QApplication::translate("consola_seonClass", "IMU PROP.", nullptr));
        lbl_octans->setText(QApplication::translate("consola_seonClass", "OCTANS", nullptr));
        lbl_enganche_etiqueta->setText(QApplication::translate("consola_seonClass", "ENGANCHE", nullptr));
        lbl_prediccion->setText(QApplication::translate("consola_seonClass", "PREDICCI\303\223N", nullptr));
        lbl_datos_plataforma->setText(QApplication::translate("consola_seonClass", "DATOS PLATAFORMA", nullptr));
        lbl_azimut_valor->setText(QApplication::translate("consola_seonClass", "valor_azimut", nullptr));
        lbl_elevacion_valor->setText(QApplication::translate("consola_seonClass", "valor_elevacion", nullptr));
        lbl_elevacion->setText(QApplication::translate("consola_seonClass", "ELEVACI\303\223N", nullptr));
        lbl_azimut->setText(QApplication::translate("consola_seonClass", "AZIMUT", nullptr));
        lbl_longitud->setText(QApplication::translate("consola_seonClass", "LONGITUD", nullptr));
        lbl_latitud->setText(QApplication::translate("consola_seonClass", "LATITUD", nullptr));
        lbl_latitud_valor->setText(QApplication::translate("consola_seonClass", "valor_latitud", nullptr));
        lbl_datos_gps->setText(QApplication::translate("consola_seonClass", "DATOS GPS", nullptr));
        lbl_longitud_valor->setText(QApplication::translate("consola_seonClass", "valor_longitud", nullptr));
        lbl_datos_blanco->setText(QApplication::translate("consola_seonClass", "DATOS BLANCO", nullptr));
        lbl_distancia_valor->setText(QApplication::translate("consola_seonClass", "valor_distancia", nullptr));
        lbl_velocidad->setText(QApplication::translate("consola_seonClass", "VELOCIDAD", nullptr));
        lbl_distancia->setText(QApplication::translate("consola_seonClass", "DISTANCIA", nullptr));
        lbl_velocidad_valor->setText(QApplication::translate("consola_seonClass", "valor_velocidad", nullptr));
        lbl_dist->setText(QApplication::translate("consola_seonClass", "DIST", nullptr));
        lbl_azimut_radar->setText(QApplication::translate("consola_seonClass", "AZIMUT", nullptr));
        lbl_dist_valor->setText(QApplication::translate("consola_seonClass", "0.00 y", nullptr));
        lbl_tipo->setText(QApplication::translate("consola_seonClass", "TIPO", nullptr));
        lbl_azimut_radar_valor->setText(QApplication::translate("consola_seonClass", "0.0 \302\260", nullptr));
        lbl_tipo_valor->setText(QApplication::translate("consola_seonClass", "A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class consola_seonClass: public Ui_consola_seonClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLA_SEON_H
