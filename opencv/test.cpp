#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

//void main() {
//
//    string path = "c:/users/максим/source/repos/opencv/resources/resources/test.png";
//    Mat img = imread(path);
//    imshow("image", img);
//    waitKey(0);
//
//}

void main() {
	string path = "c:/users/максим/source/repos/opencv/resources/resources/test_video.mp4";
	VideoCapture cap(path);
	Mat img;
	while (true) {
		cap.read(img);		
		imshow("image", img);
		waitKey(1);
	}
}