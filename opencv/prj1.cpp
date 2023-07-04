#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


Mat imgOrig, imgGray, imgCanny, imgThre, imgBlur, imgDialate, imgErode, imgWarp, imgCrop;
vector<Point> initialPoints,docPoints;

float w = 420, h = 596;
/////////////////  Scanar  //////////////////////

Mat preProcessing(Mat img) {
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
    Canny(imgBlur, imgCanny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDialate, kernel);
    //erode(imgDialate, imgErode, kernel);
    return imgDialate;
}

vector<Point> getContour(Mat image,Mat orig) {
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());
    vector<Point> biggest;
    int maxArea = 0;
    for (int i = 0; i < contours.size(); i++) {
        int area = contourArea(contours[i]);
        cout << area << '\n';
        string objType;
        if (area > 1000) {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            
            if (area > maxArea&&conPoly[i].size() == 4) {
                biggest = { conPoly[i][0],conPoly[i][1],conPoly[i][2],conPoly[i][3] };
                maxArea = area;
                //drawContours(orig, conPoly, i, Scalar(255, 0, 255), 5);
                //rectangle(orig, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
            }                        
        }
    }
    return biggest;
}

void drawPoints(vector<Point> points, Scalar color,Mat image) {
    for (int i = 0; i < points.size(); i++)
    {
        circle(image, points[i], 5, color, FILLED);
        putText(image, to_string(i), points[i], FONT_HERSHEY_PLAIN, 2, color, 2);
    }
}

vector<Point> reorder(vector<Point> points) {
    vector <Point> newPoints(4);
    vector <int> sumPoints(4), subPoints(4);
    for (int i = 0; i < 4; i++) {
        sumPoints[i]=( points[i].x + points[i].y);
        subPoints[i] = (points[i].x - points[i].y);
    }
    newPoints[0] = (points[min_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]);//0
    newPoints[1]=(points[max_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]);//1
    newPoints[2]=(points[min_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]);//2
    newPoints[3]=(points[max_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]);//3
    return newPoints;
}

Mat getWarp(Mat img, vector<Point> points, float w, float h) {
    Point2f src[4] = {points[0],points[1],points[2],points[3] };
    Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };
    Mat matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix, Point(w, h));
    return imgWarp;
}

void main() {

    string path = "c:/users/максим/source/repos/opencv/resources/resources/video5262513154503488475.mp4";
    VideoCapture cap(path);
    Mat imgOrig;
    while (true) {
        /*Mat imgOrig = imread(path);*/
        cap.read(imgOrig);
        /*resize(imgOrig, imgOrig, Size(), 0.5, 0.5);*/

        //preprosessing
        imgThre = preProcessing(imgOrig);
        //get contours-Biggest
        initialPoints = getContour(imgThre, imgOrig);
        if (initialPoints.size() == 0)
            continue;
        //drawPoints(initialPoints, Scalar(0,0,255), imgOrig);
        docPoints = reorder(initialPoints);
        //drawPoints(docPoints, Scalar(0, 255, 0), imgOrig);
        //warp
        imgWarp = getWarp(imgOrig, docPoints, w, h);
        //crop
        int cropValue = 5;
        Rect roi(cropValue, cropValue, w - (2 * cropValue), h - (2 * cropValue));
        imgCrop = imgWarp(roi);
        imshow("image", imgOrig);
        imshow("preProcess", imgThre); imshow("preProcess", imgThre);
        imshow("Warped&croped", imgCrop);
        waitKey(1);
    }
}