#pragma once

// stl
#include <algorithm>
#include <bitset>
#include <string>
#include <filesystem>

// herramientas
#include <utiles/include/FuncionesSistemaArchivos.h>
#include <utiles/include/Json.h>

typedef uint64_t big_uint;
typedef uint32_t uint;

namespace seon::aplicacion {

class configuracion {

public:

    // generales

    struct posicion {
        big_uint x, y;
    };

    struct tamanio {

        void levantar(herramientas::utiles::Json * json) {
            this->alto = json->getAtributoValorUint("alto");
            this->ancho = json->getAtributoValorUint("ancho");
        }

        big_uint ancho, alto;
    };

    struct ventana {
        
        void levantar(herramientas::utiles::Json * json) {
            this->posicion.x = json->getAtributoValorUint("x");
            this->posicion.y = json->getAtributoValorUint("y");
            this->tamanio.alto = json->getAtributoValorUint("alto");
            this->tamanio.ancho = json->getAtributoValorUint("ancho");
        }

        posicion posicion;
        tamanio tamanio;
    };

    struct color {

        void levantar(herramientas::utiles::Json * json) {
            this->nombre = json->getAtributoValorString("nombre");
            this->r = json->getAtributoValorUint("r");
            this->g = json->getAtributoValorUint("g");
            this->b = json->getAtributoValorUint("b");
        }

        std::string nombre;
        unsigned char r, g, b;
    };

    // gui

    struct elemento{

        void levantar(herramientas::utiles::Json * json) {

            herramientas::utiles::Json * json_color = nullptr;

            json_color = json->getAtributoValorJson("color_primario");
            this->color_primario.levantar(json_color);
            delete json_color;

            json_color = json->getAtributoValorJson("color_secundario");
            this->color_secundario.levantar(json_color);
            delete json_color;

            this->recuadro.posicion.x = json->getAtributoValorUint("x");
            this->recuadro.posicion.y = json->getAtributoValorUint("y");
            this->recuadro.tamanio.ancho = json->getAtributoValorUint("ancho");
            this->recuadro.tamanio.alto = json->getAtributoValorUint("alto");

            this->nombre = json->getAtributoValorString("nombre");
            this->id = json->getAtributoValorUint("id");
            this->id_padre = json->getAtributoValorUint("id_padre");
        }

        big_uint id, id_padre;
        std::string nombre;
        ventana recuadro;
        color color_primario;
        color color_secundario;
    };

    struct gui {

        void levantar(const std::string & path_configuracion) {

            this->path = path_configuracion;
            herramientas::utiles::FuncionesSistemaArchivos::leer(path_configuracion, this->detallado);

            herramientas::utiles::Json configuracion_json(this->detallado);

            herramientas::utiles::Json * json_ventana = nullptr;

            json_ventana = configuracion_json.getAtributoValorJson("area_video");
            this->area_video.levantar(json_ventana);
            delete json_ventana;

            json_ventana = configuracion_json.getAtributoValorJson("panel_superior");
            this->panel_superior.levantar(json_ventana);
            delete json_ventana;

            json_ventana = configuracion_json.getAtributoValorJson("panel_lateral");
            this->panel_lateral.levantar(json_ventana);
            delete json_ventana;

            std::vector<herramientas::utiles::Json*> json_elementos = configuracion_json.getAtributoArrayJson("elementos");

            std::for_each(json_elementos.begin(), json_elementos.end(),
                [this](herramientas::utiles::Json * json_elemento)
            {
                elemento nuevo_elemento;
                nuevo_elemento.levantar(json_elemento);

                this->elementos.push_back(nuevo_elemento);
                delete json_elemento;
            });
            json_elementos.clear();
        }

        std::vector<elemento> elementos;
        ventana area_video;
        ventana panel_superior;
        ventana panel_lateral;

        std::string detallado;
        std::experimental::filesystem::path path;
    };

    // video

    enum modo { render_0 = 0, render_1 = 1, render_2 = 2 };

    struct reticula {

        void levantar(herramientas::utiles::Json * json) {

            this->tamanio.alto = json->getAtributoValorUint("alto");
            this->tamanio.ancho = json->getAtributoValorUint("ancho");
            this->ancho_linea = json->getAtributoValorUint("ancho_linea");
            this->id = json->getAtributoValorUint("id");
        }

        tamanio tamanio;
        uint ancho_linea;
        big_uint id;
    };

    struct testigo {

        void levantar(herramientas::utiles::Json * json) {

            this->reticula.tamanio.alto = json->getAtributoValorUint("alto");
            this->reticula.tamanio.ancho = json->getAtributoValorUint("ancho");
            this->reticula.ancho_linea = json->getAtributoValorUint("ancho_linea");
            this->por_default.x = json->getAtributoValorUint("x_default");
            this->por_default.y = json->getAtributoValorUint("y_default");
        }

        reticula reticula;
        posicion por_default;
    };

    struct video {

        void levantar(const std::string & path_configuracion) {
            this->path = path_configuracion;
            herramientas::utiles::FuncionesSistemaArchivos::leer(path_configuracion, this->detallado);

            herramientas::utiles::Json configuracion_json(this->detallado);

            herramientas::utiles::Json * json_resolucion = configuracion_json.getAtributoValorJson("resolucion");
            this->resolucion.levantar(json_resolucion);
            delete json_resolucion;

            this->canal = configuracion_json.getAtributoValorUint("canal");
            this->fps = configuracion_json.getAtributoValorUint("fps");
            this->render = modo(configuracion_json.getAtributoValorUint("render"));

            herramientas::utiles::Json * json_reticula = nullptr;

            json_reticula = configuracion_json.getAtributoValorJson("reticula_mayor");
            this->mayor.levantar(json_reticula);
            delete json_reticula;

            json_reticula = configuracion_json.getAtributoValorJson("reticula_media");
            this->media.levantar(json_reticula);
            delete json_reticula;

            json_reticula = configuracion_json.getAtributoValorJson("reticula_menor");
            this->menor.levantar(json_reticula);
            delete json_reticula;

            herramientas::utiles::Json * json_testigo = nullptr;

            json_testigo = configuracion_json.getAtributoValorJson("testigo");
            this->testigo.levantar(json_testigo);

            delete json_testigo;
        }

        tamanio resolucion;
        uint canal, fps;
        reticula mayor, menor, media;
        modo render;
        testigo testigo;

        std::string detallado;
        std::experimental::filesystem::path path;
    };

    // tramas

    struct serial {
        uint puerto, baudrate;
        std::string paridad;
        std::bitset<1> bit;
    };

    struct sincro {
        uint encabezado, cola;
    };

    struct trama {

        void levantar(herramientas::utiles::Json * json) {
            herramientas::utiles::Json *  json_serial = json->getAtributoValorJson("serial");

            this->serial.puerto = json_serial->getAtributoValorUint("puerto");
            this->serial.baudrate = json_serial->getAtributoValorUint("baudrate");
            this->serial.paridad = json_serial->getAtributoValorString("paridad");
            this->serial.bit = std::bitset<1>(json_serial->getAtributoValorString("bit"));

            delete json_serial;

            herramientas::utiles::Json *  json_sincro = json->getAtributoValorJson("sincro");

            this->sincro.encabezado = json_sincro->getAtributoValorUint("encabezado");
            this->sincro.cola = json_sincro->getAtributoValorUint("cola");

            delete json_sincro;

            this->busqueda = json->getAtributoValorString("busqueda");
            this->bidireccional = json->getAtributoValorBool("bidireccional");
            this->largo = json->getAtributoValorUint("largo");
        }

        serial serial;
        std::string busqueda;
        bool bidireccional;
        big_uint largo;
        sincro sincro;
    };

    struct tramas {

        void levantar(const std::string & path_configuracion) {
            this->path = path_configuracion;
            herramientas::utiles::FuncionesSistemaArchivos::leer(path_configuracion, this->detallado);

            herramientas::utiles::Json configuracion_json(this->detallado);

            herramientas::utiles::Json * trama = nullptr;
                
            trama = configuracion_json.getAtributoValorJson("gps");
            this->gps.levantar(trama);
            delete trama;

            trama = configuracion_json.getAtributoValorJson("pupitre");
            this->pupitre.levantar(trama);
            delete trama;

            trama = configuracion_json.getAtributoValorJson("pulsadores");
            this->pulsadores.levantar(trama);
            delete trama;

            trama = configuracion_json.getAtributoValorJson("seon");
            this->seon.levantar(trama);
            delete trama;
        }

        trama gps;
        trama pupitre;
        trama pulsadores;
        trama seon;

        std::string detallado;
        std::experimental::filesystem::path path;
    };

    struct logger {
        bool activado;
        std::experimental::filesystem::path path;
        std::string detallado;
    };

    configuracion();
    configuracion(const std::string & path_configuracion);
    virtual ~configuracion();

    bool levantar(const std::string & path_configuracion);

    std::string detallado();

    gui config_gui;
    video config_video;
    tramas config_tramas;
    logger config_logger;

private:
};

};

