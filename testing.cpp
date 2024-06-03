#include <omp.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
#include "image_processing.h"
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;
using namespace chrono;

int main(int argc, char* argv[]) {
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        cout << "Cannot open the video camera" << endl;
        return -1;
    } 

    double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT);

    cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;

    Mat input_frame, output_frame;
    int d = 20;
    double sigmaColor = 80;
    double sigmaSpace = 80;

    #pragma omp parallel
    {
 
        printf("Hello World... from thread = %d\n",
               omp_get_thread_num());
    }


    while (true) {
        cap >> input_frame;

        if (input_frame.empty()) {
            cout << "Failed to capture frame" << endl;
            break;
        }

        auto start = high_resolution_clock::now();

        output_frame = input_frame.clone();
        cout << input_frame.rows << input_frame.cols << endl;

        omp_set_num_threads(6);
        #pragma omp parallel for
            for (int i = 0; i < input_frame.rows; i += 100) {
                for (int j = 0; j < input_frame.cols; j += 100) {
                    Rect block(j, i, min(100, input_frame.cols - j), min(100, input_frame.rows - i));
                    bilateralFilter(input_frame(block), output_frame(block), d, sigmaColor, sigmaSpace);
                    // printf("Hello World... from thread = %d\n", omp_get_thread_num());
                }
            }
        
        bilateralFilter(input_frame, output_frame, d, sigmaColor, sigmaSpace);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        double fps = 1000.0 / duration.count();

        stringstream ss;
        ss << "FPS: " << fps;
        putText(output_frame, ss.str(), Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);

        imshow("Output", output_frame);

        if (waitKey(10) == 27) {
            cout << "Esc key is pressed by user. Stopping the video" << endl;
            break;
        }
    }

    destroyAllWindows();
    return 0;
}
