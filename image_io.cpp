// image_io.cpp

#include "image_io.h"

cv::Mat readImage(const std::string& filename) {
    return cv::imread(filename);
}

void writeImage(const std::string& filename, const cv::Mat& image) {
    cv::imwrite(filename, image);
}
