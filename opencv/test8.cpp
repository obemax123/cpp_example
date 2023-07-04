#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

void main() {

    string path = "c:/users/������/source/repos/opencv/resources/resources/test.png";
    Mat img = imread(path);

    CascadeClassifier faceCascade;
    faceCascade.load("c:/users/������/source/repos/opencv/resources/resources/haarcascade_frontalface_default.xml");

    if (faceCascade.empty()) { cout << "xml not loaded\n"; }
    vector <Rect>faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 10);

    for (int i = 0; i < faces.size(); i++) {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
    }

    imshow("image", img);
    waitKey(0);

}