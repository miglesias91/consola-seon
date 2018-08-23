#include <consola-seon/include/lanchas.h>

namespace gui::hud {

lanchas::lanchas(const seon::aplicacion::configuracion::lanchas &config, QWidget *parent) :
    config(config), QWidget(parent) {
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->resize(this->parentWidget()->size());
    //this->resize(this->config.tamanio.ancho, this->config.tamanio.alto);
    //this->move(this->config.posicion.x, this->config.posicion.y);
}

lanchas::~lanchas() {}

void lanchas::paintEvent(QPaintEvent *paintEvent) {
    QPainter painter(this);
    painter.setPen(QPen(QBrush(QColor(this->config.trazo_lancha.color.r, this->config.trazo_lancha.color.g, this->config.trazo_lancha.color.b)), this->config.trazo_lancha.grosor, Qt::SolidLine, Qt::RoundCap));

    QVector<QPoint> vertices;

    vertices.push_back(QPoint(31, 66));
    vertices.push_back(QPoint(31, 21));
    vertices.push_back(QPoint(21, 1));
    vertices.push_back(QPoint(11, 21));
    vertices.push_back(QPoint(11, 66));
    QPolygon lancha_arriba(vertices);
    painter.drawConvexPolygon(lancha_arriba);
    vertices.clear();

    vertices.push_back(QPoint(1, 101));
    vertices.push_back(QPoint(46, 101));
    vertices.push_back(QPoint(76, 91));
    vertices.push_back(QPoint(1, 91));
    QPolygon lancha_perfil_cuerpo(vertices);
    painter.drawConvexPolygon(lancha_perfil_cuerpo);
    vertices.clear();

    vertices.push_back(QPoint(31, 91));
    vertices.push_back(QPoint(31, 82));
    vertices.push_back(QPoint(51, 82));
    vertices.push_back(QPoint(51, 91));
    QPolygon lancha_perfil_sombrero(vertices);
    painter.drawConvexPolygon(lancha_perfil_sombrero);
    vertices.clear();
}
}