#include <consola-seon/include/visor_filmacion.h>

namespace gui {

visor_filmacion::visor_filmacion(QWidget * parent) : QWidget(parent) {
    //setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_DeleteOnClose);
}

void visor_filmacion::setear_imagen(const QImage & img) {

    if (!imagen_qt.isNull()) qDebug() << "Viewer dropped frame!";
    imagen_qt = img;
    if (imagen_qt.size() != size()) {
        setFixedSize(imagen_qt.size());
    }
    update();
}

void visor_filmacion::paintEvent(QPaintEvent *) {

    QPainter p(this);
    p.drawImage(0, 0, imagen_qt);

    imagen_qt = {};
}

}
