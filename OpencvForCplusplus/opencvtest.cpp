#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(void)
{
    cv::Mat img = cv::imread("D:/youshu/USTB/learning/Forc++/OpencvForCplusplus/huochepiao.jpg");
    cv::imshow("img", img);
    cv::waitKey(0);

    return 0;
}