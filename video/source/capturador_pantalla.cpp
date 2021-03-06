#include <video/include/capturador_pantalla.h>

// aplicacion
#include <aplicacion/include/logger.h>

// herramientas
#include <utiles/include/Fecha.h>

namespace seon::video {

capturador_pantalla::capturador_pantalla(seon::aplicacion::configuracion::video configuracion) : configuracion(configuracion) {}

capturador_pantalla::~capturador_pantalla() {}

void capturador_pantalla::capturar() {

    std::string path = std::experimental::filesystem::current_path().u8string() + "\\" + configuracion.grabacion.carpeta + "\\" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + "." + configuracion.grabacion.formato;
    // Get a handle to the desktop window
    const HWND hDesktop = GetDesktopWindow();
    // Get the size of screen to the variable desktop
    RECT desktop;
    GetWindowRect(hDesktop, &desktop);

    // si la resolucion de config es 0x0, entonces uso la resolucion de pantalla.
    std::wstring ancho = this->configuracion.grabacion.resolucion.ancho == 0 ? std::to_wstring(desktop.right) : std::to_wstring(this->configuracion.grabacion.resolucion.ancho);
    std::wstring alto = this->configuracion.grabacion.resolucion.alto == 0 ? std::to_wstring(desktop.bottom) : std::to_wstring(this->configuracion.grabacion.resolucion.alto);

    // el string qe lleva la tilde ("Micr�fono") va con 'u8' adelante, indicando que se codifique en utf8.
    //std::string str_comando = this->configuracion.carpeta_utiles.string() + "\\ffmpeg.exe -f gdigrab "
        //"-framerate " + std::to_string(configuracion.grabacion.fps) + " -i desktop -vf scale=" + ancho + ":" + alto + " -f dshow -i audio=\"Micr�fono (Realtek High Definition Audio)\" " + path;
        //"-framerate " + std::to_string(configuracion.grabacion.fps) + " -i desktop -vf scale=" + ancho + ":" + alto + " " + path;

    //std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    //std::wstring comando_wstring = converter.from_bytes(str_comando);

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wpath = converter.from_bytes(path);

    std::wstring wstr_comando = this->configuracion.carpeta_utiles.wstring() + L"\\ffmpeg.exe -f gdigrab "
        L"-framerate " + std::to_wstring(configuracion.grabacion.fps) + L" -i desktop -vf scale=" + ancho + L":" + alto + L" -f dshow -i audio=\"Micr�fono (Realtek High Definition Audio)\" " + wpath;

    this->info_cap = { sizeof(this->info_cap) };

    wchar_t * comando = &wstr_comando[0];
    ::CreateProcess(NULL, comando, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &this->info_cap, &this->processInfo_cap);
}

void capturador_pantalla::detener() {
    STARTUPINFO info_kill = { sizeof(info_kill) };
    PROCESS_INFORMATION processInfo_kill;

    std::wstring str_comando_kill = this->configuracion.carpeta_utiles.wstring() + L"\\windows-kill.exe -SIGINT " + std::to_wstring(this->processInfo_cap.dwProcessId);

    wchar_t *comando_kill = &str_comando_kill[0];
    ::CreateProcess(NULL, comando_kill, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &info_kill, &processInfo_kill);
}

}
