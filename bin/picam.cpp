#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <signal.h>
#include <unistd.h>

using namespace std;

int main(int, char **) {
  // open the first webcam plugged in the computer
  cv::VideoCapture camera(0);
  if (!camera.isOpened()) {
    cerr << "ERROR: Could not open camera" << endl;
    return 1;
  }

  // this will contain the image from the webcam
  cv::Mat frame;

  // display the frame until you press a key
  while (true) {
    // capture the next frame from the webcam
    camera >> frame;
    // show the image on the window
    cv::imwrite("/tmp/frame.png", frame);
    pid_t pid = fork();
    if (pid == 0) {
      execlp("fbi", "fbi", "-T", "3", "-noverbose", "/tmp/frame.png", NULL);
    } else {
      // wait a moment before looping again
      this_thread::sleep_for(chrono::milliseconds(150));
      kill(pid, SIGTERM);
    }
  }
  return 0;
}
