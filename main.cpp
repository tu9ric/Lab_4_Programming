#include<opencv2/opencv.hpp>
#include <iostream>
 
using namespace cv;
 
int main() {
   // read the image
   Mat image = imread("C:/Users/artem/OneDrive/Desktop/Study/Programming/LAB_4/input/image_1.jpeg");
 
    // using a proper image for visualizing CHAIN_APPROX_SIMPLE

    Mat img_gray1;
    cvtColor(image, img_gray1, COLOR_BGR2GRAY);
    Mat thresh1;
    threshold(img_gray1, thresh1, 150, 255, THRESH_BINARY);
    std::vector<std::vector<Point>> contours2;
    std::vector<Vec4i> hierarchy2;
    findContours(thresh1, contours2, hierarchy2, RETR_TREE, CHAIN_APPROX_NONE);
    Mat image_copy2 = image.clone();
    drawContours(image_copy2, contours2, -1, Scalar(0, 255, 0), 2);
    imshow("None approximation", image_copy2);
    waitKey(0);
    imwrite("contours_none_image1.jpg", image_copy2);
    destroyAllWindows();
}