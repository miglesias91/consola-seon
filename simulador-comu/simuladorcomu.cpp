#include "simuladorcomu.h"

#include <bitset>

simuladorcomu::simuladorcomu(QWidget *parent)
    : QWidget(parent) {
    ui.setupUi(this);

    this->ui.form_seon->setDisabled(true);
    this->ui.form_botonera->setDisabled(true);
    this->ui.form_pupitre->setDisabled(true);

    this->ui.btn_enviar_seon->setDisabled(true);
    this->ui.btn_enviar_botonera->setDisabled(true);
    this->ui.btn_enviar_pupitre->setDisabled(true);

    this->setear_conexiones();
}

simuladorcomu::~simuladorcomu() {

}
bool simuladorcomu::conectar_seon() {

    std::string puerto = this->ui.lineedit_puerto_seon->text().toStdString();
    try {
        this->com_seon.setPort(puerto);
        this->com_seon.open();
    }
    catch (std::invalid_argument &e) {
        return false;
    }
    catch (serial::SerialException &e) {
        return false;
    }
    catch (serial::IOException &e) {
        return false;
    }

    this->ui.form_seon->setDisabled(false);
    this->ui.btn_enviar_seon->setDisabled(false);

    return true;
}

bool simuladorcomu::conectar_botonera() {

    std::string puerto = this->ui.lineedit_puerto_botonera->text().toStdString();
    try {
        this->com_botonera.setPort(puerto);
        this->com_botonera.open();
    }
    catch (std::invalid_argument &e) {
        return false;
    }
    catch (serial::SerialException &e) {
        return false;
    }
    catch (serial::IOException &e) {
        return false;
    }

    this->ui.form_botonera->setDisabled(false);
    this->ui.btn_enviar_botonera->setDisabled(false);

    return true;
}

bool simuladorcomu::conectar_pupitre() {

    std::string puerto = this->ui.lineedit_puerto_pupitre->text().toStdString();
    try {
        this->com_pupitre.setPort(puerto);
        this->com_pupitre.open();
    }
    catch (std::invalid_argument &e) {
        return false;
    }
    catch (serial::SerialException &e) {
        return false;
    }
    catch (serial::IOException &e) {
        return false;
    }

    this->ui.form_pupitre->setDisabled(false);
    this->ui.btn_enviar_pupitre->setDisabled(false);

    return true;
}

bool simuladorcomu::enviar_seon() {
    std::string trama(27, 'a');

    // header
    trama[0] = 0xeb;
    trama[1] = 0x90;

    // distancia
    std::string bits_distancia = std::bitset<16>(this->ui.spin_distancia->value()).to_string();
    std::bitset<8> distancia_1(bits_distancia.substr(0, 7));
    std::bitset<8> distancia_2(bits_distancia.substr(8, 15));

    trama[3] = distancia_1.to_ulong();
    trama[2] = distancia_2.to_ulong();

    // velocidad, origen dato, modo enganche-prediccion
    std::string bits_velocidad = std::bitset<16>(this->ui.spin_velocidad->value()).to_string();
    std::bitset<8> velocidad_1(bits_velocidad.substr(0, 7));
    std::bitset<8> velocidad_2(bits_velocidad.substr(8, 15));

    if (this->ui.radiobut_origen_dato_0->isChecked()) {
        velocidad_1.set(7, true);
        velocidad_1.set(6, false);
    }
    if (this->ui.radiobut_origen_dato_1->isChecked()) {
        velocidad_1.set(7, true);
        velocidad_1.set(6, true);
    }
    if (this->ui.radiobut_origen_dato_2->isChecked()) {
        velocidad_1.set(7, false);
        velocidad_1.set(6, true);
    }

    if (this->ui.radiobut_modo_pred_0->isChecked()) {
        velocidad_1.set(5, true);
        velocidad_1.set(4, true);
    }
    if (this->ui.radiobut_modo_pred_1->isChecked()) {
        velocidad_1.set(5, false);
        velocidad_1.set(4, false);
    }

    trama[5] = velocidad_1.to_ulong();
    trama[4] = velocidad_2.to_ulong();

    // zoom
    trama[6] = this->ui.spin_zoom->value();

    // radar activado, tipo blanco
    std::bitset<8> tipo_blanco(this->ui.spin_tipo_blanco->value());
    tipo_blanco.set(0, this->ui.checkbox_radar_acti->isChecked());

    // azimut radar
    std::string bits_azimut_radar_entero = std::bitset<16>(this->ui.spin_azimut_radar_entero->value()).to_string();
    std::bitset<8> azimut_radar_entero_1(bits_azimut_radar_entero.substr(0, 7));
    std::bitset<8> azimut_radar_entero_2(bits_azimut_radar_entero.substr(8, 15));

    trama[9] = azimut_radar_entero_1.to_ulong();
    trama[8] = azimut_radar_entero_2.to_ulong();
    trama[10] = this->ui.spin_azimut_radar_decimal->value();

    // distanacia radar
    std::string bits_distancia_radar = std::bitset<16>(this->ui.spin_distancia_radar->value()).to_string();
    std::bitset<8> distancia_radar_1(bits_distancia_radar.substr(0, 7));
    std::bitset<8> distancia_radar_2(bits_distancia_radar.substr(8, 15));

    trama[12] = distancia_radar_1.to_ulong();
    trama[11] = distancia_radar_2.to_ulong();

    // azimut grafico
    trama[13] = this->ui.spin_azimut_graf->value();

    // elevacion grafico
    trama[14] = this->ui.spin_elevacion_graf->value();

    // azimut absoluto
    std::string bits_azimut_absoluto_entero = std::bitset<16>(this->ui.spin_azimut_abs_entero->value()).to_string();
    std::bitset<8> azimut_absoluto_entero_1(bits_azimut_absoluto_entero.substr(0, 7));
    std::bitset<8> azimut_absoluto_entero_2(bits_azimut_absoluto_entero.substr(8, 15));

    trama[17] = azimut_absoluto_entero_1.to_ulong();
    trama[16] = azimut_absoluto_entero_2.to_ulong();
    trama[15] = this->ui.spin_azimut_abs_decimal->value();

    // elevacion absoluta
    std::string bits_elevacion_absoluta_entero = std::bitset<16>(this->ui.spin_elevacion_abs_entero->value()).to_string();
    std::bitset<8> elevacion_absoluta_entero_1(bits_elevacion_absoluta_entero.substr(0, 7));
    std::bitset<8> elevacion_absoluta_entero_2(bits_elevacion_absoluta_entero.substr(8, 15));

    trama[20] = elevacion_absoluta_entero_1.to_ulong();
    trama[19] = elevacion_absoluta_entero_2.to_ulong();
    trama[18] = this->ui.spin_elevacion_abs_decimal->value();

    // centro gravedad
    std::string bits_centro_gravedad_x = std::bitset<16>(this->ui.spin_centro_gravedad_x->value()).to_string();
    std::bitset<8> centro_gravedad_x_1(bits_centro_gravedad_x.substr(0, 7));
    std::bitset<8> centro_gravedad_x_2(bits_centro_gravedad_x.substr(8, 15));

    trama[22] = centro_gravedad_x_1.to_ulong();
    trama[21] = centro_gravedad_x_2.to_ulong();

    std::string bits_centro_gravedad_y = std::bitset<16>(this->ui.spin_centro_gravedad_y->value()).to_string();
    std::bitset<8> centro_gravedad_y_1(bits_centro_gravedad_y.substr(0, 7));
    std::bitset<8> centro_gravedad_y_2(bits_centro_gravedad_y.substr(8, 15));

    trama[24] = centro_gravedad_y_1.to_ulong();
    trama[23] = centro_gravedad_y_2.to_ulong();

    // corrimiento
    trama[25] = this->ui.spin_corrimiento_x->value();
    trama[26] = this->ui.spin_corrimiento_y->value();

    try {
        this->com_seon.write(trama);
    }
    catch (serial::PortNotOpenedException &e) {
        return false;
    }
    catch (serial::SerialException &e) {
        return false;
    }
    catch (serial::IOException &e) {
        return false;
    }

    return true;
}

bool simuladorcomu::enviar_botonera() {
    std::string trama(25, 'a');

    // header
    trama[0] = 0xeb;
    trama[1] = 0x90;

    // contador
    std::string bits_contador = std::bitset<16>(this->ui.spin_contador_botonera->value()).to_string();
    std::bitset<8> contador_1(bits_contador.substr(0, 7));
    std::bitset<8> contador_2(bits_contador.substr(8, 15));

    trama[2] = contador_1.to_ulong();
    trama[3] = contador_2.to_ulong();

    // flags
    trama[4] = this->ui.checkbox_ref_est->isChecked() ? 0x7a : 0x6a;
    trama[5] = this->ui.checkbox_pant_datos->isChecked() ? 0x7a : 0x6a;
    trama[6] = this->ui.checkbox_pant_barrido->isChecked() ? 0x7a : 0x6a;
    trama[7] = this->ui.checkbox_pant_normal->isChecked() ? 0x7a : 0x6a;
    trama[8] = this->ui.checkbox_vent_opt_lav->isChecked() ? 0x7a : 0x6a;
    trama[9] = this->ui.checkbox_vent_opt_limp->isChecked() ? 0x7a : 0x6a;
    trama[10] = this->ui.checkbox_pa_ir->isChecked() ? 0x7a : 0x6a;
    trama[11] = this->ui.checkbox_cam_ir->isChecked() ? 0x7a : 0x6a;
    trama[12] = this->ui.checkbox_cam_diu->isChecked() ? 0x7a : 0x6a;
    trama[13] = this->ui.checkbox_zoom_amp->isChecked() ? 0x7a : 0x6a;
    trama[14] = this->ui.checkbox_zoom_est->isChecked() ? 0x7a : 0x6a;
    trama[15] = this->ui.checkbox_foco_cerca->isChecked() ? 0x7a : 0x6a;
    trama[16] = this->ui.checkbox_foco_lejos->isChecked() ? 0x7a : 0x6a;
    trama[17] = this->ui.checkbox_video_cuant->isChecked() ? 0x7a : 0x6a;
    trama[18] = this->ui.checkbox_video_dif->isChecked() ? 0x7a : 0x6a;
    trama[19] = this->ui.checkbox_video_nor->isChecked() ? 0x7a : 0x6a;
    trama[20] = this->ui.checkbox_eng_cuant->isChecked() ? 0x7a : 0x6a;
    trama[21] = this->ui.checkbox_eng_dif->isChecked() ? 0x7a : 0x6a;
    trama[22] = this->ui.checkbox_mod_fij->isChecked() ? 0x7a : 0x6a;
    trama[23] = this->ui.checkbox_mod_esc->isChecked() ? 0x7a : 0x6a;
    trama[24] = this->ui.checkbox_mod_est->isChecked() ? 0x7a : 0x6a;

    try {
        this->com_botonera.write(trama);
    }
    catch (serial::PortNotOpenedException &e) {
        return false;
    }
    catch (serial::SerialException &e) {
        return false;
    }
    catch (serial::IOException &e) {
        return false;
    }

    return true;
}

bool simuladorcomu::enviar_pupitre() {
    std::string trama(12, 'a');

    // header
    trama[0] = 0xeb;
    trama[1] = 0x90;

    // contador
    trama[2] = this->ui.spin_contador_pupitre->value();

    // flags
    trama[3] = this->ui.checkbox_arrp->isChecked() ? 0x7a : 0x6a;
    trama[4] = this->ui.checkbox_eng_desen_pic->isChecked() ? 0x7a : 0x6a;
    trama[5] = this->ui.checkbox_boton2->isChecked() ? 0x7a : 0x6a;
    trama[6] = this->ui.checkbox_boton3->isChecked() ? 0x7a : 0x6a;
    trama[7] = this->ui.checkbox_graba_pic->isChecked() ? 0x7a : 0x6a;
    trama[8] = this->ui.checkbox_acc_arch->isChecked() ? 0x7a : 0x6a;
    trama[9] = this->ui.checkbox_sel_vent1->isChecked() ? 0x7a : 0x6a;
    trama[10] = this->ui.checkbox_sel_vent2->isChecked() ? 0x7a : 0x6a;
    trama[11] = this->ui.checkbox_sen_fija->isChecked() ? 0x7a : 0x6a;

    try {
        this->com_pupitre.write(trama);
    }
    catch (serial::PortNotOpenedException &e) {
        return false;
    }
    catch (serial::SerialException &e) {
        return false;
    }
    catch (serial::IOException &e) {
        return false;
    }

    return true;
}

void simuladorcomu::setear_conexiones() {
    QObject::connect(this->ui.btn_conectar_botonera, &QPushButton::released, this, &simuladorcomu::conectar_botonera);
    QObject::connect(this->ui.btn_conectar_seon, &QPushButton::released, this, &simuladorcomu::conectar_seon);
    QObject::connect(this->ui.btn_conectar_pupitre, &QPushButton::released, this, &simuladorcomu::conectar_pupitre);

    QObject::connect(this->ui.btn_enviar_botonera, &QPushButton::released, this, &simuladorcomu::enviar_botonera);
    QObject::connect(this->ui.btn_enviar_seon, &QPushButton::released, this, &simuladorcomu::enviar_seon);
    QObject::connect(this->ui.btn_enviar_pupitre, &QPushButton::released, this, &simuladorcomu::enviar_pupitre);
}
