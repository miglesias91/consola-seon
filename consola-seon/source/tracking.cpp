#include <consola-seon/include/tracking.h>

namespace gui::hud {

tracking::tracking(const seon::aplicacion::configuracion::tracking &config, QWidget *parent) :
    config(config),
    mayor(new reticula(config.mayor, parent)), media(new reticula(config.media, parent)), menor(new reticula(config.menor, parent)),
    centro(new centro_gravedad(config.reticula_testigo, parent)),
    QWidget(parent) {
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->resize(this->parentWidget()->size());
    this->mayor->raise();
    this->media->raise();
    this->menor->raise();
    this->centro->raise();
    this->reticulas.push_back(this->mayor);
    this->reticulas.push_back(this->media);
    this->reticulas.push_back(this->menor);
    this->reticula_actual = this->reticulas.begin();
}

tracking::~tracking() {}

void tracking::agrandar() {
    if (this->reticula_actual == this->reticulas.begin()) {
        return;
    }

    (*this->reticula_actual)->setVisible(false);
    this->reticula_actual--;
    (*this->reticula_actual)->setVisible(true);
}

void tracking::achicar() {
    if (this->reticula_actual == (this->reticulas.end() - 1)) {
        return;
    }

    (*this->reticula_actual)->setVisible(false);
    this->reticula_actual++;
    (*this->reticula_actual)->setVisible(true);
}

void tracking::corrimiento(const seon::aplicacion::configuracion::posicion &corrimiento_reticula) {
    std::for_each(this->reticulas.begin(), this->reticulas.end(), [=](reticula *reticula) {
        reticula->corrimiento(corrimiento_reticula);
    });
}

void tracking::centro_de_gravedad(const seon::aplicacion::configuracion::posicion &posicion_centro) {

}

}