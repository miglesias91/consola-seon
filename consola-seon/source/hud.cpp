#include <consola-seon/include/hud.h>

namespace gui::hud {

hud::hud(const seon::aplicacion::configuracion::ventana &config_hud, const seon::aplicacion::configuracion::video &config_video, QWidget * parent) :
    config_hud(config_hud), config_video(config_video),
    QWidget(parent) {

    this->resize(this->config_hud.tamanio.ancho, this->config_hud.tamanio.alto);
    this->move(this->config_hud.posicion.x, this->config_hud.posicion.y);
}

hud::~hud() {}

void hud::tabla(radar *tabla_radar) {
    this->tabla_radar = tabla_radar;
}
radar* hud::tabla() const {
    return this->tabla_radar;
}

void hud::dibujo(lanchas *dibujo_lanchas) {
    this->dibujo_lanchas = dibujo_lanchas;
}
lanchas* hud::dibujo() const {
    return this->dibujo_lanchas;
}

void hud::reticulas(tracking *reticulas_tracking) {
    this->reticulas_tracking = reticulas_tracking;
}
tracking* hud::reticulas() const {
    return this->reticulas_tracking;
}

}