
// stl
#include <iostream>

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
    cv::VideoCapture cap("C:/repositorio/repo-git-miglesias91/consola-seon/Debug/oficina.mp4");

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

    REQUIRE(1);
}
