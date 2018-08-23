#include <consola-seon/include/hud.h>

namespace gui::hud {

hud::hud(const seon::aplicacion::configuracion::ventana &config_hud, const seon::aplicacion::configuracion::video &config_video, QWidget * parent) :
    config_hud(config_hud), config_video(config_video),
    QWidget(parent) {

    this->resize(this->config_hud.tamanio.ancho, this->config_hud.tamanio.alto);
    this->move(this->config_hud.posicion.x, this->config_hud.posicion.y);


}

hud::~hud() {}

void hud::paintEvent(QPaintEvent * evento) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::green, 12, Qt::DashDotLine, Qt::RoundCap));
    painter.drawLine(0, 0, 600, 600);

    //painter.drawText()

    //std::for_each(this->sprites.begin(), this->sprites.end(), [=](gui::hud::sprite *sprite) {
    //    sprite->dibujar(painter);
    //});
}

}