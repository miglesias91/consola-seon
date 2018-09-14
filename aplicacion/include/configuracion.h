#pragma once

// stl
#include <algorithm>
#include <bitset>
#include <string>
#include <filesystem>
#include <unordered_map>

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

        std::string rgb() {
            return std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b);
        }

        std::string nombre;
        unsigned char r, g, b;
    };

    struct trazo {
        void levantar(herramientas::utiles::Json * json) {
            herramientas::utiles::Json * json_color = json->getAtributoValorJson("color");
            this->color.levantar(json_color);
            delete json_color;

            this->grosor = json->getAtributoValorUint("grosor");
        }

        color color;
        uint grosor;
    };

    struct tipografia {
        void levantar(herramientas::utiles::Json * json) {
            this->nombre = json->getAtributoValorString("nombre");
            this->grosor = json->getAtributoValorUint("grosor");

            herramientas::utiles::Json * json_color = json->getAtributoValorJson("color");
            this->color.levantar(json_color);
            delete json_color;
        }

        std::string nombre;
        uint32_t grosor;
        color color;
    };

    // gui

    struct elemento{

        void levantar(herramientas::utiles::Json * json) {

            herramientas::utiles::Json * json_color = nullptr;

            this->id = json->getAtributoValorString("id");
            this->texto = json->getAtributoValorString("texto");

            json_color = json->getAtributoValorJson("color_primario");
            this->color_primario.levantar(json_color);
            delete json_color;

            json_color = json->getAtributoValorJson("color_secundario");
            this->color_secundario.levantar(json_color);
            delete json_color;
        }

        std::string id, texto;
        color color_primario, color_secundario;
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

            std::vector<herramientas::utiles::Json*> json_colores = configuracion_json.getAtributoArrayJson("colores");

            std::for_each(json_colores.begin(), json_colores.end(),
                [this](herramientas::utiles::Json * json_color)
            {
                color nuevo_color;
                nuevo_color.levantar(json_color);

                this->colores[nuevo_color.nombre] = nuevo_color;
                delete json_color;
            });
            json_elementos.clear();
        }

        std::vector<elemento> elementos;
        ventana area_video;
        ventana panel_superior;
        ventana panel_lateral;
        std::unordered_map<std::string, color> colores;
        std::string detallado;
        std::experimental::filesystem::path path;
    };

    // video

    enum modo { render_0 = 0, render_1 = 1, render_2 = 2 };

    struct reticula {

        void levantar(herramientas::utiles::Json * json) {

            herramientas::utiles::Json * json_trazo = json->getAtributoValorJson("trazo");
            this->linea.levantar(json_trazo);
            delete json_trazo;

            this->tamanio.alto = json->getAtributoValorUint("alto");
            this->tamanio.ancho = json->getAtributoValorUint("ancho");
        }

        tamanio tamanio;
        trazo linea;
    };

    struct testigo : public reticula {

        void levantar(herramientas::utiles::Json * json) {
            this->reticula::levantar(json);

            this->por_default.x = json->getAtributoValorUint("x_default");
            this->por_default.y = json->getAtributoValorUint("y_default");
        }

        posicion por_default;
    };

    struct entrada_video {

        void levantar(herramientas::utiles::Json * json) {

            herramientas::utiles::Json * json_resolucion = json->getAtributoValorJson("resolucion");
            this->resolucion.levantar(json_resolucion);
            delete json_resolucion;

            this->fps = json->getAtributoValorUint("fps");
            this->path = json->getAtributoValorString("entrada");
        }

        tamanio resolucion;
        uint32_t fps;
        std::string path;
    };

    struct salida_video {
        
        void levantar(herramientas::utiles::Json * json) {

            herramientas::utiles::Json * json_resolucion = json->getAtributoValorJson("resolucion");
            this->resolucion.levantar(json_resolucion);
            delete json_resolucion;

            this->fps = json->getAtributoValorUint("fps");
            this->formato = json->getAtributoValorString("formato");
            this->carpeta = json->getAtributoValorString("carpeta");
        }

        tamanio resolucion;
        uint32_t fps;
        std::string formato, carpeta;
    };

    struct tracking {
        void levantar(herramientas::utiles::Json * json) {
            herramientas::utiles::Json * json_reticula = nullptr;

            json_reticula = json->getAtributoValorJson("reticula_mayor");
            this->mayor.levantar(json_reticula);
            delete json_reticula;

            json_reticula = json->getAtributoValorJson("reticula_media");
            this->media.levantar(json_reticula);
            delete json_reticula;

            json_reticula = json->getAtributoValorJson("reticula_menor");
            this->menor.levantar(json_reticula);
            delete json_reticula;

            json_reticula = json->getAtributoValorJson("testigo");
            this->reticula_testigo.levantar(json_reticula);
            delete json_reticula;
        }

        reticula mayor, menor, media;
        testigo reticula_testigo;
    };

    struct radar {
        void levantar(herramientas::utiles::Json * json) {
            this->posicion.x = json->getAtributoValorUint("x");
            this->posicion.y = json->getAtributoValorUint("y");
            this->tamanio.ancho = json->getAtributoValorUint("ancho");
            this->tamanio.alto = json->getAtributoValorUint("alto");

            herramientas::utiles::Json * json_tipografia = json->getAtributoValorJson("tipografia");
            this->tipografia.levantar(json_tipografia);
            delete json_tipografia;

            herramientas::utiles::Json * json_trazo = json->getAtributoValorJson("trazo");
            this->trazo.levantar(json_trazo);
            delete json_trazo;
        }

        posicion posicion;
        tamanio tamanio;
        tipografia tipografia;
        trazo trazo;
    };

    struct lanchas {
        void levantar(herramientas::utiles::Json * json) {
            this->posicion.x = json->getAtributoValorUint("x");
            this->posicion.y = json->getAtributoValorUint("y");
            this->tamanio.ancho = json->getAtributoValorUint("ancho");
            this->tamanio.alto = json->getAtributoValorUint("alto");

            herramientas::utiles::Json * json_trazo = nullptr;

            json_trazo = json->getAtributoValorJson("trazo_lancha");
            this->trazo_lancha.levantar(json_trazo);
            delete json_trazo;

            json_trazo = json->getAtributoValorJson("trazo_orientacion");
            this->trazo_orientacion.levantar(json_trazo);
            delete json_trazo;

            this->largo_trazo_orientacion = json->getAtributoValorUint("largo_trazo_orientacion");
        }

        posicion posicion;
        tamanio tamanio;
        trazo trazo_lancha, trazo_orientacion;
        uint32_t largo_trazo_orientacion;
    };

    struct video {

        void levantar(const std::string & path_configuracion) {
            this->path = path_configuracion;
            herramientas::utiles::FuncionesSistemaArchivos::leer(path_configuracion, this->detallado);

            herramientas::utiles::Json configuracion_json(this->detallado);

            herramientas::utiles::Json * json_filmacion = configuracion_json.getAtributoValorJson("filmacion");
            this->filmacion.levantar(json_filmacion);
            delete json_filmacion;

            herramientas::utiles::Json * json_grabacion = configuracion_json.getAtributoValorJson("grabacion");
            this->grabacion.levantar(json_grabacion);
            delete json_grabacion;

            this->canal = configuracion_json.getAtributoValorUint("canal");
            this->render = modo(configuracion_json.getAtributoValorUint("render"));

            herramientas::utiles::Json * json_tracking = configuracion_json.getAtributoValorJson("tracking");
            this->tracking.levantar(json_tracking);
            delete json_tracking;

            herramientas::utiles::Json * json_radar = configuracion_json.getAtributoValorJson("radar");
            this->radar.levantar(json_radar);
            delete json_radar;

            herramientas::utiles::Json * json_lanchas = configuracion_json.getAtributoValorJson("lanchas");
            this->lanchas.levantar(json_lanchas);
            delete json_lanchas;
        }

        entrada_video filmacion;
        salida_video grabacion;
        uint canal;
        modo render;
        tracking tracking;
        radar radar;
        lanchas lanchas;

        std::string detallado;
        std::experimental::filesystem::path path;
    };

    // tramas

    struct serial {
        uint baudrate;
        std::string puerto, paridad;
        std::bitset<1> bit;
    };

    struct sincro {
        uint encabezado, cola;
    };

    struct trama {

        void levantar(herramientas::utiles::Json * json) {
            herramientas::utiles::Json *  json_serial = json->getAtributoValorJson("serial");

            this->serial.puerto = json_serial->getAtributoValorString("puerto");
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

    struct comunicacion {

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
    comunicacion config_comunicacion;
    logger config_logger;

private:
};

};

