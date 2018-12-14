/********************************************************************************
** Form generated from reading UI file 'simuladorcomu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULADORCOMU_H
#define UI_SIMULADORCOMU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simuladorcomuClass
{
public:
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout;
    QWidget *widget_puerto_seon;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QFrame *line;
    QLabel *label_3;
    QLineEdit *lineedit_puerto_seon;
    QPushButton *btn_conectar_seon;
    QWidget *form_seon;
    QFormLayout *from_seon;
    QLabel *lbl_header1_seon;
    QLineEdit *lineedit_header1_seon;
    QLabel *lbl_header_seon;
    QLineEdit *lineedit_header2_seon;
    QLabel *lbl_distancia;
    QSpinBox *spin_distancia;
    QLabel *lbl_origen_dato;
    QGroupBox *groupbox_origen_dato;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radiobut_origen_dato_0;
    QRadioButton *radiobut_origen_dato_1;
    QRadioButton *radiobut_origen_dato_2;
    QLabel *lbl_modo_pred;
    QGroupBox *groupbox_modo_pred;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radiobut_modo_pred_0;
    QRadioButton *radiobut_modo_pred_1;
    QLabel *lbl_velocidad;
    QSpinBox *spin_velocidad;
    QLabel *lbl_zoom;
    QSpinBox *spin_zoom;
    QLabel *lbl_radar_act;
    QCheckBox *checkbox_radar_acti;
    QLabel *lbl_header2_seon;
    QLabel *lbl_azimut_radar;
    QWidget *horizontalWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spin_azimut_radar_entero;
    QLabel *label_4;
    QSpinBox *spin_azimut_radar_decimal;
    QLabel *lbl_dist_radar;
    QSpinBox *spin_distancia_radar;
    QLabel *lbl_azimut_graf;
    QSpinBox *spin_azimut_graf;
    QLabel *lbl_elevacion_graf;
    QSpinBox *spin_elevacion_graf;
    QLabel *lbl_azimut_abs;
    QWidget *horizontalWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spin_azimut_abs_entero;
    QLabel *label_2;
    QSpinBox *spin_azimut_abs_decimal;
    QLabel *lbl_elevacion_abs;
    QWidget *horizontalWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *spin_elevacion_abs_entero;
    QLabel *label;
    QSpinBox *spin_elevacion_abs_decimal;
    QLabel *lbl_centro_grav;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QSpinBox *spin_centro_gravedad_x;
    QLabel *label_11;
    QSpinBox *spin_centro_gravedad_y;
    QLabel *lbl_corrimiento;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spin_corrimiento_x;
    QSpinBox *spin_corrimiento_y;
    QGroupBox *groupbox_tipo_blanco;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *radiobut_tipo_s;
    QRadioButton *radiobut_tipo_a;
    QRadioButton *radiobut_tipo_y;
    QRadioButton *radiobut_tipo_t;
    QRadioButton *radiobut_tipo_u;
    QPushButton *btn_enviar_seon;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_puerto_botonera;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QFrame *line_2;
    QLabel *label_6;
    QLineEdit *lineedit_puerto_botonera;
    QPushButton *btn_conectar_botonera;
    QWidget *form_botonera;
    QFormLayout *layout_botonera;
    QLabel *lbl_header1;
    QLineEdit *lineedit_header1_botonera;
    QLabel *lbl_header2;
    QLineEdit *lineedit_header2_botonera;
    QLabel *lbl_contador;
    QLabel *lbl_ref_est;
    QCheckBox *checkbox_ref_est;
    QLabel *lbl_pant_datos;
    QCheckBox *checkbox_pant_datos;
    QLabel *lbl_pant_barrido;
    QCheckBox *checkbox_pant_barrido;
    QLabel *lbl_pant_normal;
    QLabel *lbl_vent_opt_lav;
    QCheckBox *checkbox_vent_opt_lav;
    QLabel *lbl_vent_opt_llimp;
    QCheckBox *checkbox_vent_opt_limp;
    QLabel *lbl_pa_ir;
    QCheckBox *checkbox_pa_ir;
    QLabel *lbl_cam_ir;
    QCheckBox *checkbox_cam_ir;
    QLabel *lbl_cam_diu;
    QCheckBox *checkbox_cam_diu;
    QLabel *lbl_zoom_amp;
    QCheckBox *checkbox_zoom_amp;
    QLabel *lbl_zoom_est;
    QCheckBox *checkbox_zoom_est;
    QLabel *lbl_foco_cerca;
    QCheckBox *checkbox_foco_cerca;
    QLabel *lbl_foco_lejos;
    QCheckBox *checkbox_foco_lejos;
    QLabel *lbl_video_cuant;
    QLabel *lbl_video_dif;
    QLabel *lbl_video_nor;
    QLabel *lbl_eng_cuant;
    QLabel *lbl_eng_dif;
    QLabel *lbl_mod_fij;
    QLabel *lbl_mod_esc;
    QLabel *lbl_mod_est;
    QCheckBox *checkbox_video_cuant;
    QCheckBox *checkbox_video_dif;
    QCheckBox *checkbox_video_nor;
    QCheckBox *checkbox_eng_cuant;
    QCheckBox *checkbox_eng_dif;
    QCheckBox *checkbox_mod_fij;
    QCheckBox *checkbox_mod_esc;
    QCheckBox *checkbox_mod_est;
    QCheckBox *checkbox_pant_normal;
    QSpinBox *spin_contador_botonera;
    QPushButton *btn_enviar_botonera;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_puerto_pupitre;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QFrame *line_3;
    QLabel *label_5;
    QLineEdit *lineedit_puerto_pupitre;
    QPushButton *btn_conectar_pupitre;
    QWidget *form_pupitre;
    QFormLayout *layout_pupitre;
    QLabel *lbl_header1_pupitre;
    QLineEdit *lineedit_header1_pupitre;
    QLabel *lbl_header2_2;
    QLabel *lbl_contador1;
    QLabel *lbl_arrp;
    QLabel *lbl_eng_desen_pic;
    QLabel *lbl_boton2;
    QLabel *lbl_boton3;
    QLabel *lbl_graba_pic;
    QLabel *lbl_acc_arch;
    QLabel *lbl_sel_vent1;
    QLabel *lbl_sel_vent2;
    QLabel *lbl_sen_fija;
    QLineEdit *lineedit_header2_2;
    QCheckBox *checkbox_arrp;
    QCheckBox *checkbox_eng_desen_pic;
    QCheckBox *checkbox_boton2;
    QCheckBox *checkbox_boton3;
    QCheckBox *checkbox_graba_pic;
    QCheckBox *checkbox_acc_arch;
    QCheckBox *checkbox_sel_vent1;
    QCheckBox *checkbox_sel_vent2;
    QCheckBox *checkbox_sen_fija;
    QSpinBox *spin_contador_pupitre;
    QPushButton *btn_enviar_pupitre;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_puerto_gps;
    QHBoxLayout *layout_puerto_gps;
    QLabel *lbl_gps;
    QFrame *line_4;
    QLabel *lbl_puerto_gps;
    QLineEdit *lineedit_puerto_gps;
    QPushButton *btn_conectar_gps;
    QWidget *form_gps;
    QFormLayout *formLayout;
    QLabel *lbl_hora;
    QLabel *lbl_estado_gps;
    QGroupBox *groupbox_estado_gps;
    QHBoxLayout *horizontalLayout_13;
    QRadioButton *radiobut_active_gps;
    QRadioButton *radiobut_void_gps;
    QLabel *lbl_latitud;
    QHBoxLayout *horizontalLayout_14;
    QSpinBox *spinbox_latitud_gps;
    QDoubleSpinBox *spinbox_latitud_deg_gps;
    QGroupBox *groupbox_latitud_gps;
    QHBoxLayout *horizontalLayout_15;
    QRadioButton *radiobut_latidud_gps_n;
    QRadioButton *radiobut_latidud_gps_s;
    QLabel *lbl_longitud;
    QHBoxLayout *horizontalLayout_16;
    QSpinBox *spinbox_longitud_gps;
    QDoubleSpinBox *spinbox_longitud_deg_gps;
    QGroupBox *groupbox_longitud_gps;
    QHBoxLayout *horizontalLayout_18;
    QRadioButton *radiobut_longitud_gps_w;
    QRadioButton *radiobut_longitud_gps_e;
    QLabel *lbl_nudos_gps;
    QLabel *label_13;
    QLabel *lbl_grados_gps;
    QLabel *label_14;
    QLabel *lbl_fecha_gps;
    QLabel *label_15;
    QLabel *label_12;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_19;
    QSpinBox *spinbox_horas_gps;
    QSpinBox *spinbox_minutos_gps;
    QSpinBox *spinbox_segundos_gps;
    QPushButton *btn_enviar_gps;

    void setupUi(QWidget *simuladorcomuClass)
    {
        if (simuladorcomuClass->objectName().isEmpty())
            simuladorcomuClass->setObjectName(QStringLiteral("simuladorcomuClass"));
        simuladorcomuClass->resize(1112, 751);
        horizontalLayout_11 = new QHBoxLayout(simuladorcomuClass);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_puerto_seon = new QWidget(simuladorcomuClass);
        widget_puerto_seon->setObjectName(QStringLiteral("widget_puerto_seon"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_puerto_seon->sizePolicy().hasHeightForWidth());
        widget_puerto_seon->setSizePolicy(sizePolicy);
        horizontalLayout_8 = new QHBoxLayout(widget_puerto_seon);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget_puerto_seon);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font;
        font.setPointSize(18);
        label_7->setFont(font);

        horizontalLayout_8->addWidget(label_7);

        line = new QFrame(widget_puerto_seon);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line);

        label_3 = new QLabel(widget_puerto_seon);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_8->addWidget(label_3);

        lineedit_puerto_seon = new QLineEdit(widget_puerto_seon);
        lineedit_puerto_seon->setObjectName(QStringLiteral("lineedit_puerto_seon"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineedit_puerto_seon->sizePolicy().hasHeightForWidth());
        lineedit_puerto_seon->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(9);
        lineedit_puerto_seon->setFont(font1);

        horizontalLayout_8->addWidget(lineedit_puerto_seon);

        btn_conectar_seon = new QPushButton(widget_puerto_seon);
        btn_conectar_seon->setObjectName(QStringLiteral("btn_conectar_seon"));

        horizontalLayout_8->addWidget(btn_conectar_seon);


        verticalLayout->addWidget(widget_puerto_seon);

        form_seon = new QWidget(simuladorcomuClass);
        form_seon->setObjectName(QStringLiteral("form_seon"));
        from_seon = new QFormLayout(form_seon);
        from_seon->setSpacing(6);
        from_seon->setContentsMargins(11, 11, 11, 11);
        from_seon->setObjectName(QStringLiteral("from_seon"));
        from_seon->setContentsMargins(0, 0, 0, 0);
        lbl_header1_seon = new QLabel(form_seon);
        lbl_header1_seon->setObjectName(QStringLiteral("lbl_header1_seon"));

        from_seon->setWidget(1, QFormLayout::LabelRole, lbl_header1_seon);

        lineedit_header1_seon = new QLineEdit(form_seon);
        lineedit_header1_seon->setObjectName(QStringLiteral("lineedit_header1_seon"));
        lineedit_header1_seon->setEnabled(false);

        from_seon->setWidget(1, QFormLayout::FieldRole, lineedit_header1_seon);

        lbl_header_seon = new QLabel(form_seon);
        lbl_header_seon->setObjectName(QStringLiteral("lbl_header_seon"));

        from_seon->setWidget(2, QFormLayout::LabelRole, lbl_header_seon);

        lineedit_header2_seon = new QLineEdit(form_seon);
        lineedit_header2_seon->setObjectName(QStringLiteral("lineedit_header2_seon"));
        lineedit_header2_seon->setEnabled(false);

        from_seon->setWidget(2, QFormLayout::FieldRole, lineedit_header2_seon);

        lbl_distancia = new QLabel(form_seon);
        lbl_distancia->setObjectName(QStringLiteral("lbl_distancia"));

        from_seon->setWidget(3, QFormLayout::LabelRole, lbl_distancia);

        spin_distancia = new QSpinBox(form_seon);
        spin_distancia->setObjectName(QStringLiteral("spin_distancia"));
        spin_distancia->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spin_distancia->sizePolicy().hasHeightForWidth());
        spin_distancia->setSizePolicy(sizePolicy2);
        spin_distancia->setMaximum(65535);

        from_seon->setWidget(3, QFormLayout::FieldRole, spin_distancia);

        lbl_origen_dato = new QLabel(form_seon);
        lbl_origen_dato->setObjectName(QStringLiteral("lbl_origen_dato"));

        from_seon->setWidget(4, QFormLayout::LabelRole, lbl_origen_dato);

        groupbox_origen_dato = new QGroupBox(form_seon);
        groupbox_origen_dato->setObjectName(QStringLiteral("groupbox_origen_dato"));
        sizePolicy.setHeightForWidth(groupbox_origen_dato->sizePolicy().hasHeightForWidth());
        groupbox_origen_dato->setSizePolicy(sizePolicy);
        horizontalLayout_7 = new QHBoxLayout(groupbox_origen_dato);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 0, 0, 0);
        radiobut_origen_dato_0 = new QRadioButton(groupbox_origen_dato);
        radiobut_origen_dato_0->setObjectName(QStringLiteral("radiobut_origen_dato_0"));

        horizontalLayout_7->addWidget(radiobut_origen_dato_0);

        radiobut_origen_dato_1 = new QRadioButton(groupbox_origen_dato);
        radiobut_origen_dato_1->setObjectName(QStringLiteral("radiobut_origen_dato_1"));

        horizontalLayout_7->addWidget(radiobut_origen_dato_1);

        radiobut_origen_dato_2 = new QRadioButton(groupbox_origen_dato);
        radiobut_origen_dato_2->setObjectName(QStringLiteral("radiobut_origen_dato_2"));

        horizontalLayout_7->addWidget(radiobut_origen_dato_2);


        from_seon->setWidget(4, QFormLayout::FieldRole, groupbox_origen_dato);

        lbl_modo_pred = new QLabel(form_seon);
        lbl_modo_pred->setObjectName(QStringLiteral("lbl_modo_pred"));

        from_seon->setWidget(5, QFormLayout::LabelRole, lbl_modo_pred);

        groupbox_modo_pred = new QGroupBox(form_seon);
        groupbox_modo_pred->setObjectName(QStringLiteral("groupbox_modo_pred"));
        horizontalLayout_5 = new QHBoxLayout(groupbox_modo_pred);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, 0, 0);
        radiobut_modo_pred_0 = new QRadioButton(groupbox_modo_pred);
        radiobut_modo_pred_0->setObjectName(QStringLiteral("radiobut_modo_pred_0"));

        horizontalLayout_5->addWidget(radiobut_modo_pred_0);

        radiobut_modo_pred_1 = new QRadioButton(groupbox_modo_pred);
        radiobut_modo_pred_1->setObjectName(QStringLiteral("radiobut_modo_pred_1"));

        horizontalLayout_5->addWidget(radiobut_modo_pred_1);


        from_seon->setWidget(5, QFormLayout::FieldRole, groupbox_modo_pred);

        lbl_velocidad = new QLabel(form_seon);
        lbl_velocidad->setObjectName(QStringLiteral("lbl_velocidad"));

        from_seon->setWidget(6, QFormLayout::LabelRole, lbl_velocidad);

        spin_velocidad = new QSpinBox(form_seon);
        spin_velocidad->setObjectName(QStringLiteral("spin_velocidad"));
        sizePolicy2.setHeightForWidth(spin_velocidad->sizePolicy().hasHeightForWidth());
        spin_velocidad->setSizePolicy(sizePolicy2);
        spin_velocidad->setMaximum(4095);

        from_seon->setWidget(6, QFormLayout::FieldRole, spin_velocidad);

        lbl_zoom = new QLabel(form_seon);
        lbl_zoom->setObjectName(QStringLiteral("lbl_zoom"));

        from_seon->setWidget(7, QFormLayout::LabelRole, lbl_zoom);

        spin_zoom = new QSpinBox(form_seon);
        spin_zoom->setObjectName(QStringLiteral("spin_zoom"));
        sizePolicy2.setHeightForWidth(spin_zoom->sizePolicy().hasHeightForWidth());
        spin_zoom->setSizePolicy(sizePolicy2);
        spin_zoom->setMaximum(255);

        from_seon->setWidget(7, QFormLayout::FieldRole, spin_zoom);

        lbl_radar_act = new QLabel(form_seon);
        lbl_radar_act->setObjectName(QStringLiteral("lbl_radar_act"));

        from_seon->setWidget(8, QFormLayout::LabelRole, lbl_radar_act);

        checkbox_radar_acti = new QCheckBox(form_seon);
        checkbox_radar_acti->setObjectName(QStringLiteral("checkbox_radar_acti"));

        from_seon->setWidget(8, QFormLayout::FieldRole, checkbox_radar_acti);

        lbl_header2_seon = new QLabel(form_seon);
        lbl_header2_seon->setObjectName(QStringLiteral("lbl_header2_seon"));

        from_seon->setWidget(9, QFormLayout::LabelRole, lbl_header2_seon);

        lbl_azimut_radar = new QLabel(form_seon);
        lbl_azimut_radar->setObjectName(QStringLiteral("lbl_azimut_radar"));

        from_seon->setWidget(10, QFormLayout::LabelRole, lbl_azimut_radar);

        horizontalWidget_6 = new QWidget(form_seon);
        horizontalWidget_6->setObjectName(QStringLiteral("horizontalWidget_6"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(horizontalWidget_6->sizePolicy().hasHeightForWidth());
        horizontalWidget_6->setSizePolicy(sizePolicy3);
        horizontalWidget_6->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_6 = new QHBoxLayout(horizontalWidget_6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        spin_azimut_radar_entero = new QSpinBox(horizontalWidget_6);
        spin_azimut_radar_entero->setObjectName(QStringLiteral("spin_azimut_radar_entero"));
        sizePolicy2.setHeightForWidth(spin_azimut_radar_entero->sizePolicy().hasHeightForWidth());
        spin_azimut_radar_entero->setSizePolicy(sizePolicy2);
        spin_azimut_radar_entero->setMaximum(65535);

        horizontalLayout_6->addWidget(spin_azimut_radar_entero);

        label_4 = new QLabel(horizontalWidget_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(label_4);

        spin_azimut_radar_decimal = new QSpinBox(horizontalWidget_6);
        spin_azimut_radar_decimal->setObjectName(QStringLiteral("spin_azimut_radar_decimal"));
        sizePolicy2.setHeightForWidth(spin_azimut_radar_decimal->sizePolicy().hasHeightForWidth());
        spin_azimut_radar_decimal->setSizePolicy(sizePolicy2);
        spin_azimut_radar_decimal->setMaximum(99);

        horizontalLayout_6->addWidget(spin_azimut_radar_decimal);


        from_seon->setWidget(10, QFormLayout::FieldRole, horizontalWidget_6);

        lbl_dist_radar = new QLabel(form_seon);
        lbl_dist_radar->setObjectName(QStringLiteral("lbl_dist_radar"));

        from_seon->setWidget(11, QFormLayout::LabelRole, lbl_dist_radar);

        spin_distancia_radar = new QSpinBox(form_seon);
        spin_distancia_radar->setObjectName(QStringLiteral("spin_distancia_radar"));
        sizePolicy2.setHeightForWidth(spin_distancia_radar->sizePolicy().hasHeightForWidth());
        spin_distancia_radar->setSizePolicy(sizePolicy2);
        spin_distancia_radar->setMaximum(65535);

        from_seon->setWidget(11, QFormLayout::FieldRole, spin_distancia_radar);

        lbl_azimut_graf = new QLabel(form_seon);
        lbl_azimut_graf->setObjectName(QStringLiteral("lbl_azimut_graf"));

        from_seon->setWidget(12, QFormLayout::LabelRole, lbl_azimut_graf);

        spin_azimut_graf = new QSpinBox(form_seon);
        spin_azimut_graf->setObjectName(QStringLiteral("spin_azimut_graf"));
        sizePolicy2.setHeightForWidth(spin_azimut_graf->sizePolicy().hasHeightForWidth());
        spin_azimut_graf->setSizePolicy(sizePolicy2);
        spin_azimut_graf->setMaximum(255);

        from_seon->setWidget(12, QFormLayout::FieldRole, spin_azimut_graf);

        lbl_elevacion_graf = new QLabel(form_seon);
        lbl_elevacion_graf->setObjectName(QStringLiteral("lbl_elevacion_graf"));

        from_seon->setWidget(13, QFormLayout::LabelRole, lbl_elevacion_graf);

        spin_elevacion_graf = new QSpinBox(form_seon);
        spin_elevacion_graf->setObjectName(QStringLiteral("spin_elevacion_graf"));
        sizePolicy2.setHeightForWidth(spin_elevacion_graf->sizePolicy().hasHeightForWidth());
        spin_elevacion_graf->setSizePolicy(sizePolicy2);
        spin_elevacion_graf->setMaximum(255);

        from_seon->setWidget(13, QFormLayout::FieldRole, spin_elevacion_graf);

        lbl_azimut_abs = new QLabel(form_seon);
        lbl_azimut_abs->setObjectName(QStringLiteral("lbl_azimut_abs"));

        from_seon->setWidget(14, QFormLayout::LabelRole, lbl_azimut_abs);

        horizontalWidget_4 = new QWidget(form_seon);
        horizontalWidget_4->setObjectName(QStringLiteral("horizontalWidget_4"));
        sizePolicy3.setHeightForWidth(horizontalWidget_4->sizePolicy().hasHeightForWidth());
        horizontalWidget_4->setSizePolicy(sizePolicy3);
        horizontalWidget_4->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_4 = new QHBoxLayout(horizontalWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        spin_azimut_abs_entero = new QSpinBox(horizontalWidget_4);
        spin_azimut_abs_entero->setObjectName(QStringLiteral("spin_azimut_abs_entero"));
        sizePolicy2.setHeightForWidth(spin_azimut_abs_entero->sizePolicy().hasHeightForWidth());
        spin_azimut_abs_entero->setSizePolicy(sizePolicy2);
        spin_azimut_abs_entero->setMaximum(65535);

        horizontalLayout_4->addWidget(spin_azimut_abs_entero);

        label_2 = new QLabel(horizontalWidget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(label_2);

        spin_azimut_abs_decimal = new QSpinBox(horizontalWidget_4);
        spin_azimut_abs_decimal->setObjectName(QStringLiteral("spin_azimut_abs_decimal"));
        sizePolicy2.setHeightForWidth(spin_azimut_abs_decimal->sizePolicy().hasHeightForWidth());
        spin_azimut_abs_decimal->setSizePolicy(sizePolicy2);
        spin_azimut_abs_decimal->setMaximum(99);

        horizontalLayout_4->addWidget(spin_azimut_abs_decimal);


        from_seon->setWidget(14, QFormLayout::FieldRole, horizontalWidget_4);

        lbl_elevacion_abs = new QLabel(form_seon);
        lbl_elevacion_abs->setObjectName(QStringLiteral("lbl_elevacion_abs"));

        from_seon->setWidget(15, QFormLayout::LabelRole, lbl_elevacion_abs);

        horizontalWidget_3 = new QWidget(form_seon);
        horizontalWidget_3->setObjectName(QStringLiteral("horizontalWidget_3"));
        sizePolicy3.setHeightForWidth(horizontalWidget_3->sizePolicy().hasHeightForWidth());
        horizontalWidget_3->setSizePolicy(sizePolicy3);
        horizontalWidget_3->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        spin_elevacion_abs_entero = new QSpinBox(horizontalWidget_3);
        spin_elevacion_abs_entero->setObjectName(QStringLiteral("spin_elevacion_abs_entero"));
        sizePolicy2.setHeightForWidth(spin_elevacion_abs_entero->sizePolicy().hasHeightForWidth());
        spin_elevacion_abs_entero->setSizePolicy(sizePolicy2);
        spin_elevacion_abs_entero->setMaximum(65535);

        horizontalLayout_3->addWidget(spin_elevacion_abs_entero);

        label = new QLabel(horizontalWidget_3);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(label);

        spin_elevacion_abs_decimal = new QSpinBox(horizontalWidget_3);
        spin_elevacion_abs_decimal->setObjectName(QStringLiteral("spin_elevacion_abs_decimal"));
        sizePolicy2.setHeightForWidth(spin_elevacion_abs_decimal->sizePolicy().hasHeightForWidth());
        spin_elevacion_abs_decimal->setSizePolicy(sizePolicy2);
        spin_elevacion_abs_decimal->setMaximum(99);

        horizontalLayout_3->addWidget(spin_elevacion_abs_decimal);


        from_seon->setWidget(15, QFormLayout::FieldRole, horizontalWidget_3);

        lbl_centro_grav = new QLabel(form_seon);
        lbl_centro_grav->setObjectName(QStringLiteral("lbl_centro_grav"));

        from_seon->setWidget(16, QFormLayout::LabelRole, lbl_centro_grav);

        horizontalWidget_2 = new QWidget(form_seon);
        horizontalWidget_2->setObjectName(QStringLiteral("horizontalWidget_2"));
        sizePolicy3.setHeightForWidth(horizontalWidget_2->sizePolicy().hasHeightForWidth());
        horizontalWidget_2->setSizePolicy(sizePolicy3);
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        spin_centro_gravedad_x = new QSpinBox(horizontalWidget_2);
        spin_centro_gravedad_x->setObjectName(QStringLiteral("spin_centro_gravedad_x"));
        sizePolicy2.setHeightForWidth(spin_centro_gravedad_x->sizePolicy().hasHeightForWidth());
        spin_centro_gravedad_x->setSizePolicy(sizePolicy2);
        spin_centro_gravedad_x->setMaximum(65535);

        horizontalLayout_2->addWidget(spin_centro_gravedad_x);

        label_11 = new QLabel(horizontalWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_2->addWidget(label_11);

        spin_centro_gravedad_y = new QSpinBox(horizontalWidget_2);
        spin_centro_gravedad_y->setObjectName(QStringLiteral("spin_centro_gravedad_y"));
        sizePolicy2.setHeightForWidth(spin_centro_gravedad_y->sizePolicy().hasHeightForWidth());
        spin_centro_gravedad_y->setSizePolicy(sizePolicy2);
        spin_centro_gravedad_y->setMaximum(65535);

        horizontalLayout_2->addWidget(spin_centro_gravedad_y);


        from_seon->setWidget(16, QFormLayout::FieldRole, horizontalWidget_2);

        lbl_corrimiento = new QLabel(form_seon);
        lbl_corrimiento->setObjectName(QStringLiteral("lbl_corrimiento"));

        from_seon->setWidget(17, QFormLayout::LabelRole, lbl_corrimiento);

        horizontalWidget = new QWidget(form_seon);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        sizePolicy3.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy3);
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        spin_corrimiento_x = new QSpinBox(horizontalWidget);
        spin_corrimiento_x->setObjectName(QStringLiteral("spin_corrimiento_x"));
        sizePolicy2.setHeightForWidth(spin_corrimiento_x->sizePolicy().hasHeightForWidth());
        spin_corrimiento_x->setSizePolicy(sizePolicy2);
        spin_corrimiento_x->setMaximum(255);

        horizontalLayout->addWidget(spin_corrimiento_x);

        spin_corrimiento_y = new QSpinBox(horizontalWidget);
        spin_corrimiento_y->setObjectName(QStringLiteral("spin_corrimiento_y"));
        sizePolicy2.setHeightForWidth(spin_corrimiento_y->sizePolicy().hasHeightForWidth());
        spin_corrimiento_y->setSizePolicy(sizePolicy2);
        spin_corrimiento_y->setMaximum(255);

        horizontalLayout->addWidget(spin_corrimiento_y);


        from_seon->setWidget(17, QFormLayout::FieldRole, horizontalWidget);

        groupbox_tipo_blanco = new QGroupBox(form_seon);
        groupbox_tipo_blanco->setObjectName(QStringLiteral("groupbox_tipo_blanco"));
        horizontalLayout_12 = new QHBoxLayout(groupbox_tipo_blanco);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        radiobut_tipo_s = new QRadioButton(groupbox_tipo_blanco);
        radiobut_tipo_s->setObjectName(QStringLiteral("radiobut_tipo_s"));

        horizontalLayout_12->addWidget(radiobut_tipo_s);

        radiobut_tipo_a = new QRadioButton(groupbox_tipo_blanco);
        radiobut_tipo_a->setObjectName(QStringLiteral("radiobut_tipo_a"));

        horizontalLayout_12->addWidget(radiobut_tipo_a);

        radiobut_tipo_y = new QRadioButton(groupbox_tipo_blanco);
        radiobut_tipo_y->setObjectName(QStringLiteral("radiobut_tipo_y"));

        horizontalLayout_12->addWidget(radiobut_tipo_y);

        radiobut_tipo_t = new QRadioButton(groupbox_tipo_blanco);
        radiobut_tipo_t->setObjectName(QStringLiteral("radiobut_tipo_t"));

        horizontalLayout_12->addWidget(radiobut_tipo_t);

        radiobut_tipo_u = new QRadioButton(groupbox_tipo_blanco);
        radiobut_tipo_u->setObjectName(QStringLiteral("radiobut_tipo_u"));

        horizontalLayout_12->addWidget(radiobut_tipo_u);


        from_seon->setWidget(9, QFormLayout::FieldRole, groupbox_tipo_blanco);


        verticalLayout->addWidget(form_seon);

        btn_enviar_seon = new QPushButton(simuladorcomuClass);
        btn_enviar_seon->setObjectName(QStringLiteral("btn_enviar_seon"));

        verticalLayout->addWidget(btn_enviar_seon);


        horizontalLayout_11->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_puerto_botonera = new QWidget(simuladorcomuClass);
        widget_puerto_botonera->setObjectName(QStringLiteral("widget_puerto_botonera"));
        sizePolicy.setHeightForWidth(widget_puerto_botonera->sizePolicy().hasHeightForWidth());
        widget_puerto_botonera->setSizePolicy(sizePolicy);
        horizontalLayout_10 = new QHBoxLayout(widget_puerto_botonera);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget_puerto_botonera);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout_10->addWidget(label_8);

        line_2 = new QFrame(widget_puerto_botonera);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_10->addWidget(line_2);

        label_6 = new QLabel(widget_puerto_botonera);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_10->addWidget(label_6);

        lineedit_puerto_botonera = new QLineEdit(widget_puerto_botonera);
        lineedit_puerto_botonera->setObjectName(QStringLiteral("lineedit_puerto_botonera"));

        horizontalLayout_10->addWidget(lineedit_puerto_botonera);

        btn_conectar_botonera = new QPushButton(widget_puerto_botonera);
        btn_conectar_botonera->setObjectName(QStringLiteral("btn_conectar_botonera"));

        horizontalLayout_10->addWidget(btn_conectar_botonera);


        verticalLayout_2->addWidget(widget_puerto_botonera);

        form_botonera = new QWidget(simuladorcomuClass);
        form_botonera->setObjectName(QStringLiteral("form_botonera"));
        layout_botonera = new QFormLayout(form_botonera);
        layout_botonera->setSpacing(6);
        layout_botonera->setContentsMargins(11, 11, 11, 11);
        layout_botonera->setObjectName(QStringLiteral("layout_botonera"));
        layout_botonera->setContentsMargins(0, 0, 0, 0);
        lbl_header1 = new QLabel(form_botonera);
        lbl_header1->setObjectName(QStringLiteral("lbl_header1"));

        layout_botonera->setWidget(0, QFormLayout::LabelRole, lbl_header1);

        lineedit_header1_botonera = new QLineEdit(form_botonera);
        lineedit_header1_botonera->setObjectName(QStringLiteral("lineedit_header1_botonera"));
        lineedit_header1_botonera->setEnabled(false);

        layout_botonera->setWidget(0, QFormLayout::FieldRole, lineedit_header1_botonera);

        lbl_header2 = new QLabel(form_botonera);
        lbl_header2->setObjectName(QStringLiteral("lbl_header2"));

        layout_botonera->setWidget(1, QFormLayout::LabelRole, lbl_header2);

        lineedit_header2_botonera = new QLineEdit(form_botonera);
        lineedit_header2_botonera->setObjectName(QStringLiteral("lineedit_header2_botonera"));
        lineedit_header2_botonera->setEnabled(false);

        layout_botonera->setWidget(1, QFormLayout::FieldRole, lineedit_header2_botonera);

        lbl_contador = new QLabel(form_botonera);
        lbl_contador->setObjectName(QStringLiteral("lbl_contador"));

        layout_botonera->setWidget(2, QFormLayout::LabelRole, lbl_contador);

        lbl_ref_est = new QLabel(form_botonera);
        lbl_ref_est->setObjectName(QStringLiteral("lbl_ref_est"));

        layout_botonera->setWidget(3, QFormLayout::LabelRole, lbl_ref_est);

        checkbox_ref_est = new QCheckBox(form_botonera);
        checkbox_ref_est->setObjectName(QStringLiteral("checkbox_ref_est"));

        layout_botonera->setWidget(3, QFormLayout::FieldRole, checkbox_ref_est);

        lbl_pant_datos = new QLabel(form_botonera);
        lbl_pant_datos->setObjectName(QStringLiteral("lbl_pant_datos"));

        layout_botonera->setWidget(4, QFormLayout::LabelRole, lbl_pant_datos);

        checkbox_pant_datos = new QCheckBox(form_botonera);
        checkbox_pant_datos->setObjectName(QStringLiteral("checkbox_pant_datos"));

        layout_botonera->setWidget(4, QFormLayout::FieldRole, checkbox_pant_datos);

        lbl_pant_barrido = new QLabel(form_botonera);
        lbl_pant_barrido->setObjectName(QStringLiteral("lbl_pant_barrido"));

        layout_botonera->setWidget(5, QFormLayout::LabelRole, lbl_pant_barrido);

        checkbox_pant_barrido = new QCheckBox(form_botonera);
        checkbox_pant_barrido->setObjectName(QStringLiteral("checkbox_pant_barrido"));

        layout_botonera->setWidget(5, QFormLayout::FieldRole, checkbox_pant_barrido);

        lbl_pant_normal = new QLabel(form_botonera);
        lbl_pant_normal->setObjectName(QStringLiteral("lbl_pant_normal"));

        layout_botonera->setWidget(6, QFormLayout::LabelRole, lbl_pant_normal);

        lbl_vent_opt_lav = new QLabel(form_botonera);
        lbl_vent_opt_lav->setObjectName(QStringLiteral("lbl_vent_opt_lav"));

        layout_botonera->setWidget(7, QFormLayout::LabelRole, lbl_vent_opt_lav);

        checkbox_vent_opt_lav = new QCheckBox(form_botonera);
        checkbox_vent_opt_lav->setObjectName(QStringLiteral("checkbox_vent_opt_lav"));

        layout_botonera->setWidget(7, QFormLayout::FieldRole, checkbox_vent_opt_lav);

        lbl_vent_opt_llimp = new QLabel(form_botonera);
        lbl_vent_opt_llimp->setObjectName(QStringLiteral("lbl_vent_opt_llimp"));

        layout_botonera->setWidget(8, QFormLayout::LabelRole, lbl_vent_opt_llimp);

        checkbox_vent_opt_limp = new QCheckBox(form_botonera);
        checkbox_vent_opt_limp->setObjectName(QStringLiteral("checkbox_vent_opt_limp"));

        layout_botonera->setWidget(8, QFormLayout::FieldRole, checkbox_vent_opt_limp);

        lbl_pa_ir = new QLabel(form_botonera);
        lbl_pa_ir->setObjectName(QStringLiteral("lbl_pa_ir"));

        layout_botonera->setWidget(9, QFormLayout::LabelRole, lbl_pa_ir);

        checkbox_pa_ir = new QCheckBox(form_botonera);
        checkbox_pa_ir->setObjectName(QStringLiteral("checkbox_pa_ir"));

        layout_botonera->setWidget(9, QFormLayout::FieldRole, checkbox_pa_ir);

        lbl_cam_ir = new QLabel(form_botonera);
        lbl_cam_ir->setObjectName(QStringLiteral("lbl_cam_ir"));

        layout_botonera->setWidget(10, QFormLayout::LabelRole, lbl_cam_ir);

        checkbox_cam_ir = new QCheckBox(form_botonera);
        checkbox_cam_ir->setObjectName(QStringLiteral("checkbox_cam_ir"));

        layout_botonera->setWidget(10, QFormLayout::FieldRole, checkbox_cam_ir);

        lbl_cam_diu = new QLabel(form_botonera);
        lbl_cam_diu->setObjectName(QStringLiteral("lbl_cam_diu"));

        layout_botonera->setWidget(11, QFormLayout::LabelRole, lbl_cam_diu);

        checkbox_cam_diu = new QCheckBox(form_botonera);
        checkbox_cam_diu->setObjectName(QStringLiteral("checkbox_cam_diu"));

        layout_botonera->setWidget(11, QFormLayout::FieldRole, checkbox_cam_diu);

        lbl_zoom_amp = new QLabel(form_botonera);
        lbl_zoom_amp->setObjectName(QStringLiteral("lbl_zoom_amp"));

        layout_botonera->setWidget(12, QFormLayout::LabelRole, lbl_zoom_amp);

        checkbox_zoom_amp = new QCheckBox(form_botonera);
        checkbox_zoom_amp->setObjectName(QStringLiteral("checkbox_zoom_amp"));

        layout_botonera->setWidget(12, QFormLayout::FieldRole, checkbox_zoom_amp);

        lbl_zoom_est = new QLabel(form_botonera);
        lbl_zoom_est->setObjectName(QStringLiteral("lbl_zoom_est"));

        layout_botonera->setWidget(13, QFormLayout::LabelRole, lbl_zoom_est);

        checkbox_zoom_est = new QCheckBox(form_botonera);
        checkbox_zoom_est->setObjectName(QStringLiteral("checkbox_zoom_est"));

        layout_botonera->setWidget(13, QFormLayout::FieldRole, checkbox_zoom_est);

        lbl_foco_cerca = new QLabel(form_botonera);
        lbl_foco_cerca->setObjectName(QStringLiteral("lbl_foco_cerca"));

        layout_botonera->setWidget(14, QFormLayout::LabelRole, lbl_foco_cerca);

        checkbox_foco_cerca = new QCheckBox(form_botonera);
        checkbox_foco_cerca->setObjectName(QStringLiteral("checkbox_foco_cerca"));

        layout_botonera->setWidget(14, QFormLayout::FieldRole, checkbox_foco_cerca);

        lbl_foco_lejos = new QLabel(form_botonera);
        lbl_foco_lejos->setObjectName(QStringLiteral("lbl_foco_lejos"));

        layout_botonera->setWidget(15, QFormLayout::LabelRole, lbl_foco_lejos);

        checkbox_foco_lejos = new QCheckBox(form_botonera);
        checkbox_foco_lejos->setObjectName(QStringLiteral("checkbox_foco_lejos"));

        layout_botonera->setWidget(15, QFormLayout::FieldRole, checkbox_foco_lejos);

        lbl_video_cuant = new QLabel(form_botonera);
        lbl_video_cuant->setObjectName(QStringLiteral("lbl_video_cuant"));

        layout_botonera->setWidget(16, QFormLayout::LabelRole, lbl_video_cuant);

        lbl_video_dif = new QLabel(form_botonera);
        lbl_video_dif->setObjectName(QStringLiteral("lbl_video_dif"));

        layout_botonera->setWidget(17, QFormLayout::LabelRole, lbl_video_dif);

        lbl_video_nor = new QLabel(form_botonera);
        lbl_video_nor->setObjectName(QStringLiteral("lbl_video_nor"));

        layout_botonera->setWidget(18, QFormLayout::LabelRole, lbl_video_nor);

        lbl_eng_cuant = new QLabel(form_botonera);
        lbl_eng_cuant->setObjectName(QStringLiteral("lbl_eng_cuant"));

        layout_botonera->setWidget(19, QFormLayout::LabelRole, lbl_eng_cuant);

        lbl_eng_dif = new QLabel(form_botonera);
        lbl_eng_dif->setObjectName(QStringLiteral("lbl_eng_dif"));

        layout_botonera->setWidget(20, QFormLayout::LabelRole, lbl_eng_dif);

        lbl_mod_fij = new QLabel(form_botonera);
        lbl_mod_fij->setObjectName(QStringLiteral("lbl_mod_fij"));

        layout_botonera->setWidget(21, QFormLayout::LabelRole, lbl_mod_fij);

        lbl_mod_esc = new QLabel(form_botonera);
        lbl_mod_esc->setObjectName(QStringLiteral("lbl_mod_esc"));

        layout_botonera->setWidget(22, QFormLayout::LabelRole, lbl_mod_esc);

        lbl_mod_est = new QLabel(form_botonera);
        lbl_mod_est->setObjectName(QStringLiteral("lbl_mod_est"));

        layout_botonera->setWidget(23, QFormLayout::LabelRole, lbl_mod_est);

        checkbox_video_cuant = new QCheckBox(form_botonera);
        checkbox_video_cuant->setObjectName(QStringLiteral("checkbox_video_cuant"));

        layout_botonera->setWidget(16, QFormLayout::FieldRole, checkbox_video_cuant);

        checkbox_video_dif = new QCheckBox(form_botonera);
        checkbox_video_dif->setObjectName(QStringLiteral("checkbox_video_dif"));

        layout_botonera->setWidget(17, QFormLayout::FieldRole, checkbox_video_dif);

        checkbox_video_nor = new QCheckBox(form_botonera);
        checkbox_video_nor->setObjectName(QStringLiteral("checkbox_video_nor"));

        layout_botonera->setWidget(18, QFormLayout::FieldRole, checkbox_video_nor);

        checkbox_eng_cuant = new QCheckBox(form_botonera);
        checkbox_eng_cuant->setObjectName(QStringLiteral("checkbox_eng_cuant"));

        layout_botonera->setWidget(19, QFormLayout::FieldRole, checkbox_eng_cuant);

        checkbox_eng_dif = new QCheckBox(form_botonera);
        checkbox_eng_dif->setObjectName(QStringLiteral("checkbox_eng_dif"));

        layout_botonera->setWidget(20, QFormLayout::FieldRole, checkbox_eng_dif);

        checkbox_mod_fij = new QCheckBox(form_botonera);
        checkbox_mod_fij->setObjectName(QStringLiteral("checkbox_mod_fij"));

        layout_botonera->setWidget(21, QFormLayout::FieldRole, checkbox_mod_fij);

        checkbox_mod_esc = new QCheckBox(form_botonera);
        checkbox_mod_esc->setObjectName(QStringLiteral("checkbox_mod_esc"));

        layout_botonera->setWidget(22, QFormLayout::FieldRole, checkbox_mod_esc);

        checkbox_mod_est = new QCheckBox(form_botonera);
        checkbox_mod_est->setObjectName(QStringLiteral("checkbox_mod_est"));

        layout_botonera->setWidget(23, QFormLayout::FieldRole, checkbox_mod_est);

        checkbox_pant_normal = new QCheckBox(form_botonera);
        checkbox_pant_normal->setObjectName(QStringLiteral("checkbox_pant_normal"));

        layout_botonera->setWidget(6, QFormLayout::FieldRole, checkbox_pant_normal);

        spin_contador_botonera = new QSpinBox(form_botonera);
        spin_contador_botonera->setObjectName(QStringLiteral("spin_contador_botonera"));
        spin_contador_botonera->setEnabled(false);
        sizePolicy2.setHeightForWidth(spin_contador_botonera->sizePolicy().hasHeightForWidth());
        spin_contador_botonera->setSizePolicy(sizePolicy2);
        spin_contador_botonera->setMaximum(65535);

        layout_botonera->setWidget(2, QFormLayout::FieldRole, spin_contador_botonera);


        verticalLayout_2->addWidget(form_botonera);

        btn_enviar_botonera = new QPushButton(simuladorcomuClass);
        btn_enviar_botonera->setObjectName(QStringLiteral("btn_enviar_botonera"));

        verticalLayout_2->addWidget(btn_enviar_botonera);


        horizontalLayout_11->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_puerto_pupitre = new QWidget(simuladorcomuClass);
        widget_puerto_pupitre->setObjectName(QStringLiteral("widget_puerto_pupitre"));
        sizePolicy.setHeightForWidth(widget_puerto_pupitre->sizePolicy().hasHeightForWidth());
        widget_puerto_pupitre->setSizePolicy(sizePolicy);
        horizontalLayout_9 = new QHBoxLayout(widget_puerto_pupitre);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget_puerto_pupitre);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        horizontalLayout_9->addWidget(label_9);

        line_3 = new QFrame(widget_puerto_pupitre);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_9->addWidget(line_3);

        label_5 = new QLabel(widget_puerto_pupitre);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_9->addWidget(label_5);

        lineedit_puerto_pupitre = new QLineEdit(widget_puerto_pupitre);
        lineedit_puerto_pupitre->setObjectName(QStringLiteral("lineedit_puerto_pupitre"));

        horizontalLayout_9->addWidget(lineedit_puerto_pupitre);

        btn_conectar_pupitre = new QPushButton(widget_puerto_pupitre);
        btn_conectar_pupitre->setObjectName(QStringLiteral("btn_conectar_pupitre"));

        horizontalLayout_9->addWidget(btn_conectar_pupitre);


        verticalLayout_3->addWidget(widget_puerto_pupitre);

        form_pupitre = new QWidget(simuladorcomuClass);
        form_pupitre->setObjectName(QStringLiteral("form_pupitre"));
        layout_pupitre = new QFormLayout(form_pupitre);
        layout_pupitre->setSpacing(6);
        layout_pupitre->setContentsMargins(11, 11, 11, 11);
        layout_pupitre->setObjectName(QStringLiteral("layout_pupitre"));
        layout_pupitre->setContentsMargins(0, 0, 0, 0);
        lbl_header1_pupitre = new QLabel(form_pupitre);
        lbl_header1_pupitre->setObjectName(QStringLiteral("lbl_header1_pupitre"));

        layout_pupitre->setWidget(0, QFormLayout::LabelRole, lbl_header1_pupitre);

        lineedit_header1_pupitre = new QLineEdit(form_pupitre);
        lineedit_header1_pupitre->setObjectName(QStringLiteral("lineedit_header1_pupitre"));
        lineedit_header1_pupitre->setEnabled(false);

        layout_pupitre->setWidget(0, QFormLayout::FieldRole, lineedit_header1_pupitre);

        lbl_header2_2 = new QLabel(form_pupitre);
        lbl_header2_2->setObjectName(QStringLiteral("lbl_header2_2"));

        layout_pupitre->setWidget(1, QFormLayout::LabelRole, lbl_header2_2);

        lbl_contador1 = new QLabel(form_pupitre);
        lbl_contador1->setObjectName(QStringLiteral("lbl_contador1"));

        layout_pupitre->setWidget(2, QFormLayout::LabelRole, lbl_contador1);

        lbl_arrp = new QLabel(form_pupitre);
        lbl_arrp->setObjectName(QStringLiteral("lbl_arrp"));

        layout_pupitre->setWidget(3, QFormLayout::LabelRole, lbl_arrp);

        lbl_eng_desen_pic = new QLabel(form_pupitre);
        lbl_eng_desen_pic->setObjectName(QStringLiteral("lbl_eng_desen_pic"));

        layout_pupitre->setWidget(4, QFormLayout::LabelRole, lbl_eng_desen_pic);

        lbl_boton2 = new QLabel(form_pupitre);
        lbl_boton2->setObjectName(QStringLiteral("lbl_boton2"));

        layout_pupitre->setWidget(5, QFormLayout::LabelRole, lbl_boton2);

        lbl_boton3 = new QLabel(form_pupitre);
        lbl_boton3->setObjectName(QStringLiteral("lbl_boton3"));

        layout_pupitre->setWidget(6, QFormLayout::LabelRole, lbl_boton3);

        lbl_graba_pic = new QLabel(form_pupitre);
        lbl_graba_pic->setObjectName(QStringLiteral("lbl_graba_pic"));

        layout_pupitre->setWidget(7, QFormLayout::LabelRole, lbl_graba_pic);

        lbl_acc_arch = new QLabel(form_pupitre);
        lbl_acc_arch->setObjectName(QStringLiteral("lbl_acc_arch"));

        layout_pupitre->setWidget(8, QFormLayout::LabelRole, lbl_acc_arch);

        lbl_sel_vent1 = new QLabel(form_pupitre);
        lbl_sel_vent1->setObjectName(QStringLiteral("lbl_sel_vent1"));

        layout_pupitre->setWidget(9, QFormLayout::LabelRole, lbl_sel_vent1);

        lbl_sel_vent2 = new QLabel(form_pupitre);
        lbl_sel_vent2->setObjectName(QStringLiteral("lbl_sel_vent2"));

        layout_pupitre->setWidget(10, QFormLayout::LabelRole, lbl_sel_vent2);

        lbl_sen_fija = new QLabel(form_pupitre);
        lbl_sen_fija->setObjectName(QStringLiteral("lbl_sen_fija"));

        layout_pupitre->setWidget(11, QFormLayout::LabelRole, lbl_sen_fija);

        lineedit_header2_2 = new QLineEdit(form_pupitre);
        lineedit_header2_2->setObjectName(QStringLiteral("lineedit_header2_2"));
        lineedit_header2_2->setEnabled(false);

        layout_pupitre->setWidget(1, QFormLayout::FieldRole, lineedit_header2_2);

        checkbox_arrp = new QCheckBox(form_pupitre);
        checkbox_arrp->setObjectName(QStringLiteral("checkbox_arrp"));

        layout_pupitre->setWidget(3, QFormLayout::FieldRole, checkbox_arrp);

        checkbox_eng_desen_pic = new QCheckBox(form_pupitre);
        checkbox_eng_desen_pic->setObjectName(QStringLiteral("checkbox_eng_desen_pic"));

        layout_pupitre->setWidget(4, QFormLayout::FieldRole, checkbox_eng_desen_pic);

        checkbox_boton2 = new QCheckBox(form_pupitre);
        checkbox_boton2->setObjectName(QStringLiteral("checkbox_boton2"));

        layout_pupitre->setWidget(5, QFormLayout::FieldRole, checkbox_boton2);

        checkbox_boton3 = new QCheckBox(form_pupitre);
        checkbox_boton3->setObjectName(QStringLiteral("checkbox_boton3"));

        layout_pupitre->setWidget(6, QFormLayout::FieldRole, checkbox_boton3);

        checkbox_graba_pic = new QCheckBox(form_pupitre);
        checkbox_graba_pic->setObjectName(QStringLiteral("checkbox_graba_pic"));

        layout_pupitre->setWidget(7, QFormLayout::FieldRole, checkbox_graba_pic);

        checkbox_acc_arch = new QCheckBox(form_pupitre);
        checkbox_acc_arch->setObjectName(QStringLiteral("checkbox_acc_arch"));

        layout_pupitre->setWidget(8, QFormLayout::FieldRole, checkbox_acc_arch);

        checkbox_sel_vent1 = new QCheckBox(form_pupitre);
        checkbox_sel_vent1->setObjectName(QStringLiteral("checkbox_sel_vent1"));

        layout_pupitre->setWidget(9, QFormLayout::FieldRole, checkbox_sel_vent1);

        checkbox_sel_vent2 = new QCheckBox(form_pupitre);
        checkbox_sel_vent2->setObjectName(QStringLiteral("checkbox_sel_vent2"));

        layout_pupitre->setWidget(10, QFormLayout::FieldRole, checkbox_sel_vent2);

        checkbox_sen_fija = new QCheckBox(form_pupitre);
        checkbox_sen_fija->setObjectName(QStringLiteral("checkbox_sen_fija"));

        layout_pupitre->setWidget(11, QFormLayout::FieldRole, checkbox_sen_fija);

        spin_contador_pupitre = new QSpinBox(form_pupitre);
        spin_contador_pupitre->setObjectName(QStringLiteral("spin_contador_pupitre"));
        spin_contador_pupitre->setEnabled(false);
        sizePolicy2.setHeightForWidth(spin_contador_pupitre->sizePolicy().hasHeightForWidth());
        spin_contador_pupitre->setSizePolicy(sizePolicy2);
        spin_contador_pupitre->setMaximum(255);

        layout_pupitre->setWidget(2, QFormLayout::FieldRole, spin_contador_pupitre);


        verticalLayout_3->addWidget(form_pupitre);

        btn_enviar_pupitre = new QPushButton(simuladorcomuClass);
        btn_enviar_pupitre->setObjectName(QStringLiteral("btn_enviar_pupitre"));

        verticalLayout_3->addWidget(btn_enviar_pupitre);


        horizontalLayout_11->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, 0, -1);
        widget_puerto_gps = new QWidget(simuladorcomuClass);
        widget_puerto_gps->setObjectName(QStringLiteral("widget_puerto_gps"));
        sizePolicy.setHeightForWidth(widget_puerto_gps->sizePolicy().hasHeightForWidth());
        widget_puerto_gps->setSizePolicy(sizePolicy);
        layout_puerto_gps = new QHBoxLayout(widget_puerto_gps);
        layout_puerto_gps->setSpacing(6);
        layout_puerto_gps->setContentsMargins(11, 11, 11, 11);
        layout_puerto_gps->setObjectName(QStringLiteral("layout_puerto_gps"));
        layout_puerto_gps->setContentsMargins(0, 0, 0, 0);
        lbl_gps = new QLabel(widget_puerto_gps);
        lbl_gps->setObjectName(QStringLiteral("lbl_gps"));
        lbl_gps->setFont(font);

        layout_puerto_gps->addWidget(lbl_gps);

        line_4 = new QFrame(widget_puerto_gps);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        layout_puerto_gps->addWidget(line_4);

        lbl_puerto_gps = new QLabel(widget_puerto_gps);
        lbl_puerto_gps->setObjectName(QStringLiteral("lbl_puerto_gps"));

        layout_puerto_gps->addWidget(lbl_puerto_gps);

        lineedit_puerto_gps = new QLineEdit(widget_puerto_gps);
        lineedit_puerto_gps->setObjectName(QStringLiteral("lineedit_puerto_gps"));

        layout_puerto_gps->addWidget(lineedit_puerto_gps);

        btn_conectar_gps = new QPushButton(widget_puerto_gps);
        btn_conectar_gps->setObjectName(QStringLiteral("btn_conectar_gps"));

        layout_puerto_gps->addWidget(btn_conectar_gps);


        verticalLayout_4->addWidget(widget_puerto_gps, 0, Qt::AlignTop);

        form_gps = new QWidget(simuladorcomuClass);
        form_gps->setObjectName(QStringLiteral("form_gps"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(form_gps->sizePolicy().hasHeightForWidth());
        form_gps->setSizePolicy(sizePolicy4);
        formLayout = new QFormLayout(form_gps);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lbl_hora = new QLabel(form_gps);
        lbl_hora->setObjectName(QStringLiteral("lbl_hora"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lbl_hora);

        lbl_estado_gps = new QLabel(form_gps);
        lbl_estado_gps->setObjectName(QStringLiteral("lbl_estado_gps"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lbl_estado_gps);

        groupbox_estado_gps = new QGroupBox(form_gps);
        groupbox_estado_gps->setObjectName(QStringLiteral("groupbox_estado_gps"));
        groupbox_estado_gps->setEnabled(false);
        groupbox_estado_gps->setCheckable(false);
        horizontalLayout_13 = new QHBoxLayout(groupbox_estado_gps);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(9, 0, 0, 0);
        radiobut_active_gps = new QRadioButton(groupbox_estado_gps);
        radiobut_active_gps->setObjectName(QStringLiteral("radiobut_active_gps"));

        horizontalLayout_13->addWidget(radiobut_active_gps);

        radiobut_void_gps = new QRadioButton(groupbox_estado_gps);
        radiobut_void_gps->setObjectName(QStringLiteral("radiobut_void_gps"));

        horizontalLayout_13->addWidget(radiobut_void_gps);


        formLayout->setWidget(1, QFormLayout::FieldRole, groupbox_estado_gps);

        lbl_latitud = new QLabel(form_gps);
        lbl_latitud->setObjectName(QStringLiteral("lbl_latitud"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lbl_latitud);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        spinbox_latitud_gps = new QSpinBox(form_gps);
        spinbox_latitud_gps->setObjectName(QStringLiteral("spinbox_latitud_gps"));
        sizePolicy2.setHeightForWidth(spinbox_latitud_gps->sizePolicy().hasHeightForWidth());
        spinbox_latitud_gps->setSizePolicy(sizePolicy2);
        spinbox_latitud_gps->setMinimum(-90);
        spinbox_latitud_gps->setMaximum(90);

        horizontalLayout_14->addWidget(spinbox_latitud_gps);

        spinbox_latitud_deg_gps = new QDoubleSpinBox(form_gps);
        spinbox_latitud_deg_gps->setObjectName(QStringLiteral("spinbox_latitud_deg_gps"));
        sizePolicy1.setHeightForWidth(spinbox_latitud_deg_gps->sizePolicy().hasHeightForWidth());
        spinbox_latitud_deg_gps->setSizePolicy(sizePolicy1);
        spinbox_latitud_deg_gps->setProperty("showGroupSeparator", QVariant(false));
        spinbox_latitud_deg_gps->setDecimals(3);

        horizontalLayout_14->addWidget(spinbox_latitud_deg_gps);

        groupbox_latitud_gps = new QGroupBox(form_gps);
        groupbox_latitud_gps->setObjectName(QStringLiteral("groupbox_latitud_gps"));
        horizontalLayout_15 = new QHBoxLayout(groupbox_latitud_gps);
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        radiobut_latidud_gps_n = new QRadioButton(groupbox_latitud_gps);
        radiobut_latidud_gps_n->setObjectName(QStringLiteral("radiobut_latidud_gps_n"));

        horizontalLayout_15->addWidget(radiobut_latidud_gps_n);

        radiobut_latidud_gps_s = new QRadioButton(groupbox_latitud_gps);
        radiobut_latidud_gps_s->setObjectName(QStringLiteral("radiobut_latidud_gps_s"));

        horizontalLayout_15->addWidget(radiobut_latidud_gps_s);


        horizontalLayout_14->addWidget(groupbox_latitud_gps);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_14);

        lbl_longitud = new QLabel(form_gps);
        lbl_longitud->setObjectName(QStringLiteral("lbl_longitud"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lbl_longitud);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        spinbox_longitud_gps = new QSpinBox(form_gps);
        spinbox_longitud_gps->setObjectName(QStringLiteral("spinbox_longitud_gps"));
        sizePolicy2.setHeightForWidth(spinbox_longitud_gps->sizePolicy().hasHeightForWidth());
        spinbox_longitud_gps->setSizePolicy(sizePolicy2);
        spinbox_longitud_gps->setMinimum(-180);
        spinbox_longitud_gps->setMaximum(180);

        horizontalLayout_16->addWidget(spinbox_longitud_gps);

        spinbox_longitud_deg_gps = new QDoubleSpinBox(form_gps);
        spinbox_longitud_deg_gps->setObjectName(QStringLiteral("spinbox_longitud_deg_gps"));
        sizePolicy1.setHeightForWidth(spinbox_longitud_deg_gps->sizePolicy().hasHeightForWidth());
        spinbox_longitud_deg_gps->setSizePolicy(sizePolicy1);
        spinbox_longitud_deg_gps->setDecimals(3);

        horizontalLayout_16->addWidget(spinbox_longitud_deg_gps);

        groupbox_longitud_gps = new QGroupBox(form_gps);
        groupbox_longitud_gps->setObjectName(QStringLiteral("groupbox_longitud_gps"));
        horizontalLayout_18 = new QHBoxLayout(groupbox_longitud_gps);
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        radiobut_longitud_gps_w = new QRadioButton(groupbox_longitud_gps);
        radiobut_longitud_gps_w->setObjectName(QStringLiteral("radiobut_longitud_gps_w"));

        horizontalLayout_18->addWidget(radiobut_longitud_gps_w);

        radiobut_longitud_gps_e = new QRadioButton(groupbox_longitud_gps);
        radiobut_longitud_gps_e->setObjectName(QStringLiteral("radiobut_longitud_gps_e"));

        horizontalLayout_18->addWidget(radiobut_longitud_gps_e);


        horizontalLayout_16->addWidget(groupbox_longitud_gps);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_16);

        lbl_nudos_gps = new QLabel(form_gps);
        lbl_nudos_gps->setObjectName(QStringLiteral("lbl_nudos_gps"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lbl_nudos_gps);

        label_13 = new QLabel(form_gps);
        label_13->setObjectName(QStringLiteral("label_13"));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_13->setFont(font2);

        formLayout->setWidget(4, QFormLayout::FieldRole, label_13);

        lbl_grados_gps = new QLabel(form_gps);
        lbl_grados_gps->setObjectName(QStringLiteral("lbl_grados_gps"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lbl_grados_gps);

        label_14 = new QLabel(form_gps);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font2);

        formLayout->setWidget(5, QFormLayout::FieldRole, label_14);

        lbl_fecha_gps = new QLabel(form_gps);
        lbl_fecha_gps->setObjectName(QStringLiteral("lbl_fecha_gps"));

        formLayout->setWidget(6, QFormLayout::LabelRole, lbl_fecha_gps);

        label_15 = new QLabel(form_gps);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font2);

        formLayout->setWidget(6, QFormLayout::FieldRole, label_15);

        label_12 = new QLabel(form_gps);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_12);

        label_16 = new QLabel(form_gps);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font2);

        formLayout->setWidget(7, QFormLayout::FieldRole, label_16);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        spinbox_horas_gps = new QSpinBox(form_gps);
        spinbox_horas_gps->setObjectName(QStringLiteral("spinbox_horas_gps"));
        spinbox_horas_gps->setWrapping(false);
        spinbox_horas_gps->setMaximum(23);

        horizontalLayout_19->addWidget(spinbox_horas_gps);

        spinbox_minutos_gps = new QSpinBox(form_gps);
        spinbox_minutos_gps->setObjectName(QStringLiteral("spinbox_minutos_gps"));
        spinbox_minutos_gps->setMaximum(59);

        horizontalLayout_19->addWidget(spinbox_minutos_gps);

        spinbox_segundos_gps = new QSpinBox(form_gps);
        spinbox_segundos_gps->setObjectName(QStringLiteral("spinbox_segundos_gps"));
        spinbox_segundos_gps->setMaximum(59);

        horizontalLayout_19->addWidget(spinbox_segundos_gps);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_19);


        verticalLayout_4->addWidget(form_gps);

        btn_enviar_gps = new QPushButton(simuladorcomuClass);
        btn_enviar_gps->setObjectName(QStringLiteral("btn_enviar_gps"));

        verticalLayout_4->addWidget(btn_enviar_gps);


        horizontalLayout_11->addLayout(verticalLayout_4);


        retranslateUi(simuladorcomuClass);

        QMetaObject::connectSlotsByName(simuladorcomuClass);
    } // setupUi

    void retranslateUi(QWidget *simuladorcomuClass)
    {
        simuladorcomuClass->setWindowTitle(QApplication::translate("simuladorcomuClass", "simuladorcomu", nullptr));
        label_7->setText(QApplication::translate("simuladorcomuClass", "SEON", nullptr));
        label_3->setText(QApplication::translate("simuladorcomuClass", "puerto", nullptr));
#ifndef QT_NO_TOOLTIP
        lineedit_puerto_seon->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineedit_puerto_seon->setInputMask(QString());
        lineedit_puerto_seon->setText(QApplication::translate("simuladorcomuClass", "COM8", nullptr));
        lineedit_puerto_seon->setPlaceholderText(QApplication::translate("simuladorcomuClass", "COM8", nullptr));
        btn_conectar_seon->setText(QApplication::translate("simuladorcomuClass", "conectar", nullptr));
        lbl_header1_seon->setText(QApplication::translate("simuladorcomuClass", "header1", nullptr));
        lbl_header_seon->setText(QApplication::translate("simuladorcomuClass", "header2", nullptr));
        lbl_distancia->setText(QApplication::translate("simuladorcomuClass", "distancia", nullptr));
        lbl_origen_dato->setText(QApplication::translate("simuladorcomuClass", "origen dato", nullptr));
        radiobut_origen_dato_0->setText(QApplication::translate("simuladorcomuClass", "0", nullptr));
        radiobut_origen_dato_1->setText(QApplication::translate("simuladorcomuClass", "1", nullptr));
        radiobut_origen_dato_2->setText(QApplication::translate("simuladorcomuClass", "2", nullptr));
        lbl_modo_pred->setText(QApplication::translate("simuladorcomuClass", "modo pred", nullptr));
        radiobut_modo_pred_0->setText(QApplication::translate("simuladorcomuClass", "pred = true, eng = false", nullptr));
        radiobut_modo_pred_1->setText(QApplication::translate("simuladorcomuClass", "pred = false, eng = true", nullptr));
        lbl_velocidad->setText(QApplication::translate("simuladorcomuClass", "velocidad", nullptr));
        lbl_zoom->setText(QApplication::translate("simuladorcomuClass", "zoom", nullptr));
        lbl_radar_act->setText(QApplication::translate("simuladorcomuClass", "radar acti", nullptr));
        checkbox_radar_acti->setText(QString());
        lbl_header2_seon->setText(QApplication::translate("simuladorcomuClass", "tipo blanco", nullptr));
        lbl_azimut_radar->setText(QApplication::translate("simuladorcomuClass", "azimut radar", nullptr));
        label_4->setText(QApplication::translate("simuladorcomuClass", ",", nullptr));
        lbl_dist_radar->setText(QApplication::translate("simuladorcomuClass", "distancia radar", nullptr));
        lbl_azimut_graf->setText(QApplication::translate("simuladorcomuClass", "azimut graf", nullptr));
        lbl_elevacion_graf->setText(QApplication::translate("simuladorcomuClass", "elevacion graf", nullptr));
        lbl_azimut_abs->setText(QApplication::translate("simuladorcomuClass", "azimut abs", nullptr));
        label_2->setText(QApplication::translate("simuladorcomuClass", ",", nullptr));
        lbl_elevacion_abs->setText(QApplication::translate("simuladorcomuClass", "elevacion abs", nullptr));
        label->setText(QApplication::translate("simuladorcomuClass", ",", nullptr));
        lbl_centro_grav->setText(QApplication::translate("simuladorcomuClass", "centro gravedad", nullptr));
        label_10->setText(QApplication::translate("simuladorcomuClass", "x", nullptr));
        spin_centro_gravedad_x->setSuffix(QString());
        label_11->setText(QApplication::translate("simuladorcomuClass", "y", nullptr));
        lbl_corrimiento->setText(QApplication::translate("simuladorcomuClass", "corrimiento", nullptr));
        radiobut_tipo_s->setText(QApplication::translate("simuladorcomuClass", "S", nullptr));
        radiobut_tipo_a->setText(QApplication::translate("simuladorcomuClass", "A", nullptr));
        radiobut_tipo_y->setText(QApplication::translate("simuladorcomuClass", "Y", nullptr));
        radiobut_tipo_t->setText(QApplication::translate("simuladorcomuClass", "T", nullptr));
        radiobut_tipo_u->setText(QApplication::translate("simuladorcomuClass", "U", nullptr));
        btn_enviar_seon->setText(QApplication::translate("simuladorcomuClass", "enviar", nullptr));
        label_8->setText(QApplication::translate("simuladorcomuClass", "BOTONERA", nullptr));
        label_6->setText(QApplication::translate("simuladorcomuClass", "puerto", nullptr));
        lineedit_puerto_botonera->setInputMask(QString());
        lineedit_puerto_botonera->setText(QApplication::translate("simuladorcomuClass", "COM6", nullptr));
        lineedit_puerto_botonera->setPlaceholderText(QApplication::translate("simuladorcomuClass", "COM6", nullptr));
        btn_conectar_botonera->setText(QApplication::translate("simuladorcomuClass", "conectar", nullptr));
        lbl_header1->setText(QApplication::translate("simuladorcomuClass", "header1", nullptr));
        lbl_header2->setText(QApplication::translate("simuladorcomuClass", "header2", nullptr));
        lbl_contador->setText(QApplication::translate("simuladorcomuClass", "contador", nullptr));
        lbl_ref_est->setText(QApplication::translate("simuladorcomuClass", "ref_est", nullptr));
        lbl_pant_datos->setText(QApplication::translate("simuladorcomuClass", "pant_datos", nullptr));
        lbl_pant_barrido->setText(QApplication::translate("simuladorcomuClass", "pant_barrido", nullptr));
        lbl_pant_normal->setText(QApplication::translate("simuladorcomuClass", "pant_normal", nullptr));
        lbl_vent_opt_lav->setText(QApplication::translate("simuladorcomuClass", "vent_opt_lav", nullptr));
        lbl_vent_opt_llimp->setText(QApplication::translate("simuladorcomuClass", "vent_opt_limp", nullptr));
        lbl_pa_ir->setText(QApplication::translate("simuladorcomuClass", "pa_ir", nullptr));
        lbl_cam_ir->setText(QApplication::translate("simuladorcomuClass", "cam_ir", nullptr));
        lbl_cam_diu->setText(QApplication::translate("simuladorcomuClass", "cam_diu", nullptr));
        lbl_zoom_amp->setText(QApplication::translate("simuladorcomuClass", "zoom_amp", nullptr));
        lbl_zoom_est->setText(QApplication::translate("simuladorcomuClass", "zoom_est", nullptr));
        lbl_foco_cerca->setText(QApplication::translate("simuladorcomuClass", "foco_cerca", nullptr));
        lbl_foco_lejos->setText(QApplication::translate("simuladorcomuClass", "foco_lejos", nullptr));
        lbl_video_cuant->setText(QApplication::translate("simuladorcomuClass", "video_cuant", nullptr));
        lbl_video_dif->setText(QApplication::translate("simuladorcomuClass", "video_dif", nullptr));
        lbl_video_nor->setText(QApplication::translate("simuladorcomuClass", "video_nor", nullptr));
        lbl_eng_cuant->setText(QApplication::translate("simuladorcomuClass", "eng_cuant", nullptr));
        lbl_eng_dif->setText(QApplication::translate("simuladorcomuClass", "eng_dif", nullptr));
        lbl_mod_fij->setText(QApplication::translate("simuladorcomuClass", "mod_fij", nullptr));
        lbl_mod_esc->setText(QApplication::translate("simuladorcomuClass", "mod_esc", nullptr));
        lbl_mod_est->setText(QApplication::translate("simuladorcomuClass", "mod_est", nullptr));
        checkbox_pant_normal->setText(QString());
        btn_enviar_botonera->setText(QApplication::translate("simuladorcomuClass", "enviar", nullptr));
        label_9->setText(QApplication::translate("simuladorcomuClass", "PUPITRE", nullptr));
        label_5->setText(QApplication::translate("simuladorcomuClass", "puerto", nullptr));
        lineedit_puerto_pupitre->setInputMask(QString());
        lineedit_puerto_pupitre->setText(QApplication::translate("simuladorcomuClass", "COM4", nullptr));
        lineedit_puerto_pupitre->setPlaceholderText(QApplication::translate("simuladorcomuClass", "COM4", nullptr));
        btn_conectar_pupitre->setText(QApplication::translate("simuladorcomuClass", "conectar", nullptr));
        lbl_header1_pupitre->setText(QApplication::translate("simuladorcomuClass", "header1", nullptr));
        lbl_header2_2->setText(QApplication::translate("simuladorcomuClass", "header2", nullptr));
        lbl_contador1->setText(QApplication::translate("simuladorcomuClass", "contador", nullptr));
        lbl_arrp->setText(QApplication::translate("simuladorcomuClass", "arrp", nullptr));
        lbl_eng_desen_pic->setText(QApplication::translate("simuladorcomuClass", "eng_desen_pic ", nullptr));
        lbl_boton2->setText(QApplication::translate("simuladorcomuClass", "boton2", nullptr));
        lbl_boton3->setText(QApplication::translate("simuladorcomuClass", "boton3", nullptr));
        lbl_graba_pic->setText(QApplication::translate("simuladorcomuClass", "graba_pic", nullptr));
        lbl_acc_arch->setText(QApplication::translate("simuladorcomuClass", "acc_arch", nullptr));
        lbl_sel_vent1->setText(QApplication::translate("simuladorcomuClass", "sel_vent1", nullptr));
        lbl_sel_vent2->setText(QApplication::translate("simuladorcomuClass", "sel_vent2", nullptr));
        lbl_sen_fija->setText(QApplication::translate("simuladorcomuClass", "sen_fija", nullptr));
        checkbox_arrp->setText(QString());
        checkbox_eng_desen_pic->setText(QString());
        checkbox_boton2->setText(QString());
        checkbox_boton3->setText(QString());
        checkbox_graba_pic->setText(QString());
        checkbox_acc_arch->setText(QString());
        checkbox_sel_vent1->setText(QString());
        checkbox_sel_vent2->setText(QString());
        checkbox_sen_fija->setText(QString());
        btn_enviar_pupitre->setText(QApplication::translate("simuladorcomuClass", "enviar", nullptr));
        lbl_gps->setText(QApplication::translate("simuladorcomuClass", "GPS", nullptr));
        lbl_puerto_gps->setText(QApplication::translate("simuladorcomuClass", "puerto", nullptr));
        lineedit_puerto_gps->setText(QApplication::translate("simuladorcomuClass", "COM10", nullptr));
        lineedit_puerto_gps->setPlaceholderText(QApplication::translate("simuladorcomuClass", "COM10", nullptr));
        btn_conectar_gps->setText(QApplication::translate("simuladorcomuClass", "conectar", nullptr));
        lbl_hora->setText(QApplication::translate("simuladorcomuClass", "hora", nullptr));
        lbl_estado_gps->setText(QApplication::translate("simuladorcomuClass", "estado", nullptr));
        groupbox_estado_gps->setTitle(QString());
        radiobut_active_gps->setText(QApplication::translate("simuladorcomuClass", "active", nullptr));
        radiobut_void_gps->setText(QApplication::translate("simuladorcomuClass", "void", nullptr));
        lbl_latitud->setText(QApplication::translate("simuladorcomuClass", "latitud", nullptr));
        spinbox_latitud_deg_gps->setPrefix(QApplication::translate("simuladorcomuClass", "deg ", nullptr));
        groupbox_latitud_gps->setTitle(QString());
        radiobut_latidud_gps_n->setText(QApplication::translate("simuladorcomuClass", "N", nullptr));
        radiobut_latidud_gps_s->setText(QApplication::translate("simuladorcomuClass", "S", nullptr));
        lbl_longitud->setText(QApplication::translate("simuladorcomuClass", "longitud", nullptr));
        spinbox_longitud_deg_gps->setPrefix(QApplication::translate("simuladorcomuClass", "deg ", nullptr));
        groupbox_longitud_gps->setTitle(QString());
        radiobut_longitud_gps_w->setText(QApplication::translate("simuladorcomuClass", "W", nullptr));
        radiobut_longitud_gps_e->setText(QApplication::translate("simuladorcomuClass", "E", nullptr));
        lbl_nudos_gps->setText(QApplication::translate("simuladorcomuClass", "nudos", nullptr));
        label_13->setText(QApplication::translate("simuladorcomuClass", "no necesario", nullptr));
        lbl_grados_gps->setText(QApplication::translate("simuladorcomuClass", "grados", nullptr));
        label_14->setText(QApplication::translate("simuladorcomuClass", "no necesario", nullptr));
        lbl_fecha_gps->setText(QApplication::translate("simuladorcomuClass", "fecha", nullptr));
        label_15->setText(QApplication::translate("simuladorcomuClass", "no necesario", nullptr));
        label_12->setText(QApplication::translate("simuladorcomuClass", "variacion mag", nullptr));
        label_16->setText(QApplication::translate("simuladorcomuClass", "no necesario", nullptr));
        spinbox_horas_gps->setSuffix(QApplication::translate("simuladorcomuClass", " hr", nullptr));
        spinbox_horas_gps->setPrefix(QString());
        spinbox_minutos_gps->setSuffix(QApplication::translate("simuladorcomuClass", " min", nullptr));
        spinbox_segundos_gps->setSuffix(QApplication::translate("simuladorcomuClass", " seg", nullptr));
        btn_enviar_gps->setText(QApplication::translate("simuladorcomuClass", "enviar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simuladorcomuClass: public Ui_simuladorcomuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULADORCOMU_H
