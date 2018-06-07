#pragma once

// qt
#include <QtWidgets>
#include <QtConcurrent/qtconcurrentrun.h>

// comunicacion
#include <comunicacion/include/administrador.h>

Q_DECLARE_METATYPE(seon::comunicacion::trama_gps)
Q_DECLARE_METATYPE(seon::comunicacion::trama_pulsadores)
Q_DECLARE_METATYPE(seon::comunicacion::trama_pupitre)
Q_DECLARE_METATYPE(seon::comunicacion::trama_seon)

class comunicador : public QObject {
    Q_OBJECT

public:

    Q_SIGNAL void nuevo_mensaje_gps(const seon::comunicacion::trama_gps & trama);
    Q_SIGNAL void nuevo_mensaje_pulsadores(const seon::comunicacion::trama_pulsadores & trama);
    Q_SIGNAL void nuevo_mensaje_pupitre(const seon::comunicacion::trama_pupitre & trama);
    Q_SIGNAL void nuevo_mensaje_seon(const seon::comunicacion::trama_seon & trama);

    comunicador(seon::comunicacion::administrador * admin_comunicacion, QObject * parent = nullptr);

    virtual ~comunicador();

    void cortar();

    void iniciar_comunicaciones();

    void iniciar_comunicacion_gps();
    void iniciar_comunicacion_pulsadores();
    void iniciar_comunicacion_pupitre();
    void iniciar_comunicacion_seon();

private:

    seon::comunicacion::administrador * admin_comunicacion;
    bool hay_comunicacion;
    //QBasicTimer timer;
    //void timerEvent(QTimerEvent * evento);
};
