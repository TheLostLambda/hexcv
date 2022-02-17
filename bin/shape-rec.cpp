#include "opencv2/opencv.hpp"
#include "iostream"

int main(int, char**) {
    // open the first webcam plugged in the computer
    cv::VideoCapture camera(0);
    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not open camera" << std::endl;
        return 1;
    }

    // create a window to display the images from the webcam
    cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE);

    // this will contain the image from the webcam
    cv::Mat frame;

    // display the frame until you press a key
    while (true) {
        // capture the next frame from the webcam
        camera >> frame;
        // convert the image to grayscale
        cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
        // apply binary thresholding
        cv::threshold(frame, frame, 150, 255, cv::THRESH_BINARY);
        // show the image on the window
        cv::imshow("Webcam", frame);
        // wait (10ms) for a key to be pressed
        if (cv::waitKey(10) >= 0)
            break;
    }
    return 0;
}
