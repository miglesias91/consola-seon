#include <consola-seon/include/visor_imagen.h>

namespace gui {

visor_imagen::visor_imagen(QWidget * parent) : QWidget(parent) {
    setAttribute(Qt::WA_OpaquePaintEvent);
}

void visor_imagen::setear_imagen(const QImage & img) {

    if (!imagen_qt.isNull()) qDebug() << "Viewer dropped frame!";
    imagen_qt = img;
    if (imagen_qt.size() != size()) {
        setFixedSize(imagen_qt.size());
    }
    update();
}

void visor_imagen::paintEvent(QPaintEvent *) {

    QPainter p(this);
    p.drawImage(0, 0, imagen_qt);

    imagen_qt = {};
}

}
