#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Crop and Resize  //////////////////////

void main() {
    string path = "c:/users/максим/source/repos/opencv/resources/resources/test.png";

    Mat img = imread(path);
    Mat imgResize, imgCrop;
    //size 768 : 559
    /*resize(img, imgResize, Size(640, 480));*/
    resize(img, imgResize, Size(),0.5,0.5);

    Rect roi(240, 100,260,300);//finded the face

    imgCrop = img(roi);

    imshow("image", img);
    imshow("Resize", imgResize);
    imshow("Crop", imgCrop);

    waitKey(0);
}

