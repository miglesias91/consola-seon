#include <consola-seon/include/radar.h>

namespace gui::hud {

radar::radar(const seon::aplicacion::configuracion::radar &config, QLabel *distancia, QLabel *azimut, QLabel *tipo, QWidget *tabla, QWidget *parent) :
    config(config), distancia(distancia), azimut(azimut), tipo(tipo), tabla(tabla),
    QWidget(parent) {
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->resize(this->parentWidget()->size());
    this->tabla->move(this->config.posicion.x, this->config.posicion.y);
    this->tabla->resize(this->config.tamanio.ancho, this->config.tamanio.alto);
    this->tabla->setParent(parent);

    std::string stylesheet =
        "font: " + std::to_string(this->config.tipografia.grosor) + "pt \"" + this->config.tipografia.nombre + "\";" +
        "color: rgb(" + std::to_string(this->config.tipografia.color.r) + "," + std::to_string(this->config.tipografia.color.g) + "," + std::to_string(this->config.tipografia.color.b) + "); " +
        "border: " + std::to_string(this->config.trazo.grosor) + "px solid rgb( " + std::to_string(this->config.trazo.color.r) + "," + std::to_string(this->config.trazo.color.g) + "," + std::to_string(this->config.trazo.color.b) + ");";

    this->tabla->setStyleSheet(stylesheet.c_str());
}

radar::~radar() {}

}