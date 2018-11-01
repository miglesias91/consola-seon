#include <consola-seon/include/lanchas.h>

// qt
#include <qvector2d.h>
#include <qmatrix4x4.h>

namespace gui::hud {

lanchas::lanchas(const seon::aplicacion::configuracion::lanchas &config, QWidget *parent) :
    config(config), azimut_lancha(0), elevacion_lancha(0), QWidget(parent) {
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setAttribute(Qt::WA_OpaquePaintEvent, false);

    this->resize(this->parentWidget()->size());
    this->move(this->config.posicion.x, this->config.posicion.y);
    this->setParent(parent);
}

lanchas::~lanchas() {}

void lanchas::azimut(const uint8_t &valor) {
    this->azimut_lancha = valor;
}

void lanchas::elevacion(const uint8_t &valor) {
    this->elevacion_lancha = valor;
}

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

    painter.setPen(QPen(QBrush(QColor(this->config.trazo_orientacion.color.r, this->config.trazo_orientacion.color.g, this->config.trazo_orientacion.color.b)), this->config.trazo_orientacion.grosor, Qt::SolidLine, Qt::RoundCap));

    // dibujo orientacion azimut
    int32_t orientacion_azimut_x = 0, orientacion_azimut_y = this->config.largo_trazo_orientacion;
    this->rotar(this->azimut_lancha, &orientacion_azimut_x, &orientacion_azimut_y);
    painter.drawLine(21, 44, 21 + orientacion_azimut_x, 44 - orientacion_azimut_y);

    // dibujo orientacion elevacion
    int32_t orientacion_elevacion_x = this->config.largo_trazo_orientacion, orientacion_elevacion_y = 0;
    this->rotar(this->elevacion_lancha, &orientacion_elevacion_x, &orientacion_elevacion_y);
    painter.drawLine(41, 77, 41 + orientacion_elevacion_x, 77 + orientacion_elevacion_y);
}

void lanchas::rotar(const uint8_t & angulo, int32_t * x, int32_t * y) const {
    double_t seno = std::sin(angulo * 0.0174533);  // paso a radianes
    double_t coseno = std::cos(angulo * 0.0174533);  // paso a radianes

    int32_t nuevo_x = *x * coseno - *y * seno;
    int32_t nuevo_y = *x * seno + *y * coseno;

    *x = nuevo_x;
    *y = nuevo_y;
}
}