#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Some effects  //////////////////////

void main() {

    string path = "c:/users/максим/source/repos/opencv/resources/resources/test.png";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDialate, imgErode;
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur,Size(7,7),5,0);
    Canny(imgBlur, imgCanny, 25, 75);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(imgCanny, imgDialate, kernel);
    erode(imgDialate, imgErode, kernel);

    /*imshow("image", img);
    imshow("gray", imgGray);
    imshow("blur", imgBlur);
    imshow("blur", imgCanny);*/
    imshow("dialate", imgDialate);
    imshow("erode", imgErode);
    waitKey(0);
}

