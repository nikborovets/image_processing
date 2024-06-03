#include <iostream>
#include <opencv2/opencv.hpp>
#include "image_io.h"
#include "image_processing.h"

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_image> <output_image>" << endl;
        return -1;
    }

    Mat image = readImage(argv[1]);
    if (image.empty()) {
        cerr << "Error: could not read image" << endl;
        return -1;
    }

    int kernelSize = 15;
    Mat filteredImage = applyFilter(image, kernelSize);
    // filteredImage = applySobelFilter(filteredImage);

    // Mat filteredImage = applyMedianFilter(image, 5);
    // filteredImage = applySobelFilter(filteredImage);
    // filteredImage = applyRobertFilter(filteredImage);
    // filteredImage = applySharpenFilter(filteredImage);
    filteredImage = applyAdaptiveSmoothFilter(filteredImage, 11, 2);
    // filteredImage = applyContrastEnhancement(filteredImage, 1, 5);


    writeImage(argv[2], filteredImage);
    cout << "Processed image saved to " << argv[2] << endl;

    return 0;
}
