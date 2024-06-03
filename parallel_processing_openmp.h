// parallel_processing_openmp.h

#ifndef PARALLEL_PROCESSING_OPENMP_H
#define PARALLEL_PROCESSING_OPENMP_H

#include <opencv2/opencv.hpp>

void processImageParallel(const cv::Mat& image, int kernelSize);

#endif // PARALLEL_PROCESSING_OPENMP_H
