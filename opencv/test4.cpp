#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  text and shapes  //////////////////////

void main() {
    Mat img(512, 512,CV_8SC3,Scalar(255,255,255));
    circle(img, Point(256, 256), 155, Scalar(0, 0, 255),FILLED);
    rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 0, 0),FILLED);
    line(img, Point(130, 296), Point(382, 296), Scalar(0, 255, 0), 2);
    putText(img, "Maxim is beautifull", Point(137, 262), FONT_HERSHEY_COMPLEX, 0.72, Scalar(0, 0, 0), 2);
    
    imshow("Image", img);

    waitKey(0);
}

