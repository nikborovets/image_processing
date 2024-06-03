// image_io.h

#ifndef IMAGE_IO_H
#define IMAGE_IO_H

#include <string>
#include <opencv2/opencv.hpp>


cv::Mat readImage(const std::string& filename);
void writeImage(const std::string& filename, const cv::Mat& image);

#endif // IMAGE_IO_H
