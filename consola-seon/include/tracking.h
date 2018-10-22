#pragma once

// qt
#include <QtWidgets>

// aplicacion
#include <aplicacion/include/configuracion.h>

namespace gui::hud {

class reticula : public QWidget {
    Q_OBJECT
public:
    reticula(const seon::aplicacion::configuracion::reticula &config, QWidget *parent = nullptr)
    : config(config), QWidget(parent) {
        this->corrimiento_lineas.x = 0;
        this->corrimiento_lineas.y = 0;
        this->resize(this->parentWidget()->size());
    }

    virtual ~reticula() {};

    void corrimiento(const seon::aplicacion::configuracion::posicion &corrimiento_lineas) {
        this->corrimiento_lineas = corrimiento_lineas;
    }

protected:
    void paintEvent(QPaintEvent *paintEvent) override {
        int32_t x = 0;
        int32_t y = 0;
        int32_t ancho = this->parentWidget()->size().width();
        int32_t alto = this->parentWidget()->size().height();

        int32_t esquina_izq_arriba_x = x;
        int32_t esquina_izq_arriba_y = y;
        int32_t esquina_der_abajo_x = x + ancho;
        int32_t esquina_der_abajo_y = y + alto;

        int32_t centro_x = ((esquina_der_abajo_x - esquina_izq_arriba_x) / 2) + this->corrimiento_lineas.x;
        int32_t centro_y = ((esquina_der_abajo_y - esquina_izq_arriba_y) / 2) + this->corrimiento_lineas.y;

        this->QWidget::paintEvent(paintEvent);
        QPainter painter(this);
        //painter.eraseRect(this->rect());
        painter.setPen(QPen(QBrush(QColor(this->config.linea.color.r, this->config.linea.color.g, this->config.linea.color.b)), this->config.linea.grosor));

        uint32_t mitad_alto = this->config.tamanio.alto / 2;
        uint32_t mitad_ancho = this->config.tamanio.ancho / 2;

        painter.drawLine(centro_x, esquina_izq_arriba_y, centro_x, centro_y - mitad_alto);  // linea arriba
        painter.drawLine(esquina_izq_arriba_x, centro_y, centro_x - mitad_ancho, centro_y);  // linea izquierda
        painter.drawLine(centro_x, esquina_der_abajo_y, centro_x, centro_y + mitad_alto);  // linea abajo
        painter.drawLine(esquina_der_abajo_x, centro_y, centro_x + mitad_ancho, centro_y);  // linea derecha
    }

private:
    seon::aplicacion::configuracion::reticula config;
    seon::aplicacion::configuracion::posicion corrimiento_lineas;
};

class centro_gravedad : public QWidget {
    Q_OBJECT
public:
    centro_gravedad(const seon::aplicacion::configuracion::testigo &config, QWidget *parent = nullptr)
        : config(config), pos_centro(config.por_default),QWidget(parent) {
        this->resize(this->parentWidget()->size());
    }

    virtual ~centro_gravedad() {};

    void posicion(const seon::aplicacion::configuracion::posicion &pos_centro) {
        this->pos_centro = pos_centro;
    }

protected:
    void paintEvent(QPaintEvent *paintEvent) override {
        int32_t x = this->pos_centro.x;
        int32_t y = this->pos_centro.y;
        int32_t ancho = this->config.tamanio.ancho;
        int32_t alto = this->config.tamanio.alto;

        int32_t esquina_izq_arriba_x = x;
        int32_t esquina_izq_arriba_y = y;
        int32_t esquina_der_abajo_x = x + ancho;
        int32_t esquina_der_abajo_y = y + alto;

        int32_t centro_x = ((esquina_der_abajo_x - esquina_izq_arriba_x) / 2) + x;
        int32_t centro_y = ((esquina_der_abajo_y - esquina_izq_arriba_y) / 2) + y;

        this->QWidget::paintEvent(paintEvent);
        QPainter painter(this);
        //painter.eraseRect(this->rect());
        painter.setPen(QPen(QBrush(QColor(this->config.linea.color.r, this->config.linea.color.g, this->config.linea.color.b)), this->config.linea.grosor));

        uint32_t espacio_alto = this->config.espacio_entre_lineas / 2;
        uint32_t espacio_ancho = this->config.espacio_entre_lineas / 2;

        painter.drawLine(centro_x, esquina_izq_arriba_y, centro_x, centro_y - espacio_alto);  // linea arriba
        painter.drawLine(esquina_izq_arriba_x, centro_y, centro_x - espacio_ancho, centro_y);  // linea izquierda
        painter.drawLine(centro_x, esquina_der_abajo_y, centro_x, centro_y + espacio_alto);  // linea abajo
        painter.drawLine(esquina_der_abajo_x, centro_y, centro_x + espacio_ancho, centro_y);  // linea derecha
    }

private:
    seon::aplicacion::configuracion::testigo config;

    seon::aplicacion::configuracion::posicion pos_centro;
};

class tracking : public QWidget {
    Q_OBJECT

public:
    tracking(const seon::aplicacion::configuracion::tracking &config, QWidget *parent = nullptr);
    virtual ~tracking();

    void agrandar();
    void achicar();
    void corrimiento(const seon::aplicacion::configuracion::posicion &corrimiento_reticula);
    void centro_de_gravedad(const seon::aplicacion::configuracion::posicion &posicion_centro);

private:
    seon::aplicacion::configuracion::tracking config;
    reticula *mayor, *media, *menor;
    centro_gravedad *centro;
    std::vector<reticula*> reticulas;
    std::vector<reticula*>::iterator reticula_actual;
};

}