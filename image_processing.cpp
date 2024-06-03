// image_processing.cpp

#include "image_processing.h"

cv::Mat applyFilter(const cv::Mat& image, int kernelSize) {
    cv::Mat result;
    cv::GaussianBlur(image, result, cv::Size(kernelSize, kernelSize), 0);
    return result;
}


cv::Mat applyMedianFilter(const cv::Mat& image, int kernelSize) {
    cv::Mat result;
    cv::medianBlur(image, result, kernelSize);
    return result;
}

cv::Mat applySobelFilter(const cv::Mat& image) {
    cv::Mat result;
    cv::Mat gradientX, gradientY;
    cv::Sobel(image, gradientX, CV_16S, 1, 0);
    cv::Sobel(image, gradientY, CV_16S, 0, 1);
    cv::convertScaleAbs(gradientX, gradientX);
    cv::convertScaleAbs(gradientY, gradientY);
    cv::addWeighted(gradientX, 0.5, gradientY, 0.5, 0, result);
    return result;
}

cv::Mat applyRobertFilter(const cv::Mat& image) {
    cv::Mat result;
    cv::Mat gradientX = (cv::Mat_<float>(2, 2) << 1, 0, 0, -1);
    cv::Mat gradientY = (cv::Mat_<float>(2, 2) << 0, 1, -1, 0);
    cv::filter2D(image, result, -1, gradientX);
    cv::filter2D(image, result, -1, gradientY);
    return result;
}

cv::Mat applySharpenFilter(const cv::Mat& image) {
    cv::Mat result;
    cv::Mat kernel = (cv::Mat_<float>(3,3) <<
        0, -1, 0,
        -1, 5, -1,
        0, -1, 0);
    cv::filter2D(image, result, -1, kernel);
    return result;
}

cv::Mat applyAdaptiveSmoothFilter(const cv::Mat& image, int blockSize, double C) {
    cv::Mat result;
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    cv::adaptiveThreshold(grayImage, result, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, blockSize, C);
    return result;
}


cv::Mat applyContrastEnhancement(const cv::Mat& image, double alpha, int beta) {
    cv::Mat result;
    image.convertTo(result, -1, alpha, beta);
    return result;
}
