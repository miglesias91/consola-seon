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
}

tracking::~tracking() {}

}