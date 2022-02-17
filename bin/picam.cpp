#include <chrono>
#include <time.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int, char **) {
  // open the first webcam plugged in the computer
  cv::VideoCapture camera(0);
  if (!camera.isOpened()) {
    cerr << "ERROR: Could not open camera" << endl;
    return 1;
  }

  // create a window to display the images from the webcam
  cv::namedWindow("PiCam", cv::WINDOW_GUI_NORMAL);
  cv::setWindowProperty("PiCam", cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN);

  // this will contain the image from the webcam
  cv::Mat frame;

  // start a clock for tracking elapsed time
  auto start = chrono::steady_clock::now();

  // display the frame until you press a key
  while (true) {
    // capture the next frame from the webcam
    camera >> frame;
    // show the image on the window
    cv::imshow("PiCam", frame);
    // check how much time has passed
    auto end = chrono::steady_clock::now();
    // if two seconds have passed, save the current frame
    if (chrono::duration_cast<chrono::seconds>(end - start).count() >= 2) {
      // format the current system time in str
      auto const time = chrono::system_clock::to_time_t(chrono::system_clock::now());
      string strtime(ctime(&time));
      strtime.pop_back();
      // save the current frame
      cv::imwrite("/tmp/" + strtime + ".png", frame);
      start = end;
    }
    // wait (1ms) for a key to be pressed
    if (cv::waitKey(1) >= 0)
      break;
  }
  return 0;
}
