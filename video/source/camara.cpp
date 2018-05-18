#include <video/include/camara.h>

// stl
#include <iostream>

// opencv
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

// aplicacion
#include <aplicacion/include/logger.h>

namespace seon::video {

camara::camara(big_uint ancho, big_uint alto, uint fps) : alto(alto), ancho(ancho), fps(fps) {

    std::stringstream mensaje;
    
    mensaje << "camara iniciada:\n ancho: " << this->ancho << " - alto: "<< this->alto << " - fps: " + this->fps << ".";

    aplicacion::logger::info(mensaje.str());
}

camara::~camara() {

    aplicacion::logger::info("cierre camara");
}

void camara::filmar(const std::string & path_video) {

    aplicacion::logger::info("inicio filmacion: " + path_video);

    cv::VideoCapture cap(path_video);

    // Check if camera opened successfully
    if (!cap.isOpened()) {
        std::cout << "Error opening video stream or file" << std::endl;
        return;
    }

    while (1) {

        cv::Mat frame;
        // Capture frame-by-frame
        cap >> frame;

        // If the frame is empty, break immediately
        if (frame.empty())
            break;

        // Display the resulting frame
        cv::imshow("Frame", frame);

        // Press  ESC on keyboard to exit
        char c = (char)cv::waitKey(25);
        if (c == 27)
            break;
    }

    // When everything done, release the video capture object
    cap.release();

    // Closes all the frames
    cv::destroyAllWindows();
}



}
