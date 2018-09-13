#include <consola-seon/include/tracking.h>

namespace gui::hud {

tracking::tracking(const seon::aplicacion::configuracion::tracking &config, QWidget *parent) :
    config(config), mayor(new reticula(config.mayor, parent)), media(new reticula(config.media, parent)), menor(new reticula(config.menor, parent)),
    QWidget(parent) {
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->resize(this->parentWidget()->size());
    this->mayor->raise();
    this->media->raise();
    this->menor->raise();

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

}