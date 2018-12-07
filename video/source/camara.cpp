#include <video/include/camara.h>

// stl
#include <iostream>

// opencv
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::video {

camara::camara(seon::aplicacion::configuracion::video configuracion) : configuracion(configuracion) {

    std::stringstream mensaje;
    
    //mensaje << "camara iniciada:\n ancho: " << this->ancho << " - alto: " << this->alto << " - fps: " << this->fps << ".";

    aplicacion::logger::info(mensaje.str());
}

camara::~camara() {

    aplicacion::logger::info("cierre camara");
}

void camara::filmar() {

    aplicacion::logger::info("inicio filmacion");

    // Get a handle to the desktop window
    const HWND hDesktop = GetDesktopWindow();
    // Get the size of screen to the variable desktop
    RECT desktop;
    GetWindowRect(hDesktop, &desktop);

    // si la resolucion de config es 0x0, entonces uso la resolucion de pantalla.
    std::wstring ancho = this->configuracion.filmacion.resolucion.ancho == 0 ? std::to_wstring(desktop.right) : std::to_wstring(this->configuracion.filmacion.resolucion.ancho);
    std::wstring alto = this->configuracion.filmacion.resolucion.alto == 0 ? std::to_wstring(desktop.bottom) : std::to_wstring(this->configuracion.filmacion.resolucion.alto);

    this->info_cam = { sizeof(this->info_cam) };

    std::wstring str_comando_cam = this->configuracion.carpeta_utiles.wstring() + L"\\ffplay.exe -video_size 720x576 -f dshow -vf scale=" + ancho + L":" + alto + L":force_original_aspect_ratio=decrease,pad=" + ancho + L":" + alto + L":(ow-iw)/2:(oh-ih)/2,setsar=1 -i video=\"Decklink Video Capture\"";
    wchar_t * comando_cam = &str_comando_cam[0];
    ::CreateProcess(NULL, comando_cam, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &this->info_cam, &this->processInfo_cam);
}

void camara::detener() {
    aplicacion::logger::info("detener filmacion");

    STARTUPINFO info_kill = { sizeof(info_kill) };
    PROCESS_INFORMATION processInfo_kill;

    std::wstring str_comando_kill = this->configuracion.carpeta_utiles.wstring() + L"\\windows-kill.exe -SIGINT " + std::to_wstring(this->processInfo_cam.dwProcessId);

    wchar_t *comando_kill = &str_comando_kill[0];
    ::CreateProcess(NULL, comando_kill, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &info_kill, &processInfo_kill);
}

}
