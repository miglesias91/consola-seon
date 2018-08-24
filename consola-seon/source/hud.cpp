#include <consola-seon/include/hud.h>

namespace gui::hud {

hud::hud(const seon::aplicacion::configuracion::ventana &config_hud, const seon::aplicacion::configuracion::video &config_video, QWidget * parent) :
    config_hud(config_hud), config_video(config_video),
    QWidget(parent) {

    this->resize(this->config_hud.tamanio.ancho, this->config_hud.tamanio.alto);
    this->move(this->config_hud.posicion.x, this->config_hud.posicion.y);
}

hud::~hud() {}

}