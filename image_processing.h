// image_processing.h

#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <opencv2/opencv.hpp>

cv::Mat applyFilter(const cv::Mat& image, int kernelSize);

cv::Mat applyMedianFilter(const cv::Mat& image, int kernelSize);
cv::Mat applySobelFilter(const cv::Mat& image);
cv::Mat applyRobertFilter(const cv::Mat& image);
cv::Mat applySharpenFilter(const cv::Mat& image);
cv::Mat applyAdaptiveSmoothFilter(const cv::Mat& image, int blockSize, double C);
cv::Mat applyContrastEnhancement(const cv::Mat& image, double alpha, int beta);

#endif // IMAGE_PROCESSING_H
