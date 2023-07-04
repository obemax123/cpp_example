#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Detect Shapes  //////////////////////
Mat imgGray, imgBlur, imgCanny, imgDialate;

void getContours(Mat imgDialate, Mat img) {

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(imgDialate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    //drawContours(img, contours, -1, Scalar(255, 0, 255), 2);//-1 - all

    for (int i = 0; i < contours.size(); i++) {
        int area = contourArea(contours[i]);
        cout << area << '\n';

        vector<vector<Point>> conPoly(contours.size());
        vector<Rect> boundRect(contours.size());
        string objType;

        if (area > 1000) {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            
            cout << conPoly[i].size() << '\n';
            boundRect[i] = boundingRect(conPoly[i]);
            
            int objCor = (int)conPoly[i].size();

            if (objCor == 3)
                objType = "Triangle";
            else if (objCor == 4) {              
                float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
                if (aspRatio > 0.95 && aspRatio < 1.05)
                    objType = "Square";
                else
                    objType = "Rectangle";

            }
            else if (objCor >4)
                objType = "Circle";

            drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);//-1 - all
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 2);
            putText(img, objType, {boundRect[i].x,boundRect[i].y-3}, FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 0), 1);
        }
    }

}

void main() {

    string path = "c:/users/максим/source/repos/opencv/resources/resources/shapes.png";
    Mat img = imread(path);

    //preprocessing
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
    Canny(imgGray, imgCanny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(imgCanny, imgDialate, kernel);
    getContours(imgDialate, img);

    imshow("image", img);
    /*imshow("gray", imgGray);
    imshow("blur", imgBlur);
    imshow("Canny", imgCanny);
    imshow("dialate", imgDialate);*/
    waitKey(0);

}