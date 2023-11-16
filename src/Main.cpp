#include <iostream>
#include <opencv2/core.hpp>
#include "MagicIsp.h"

int main() {
    cv::Mat temp = cv::Mat(5, 5, CV_8UC1, cv::Scalar::all(0));
    std::cout << temp << std::endl;

    cv::Mat mat = add(temp, 13);
    std::cout << mat << std::endl;

    return 0;
}