
// stl
#include <iostream>
#include <filesystem>

// catch2
#include <catch.hpp>

// opencv
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

TEST_CASE("video", "stream_camara")
{
    // Create a VideoCapture object and open the input file
    // If the input is the web camera, pass 0 instead of the video file name

    std::string directorio_ejecutable = std::experimental::filesystem::current_path().u8string();

    cv::VideoCapture cap(directorio_ejecutable + "\\oficina.mp4", cv::CAP_FFMPEG);
    cv::VideoWriter grabador(directorio_ejecutable + "\\salida.mp4", cv::CAP_FFMPEG, cv::VideoWriter::fourcc('F', 'M', 'P', '4'), 30, cv::Size(cap.get(cv::CAP_PROP_FRAME_WIDTH), cap.get(cv::CAP_PROP_FRAME_HEIGHT)));

    // Check if camera opened successfully
    if (!cap.isOpened()) {
        std::cout << "Error opening video stream or file" << std::endl;
        return;
    }

    cap.set(CV_CAP_PROP_FPS, 1.0f);
    double fps = cap.get(CV_CAP_PROP_FPS);
    double height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    double width = cap.get(CV_CAP_PROP_FRAME_WIDTH);

    while (1) {

        cv::Mat frame;
        // Capture frame-by-frame
        //cap >> frame;
        cap.read(frame);

        // If the frame is empty, break immediately
        if (frame.empty())
            break;

        // Display the resulting frame
        cv::imshow("Frame", frame);

        grabador.write(frame);

        // Press  ESC on keyboard to exit
        char c = (char)cv::waitKey(25);
        if (c == 27)
            break;
    }

    // When everything done, release the video capture object
    cap.release();

    // Closes all the frames
    cv::destroyAllWindows();

    REQUIRE(1);
}
