
// stl
#include <iostream>
#include <filesystem>
#include <thread>

// catch2
#include <catch.hpp>

// comunicacion
#include <comunicacion/include/administrador.h>
#include <comunicacion/include/trama_gps.h>
#include <comunicacion/include/trama_pulsadores.h>

TEST_CASE("escribir_y_leer_datos", "comunicacion") {

    //previo a la ejecucion de este test, tienen que estar creados los puertos seriales virtuales COM1 y COM2:
    //COM1: puerto donde se recibe la info.
    //COM2: puerto donde se escribe la info.
    // info -- escribir --> COM3 -- viaja info --> COM4 -- leer --> info.

    std::string trama = "esto_son_los_datos_de_una_trama";

    seon::aplicacion::configuracion::trama config_trama;
    config_trama.bidireccional = true;
    config_trama.busqueda = "si";
    config_trama.largo = 50;
    config_trama.serial.baudrate = 57600;
    config_trama.serial.bit = 1;
    config_trama.serial.paridad = "0";
    config_trama.serial.puerto = "COM3";
    seon::comunicacion::SERIAL puerto_serial_entrada(config_trama);
    
    config_trama.serial.puerto = "COM4";
    seon::comunicacion::SERIAL puerto_serial_salida(config_trama);

    std::thread hilo_escritura([&puerto_serial_entrada, &trama]() {

        puerto_serial_entrada.escribir(trama);
        puerto_serial_entrada.escribir(trama);
    });

    std::string tira_de_datos_leida = "";

    std::thread hilo_escucha([&puerto_serial_salida, &tira_de_datos_leida]() {

        puerto_serial_salida.leer(tira_de_datos_leida);
        puerto_serial_salida.leer(tira_de_datos_leida);
    });

    hilo_escritura.join();
    hilo_escucha.join();

    REQUIRE(tira_de_datos_leida == trama+trama);
}

TEST_CASE("enviar_y_recibir_trama", "comunicacion") {

    //previo a la ejecucion de este test, tienen que estar creados los puertos seriales virtuales COM1 y COM2:
    //COM1: puerto donde se recibe la info.
    //COM2: puerto donde se escribe la info.
    // trama -- enviar --> COM3 -- viaja trama --> COM4 -- recibir --> trama.

    seon::aplicacion::configuracion::trama config_trama;
    config_trama.bidireccional = true;
    config_trama.busqueda = "si";
    config_trama.largo = 10;
    config_trama.serial.baudrate = 57600;
    config_trama.serial.bit = 1;
    config_trama.serial.paridad = "0";
    config_trama.serial.puerto = "COM3";
    seon::comunicacion::SERIAL puerto_serial_entrada(config_trama);

    config_trama.serial.puerto = "COM4";
    seon::comunicacion::SERIAL puerto_serial_salida(config_trama);

    std::thread hilo_envio([&puerto_serial_entrada]() {

        seon::comunicacion::trama_gps trama_a_enviar;

        trama_a_enviar.setear("0123456789");
        puerto_serial_entrada.enviar(&trama_a_enviar);

        trama_a_enviar.setear("9876543210");
        puerto_serial_entrada.enviar(&trama_a_enviar);
    });
    hilo_envio.join();

    seon::comunicacion::trama_gps trama_recibida;

    puerto_serial_salida.recibir(&trama_recibida);
    REQUIRE(trama_recibida.tira_de_datos == "0123456789");

    puerto_serial_salida.recibir(&trama_recibida);
    REQUIRE(trama_recibida.tira_de_datos == "9876543210");
}

TEST_CASE("trama_gps", "comunicacion") {
    seon::comunicacion::trama_gps trama;

    std::string oracion = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
    trama.setear(oracion);

    REQUIRE(trama.fecha.getStringAAAAMMDDHHmmSS() == "19980913081836");
    REQUIRE(trama.estado == "A");
    REQUIRE(trama.latitud.angulo == 3751.65);
    REQUIRE(trama.latitud.cardinalidad == "S");
    REQUIRE(trama.longitud.angulo == 14507.36);
    REQUIRE(trama.longitud.cardinalidad == "E");
    REQUIRE(trama.velocidad == 0.00);
    REQUIRE(trama.angulo == 360.00);
    REQUIRE(trama.variacion_magnetica.angulo == 11.3);
    REQUIRE(trama.variacion_magnetica.cardinalidad == "E");
    REQUIRE(trama.checksum == "62");
}

TEST_CASE("trama_pulsadores", "comunicacion") {
    seon::comunicacion::trama_pulsadores trama;

    std::vector<uint8_t> tira_de_datos = {
        0xeb, 0x90,  // headers
        0x00, 0x00,  // contador
        0x6a,  // ref_est
        0x6a, 0x6a, 0x6a,  // pantalla
        0x6a, 0x6a,  // ventana
        0x6a,  // pa_ir
        0x6a, 0x6a,  // camara
        0x6a, 0x6a,  // zoom
        0x6a, 0x6a,  // foco
        0x6a, 0x6a, 0x6a,  // video
        0x6a, 0x6a,  // engance
        0x6a, 0x6a, 0x6a };  // modo

    trama.setear(std::string(tira_de_datos.begin(), tira_de_datos.end()));

    REQUIRE(trama.header_1 == 235);
    REQUIRE(trama.header_2 == 144);
    REQUIRE(trama.contador == 0);
    REQUIRE(trama.ref_est == false);
    REQUIRE(trama.pantalla_datos == false);
    REQUIRE(trama.pantalla_barrido == false);
    REQUIRE(trama.pantalla_normal == false);
    REQUIRE(trama.ventana_optica_lava == false);
    REQUIRE(trama.ventana_optica_limpia == false);
    REQUIRE(trama.pa_ir == false);
    REQUIRE(trama.camara_ir == false);
    REQUIRE(trama.camara_diurna == false);
    REQUIRE(trama.zoom_amplio == false);
    REQUIRE(trama.zoom_estrecho == false);
    REQUIRE(trama.foco_cerca == false);
    REQUIRE(trama.foco_lejos == false);
    REQUIRE(trama.video_cuantificado == false);
    REQUIRE(trama.video_diferenciado == false);
    REQUIRE(trama.video_normal == false);
    REQUIRE(trama.enganche_cuantificado == false);
    REQUIRE(trama.enganche_diferenciado == false);
    REQUIRE(trama.modo_fijo == false);
    REQUIRE(trama.modo_esclavo == false);
    REQUIRE(trama.modo_estable == false);
}

TEST_CASE("trama_pupitre", "comunicacion") {
    seon::comunicacion::trama_pupitre trama;

    std::vector<uint8_t> tira_de_datos = {
        0xeb, 0x90,  // headers
        0x00,  // contador
        0x6a,  // arrp
        0x6a,  // enganche_desenganche_pic
        0x6a, 0x6a,  // botones
        0x6a, 0x6a,  // graba y acc
        0x6a, 0x6a,  // seleccion ventana
        0x6a };  // sen fija

    trama.setear(std::string(tira_de_datos.begin(), tira_de_datos.end()));

    REQUIRE(trama.header_1 == 235);
    REQUIRE(trama.header_2 == 144);
    REQUIRE(trama.contador == 0);
    REQUIRE(trama.arrp == false);
    REQUIRE(trama.enganche_desenganche_pic == false);
    REQUIRE(trama.boton_2 == false);
    REQUIRE(trama.boton_3 == false);
    REQUIRE(trama.graba_pic == false);
    REQUIRE(trama.acc_archivo_pic == false);
    REQUIRE(trama.seleccion_ventana_1 == false);
    REQUIRE(trama.seleccion_ventana_2 == false);
    REQUIRE(trama.sen_fija == false);
}