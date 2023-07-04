#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


///////////////  Warp //////////////////////

float w = 250, h = 350;
Mat matrix, imgWarp;

void main() {

    string path = "c:/users/максим/source/repos/opencv/resources/resources/cards.jpg";
    Mat img = imread(path);
    Point2f src[4] = { {739,382},{1028,434},{639,713},{970,785} };
    Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };
    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    for (int i = 0; i < 4; i++) {
        circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
    }



    imshow("image", img);
    imshow("Warped", imgWarp);
    waitKey(0);

}