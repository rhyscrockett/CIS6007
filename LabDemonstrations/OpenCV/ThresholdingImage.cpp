#include <iostream>
#include <vector>
#include <string>
#include <future>
#include <thread>
#include <chrono>
#include <opencv2/opencv.hpp>
/*
cv::Mat greyscale_conversion_serial(const cv::Mat& image) {
    cv::Mat grey_image(image.size().height, image.size().width, CV_8UC1, cv::Scalar(0));

    for (auto row = 0; row < image.rows; ++row) {
        for (auto col = 0; col < image.cols; ++col) {
            cv::Vec3b bgr_pixel = image.at<cv::Vec3b>(row, col);

            unsigned int greyscale = (int)(0.114 * bgr_pixel[0] + 0.587 * bgr_pixel[1] + 0.299 * bgr_pixel[2]);

            grey_image.at<uchar>(row, col) = greyscale;
        }
    }
    return grey_image;
}*/


void greyscale_conversion_serial(unsigned char* input, unsigned char* output, int num_pixels) {
    int j = 0;

    for (auto i = 0; i < num_pixels; i+=3) {
        int value_b = input[i];
        int value_g = input[i + 1];
        int value_r = input[i + 2];

        output[j] = (int)(0.114 * value_b + 0.587 * value_g + 0.299 * value_r);
    }
}

// divide and conquer parallel strategy
void greyscale_conversion_parallel(unsigned char* input, unsigned char* output, int start_idx, int end_idx, const int max_depth, int depth = 0) {
    if (depth > max_depth) {

        // loop through the indexers in groups of three (blue green red)
        for (auto i = start_idx; i < end_idx; i+=3) {
            int value_b = input[i];
            int value_g = input[i + 1];
            int value_r = input[i + 2];

            int j = i / 3;
            output[j] = (int)(0.114 * value_b + 0.587 * value_g + 0.229 * value_r);
        }
    }
    else {
        auto mid_point = (start_idx + end_idx) / 2; // split the input into two
        auto left_part = std::async(std::launch::async, greyscale_conversion_parallel, std::ref(input), std::ref(output), start_idx, mid_point, max_depth, depth + 1);
        greyscale_conversion_parallel(std::ref(input), std::ref(output), mid_point, end_idx, max_depth, depth + 1); // run the conversion in parallel by using async on two halfs
    }
}

void thresholding_serial(unsigned char* input, unsigned char* output, int num_pixels) {
    int j = 0;
    for (int i = 0; i < num_pixels; i+=3) {
        int value_b = input[i];
        int value_g = input[i + 1];
        int value_r = input[i + 2];

        output[j] = (i >= 70) ? 255 : 0;
    }
}

int main(int argc, char** argv) {
    std::cout << "Starting the application..." << std::endl;

    if (argc != 2) {
        std::cout << "Error in the arguments used!" << std::endl;
        return 1;
    }

    std::string image_name(argv[1]); // sets the command line argument used to the string variable image_name

    cv::Mat image = cv::imread(image_name); // use the image open cv function on the image_name variable s

    cv::Mat threshoutput;
    double thresh = 70;
    double maxValue = 255;

    if (!image.data) {
        std::cout << "Error in loading the image!" << std::endl;
        return 1;
    }

    unsigned char* image_ptr = (unsigned char*)(image.data);
    unsigned char* output_ptr = new unsigned char[image.size().height * image.size().width];
    cv::Mat grey_image_ptr = cv::Mat(image.size().height, image.size().width, CV_8UC1, (unsigned char*)output_ptr);

    auto startSerialTimer = std::chrono::system_clock::now(); // start the timer
    //cv::Mat grey_image = greyscale_conversion_serial(image); // set grey_image to the open 
    greyscale_conversion_serial(image_ptr, output_ptr, image.rows * image.cols * 3);
    auto endSerialTimer = std::chrono::system_clock::now(); // end the timer
    auto serialTimerDuration = std::chrono::duration_cast<std::chrono::microseconds>(endSerialTimer - startSerialTimer).count();
    std::cout << "Serial Time Taken: " << serialTimerDuration << " ms. " << std::endl;
    
    auto startParallelTimer = std::chrono::system_clock::now();
    greyscale_conversion_parallel(image_ptr, output_ptr, 0, image.rows * image.cols * 3, 0, 0); // max_depth set to 0 instead of 3 which was given in workshop
    auto endParallelTimer = std::chrono::system_clock::now();
    auto parallelTimerDuration = std::chrono::duration_cast<std::chrono::microseconds>(endParallelTimer - startParallelTimer).count();
    std::cout << "Parallel Time Taken: " << parallelTimerDuration << " ms. " << std::endl;
    
    auto startThresholdSerialTimer = std::chrono::system_clock::now();
    //cv::threshold(grey_image_ptr, threshoutput, thresh, maxValue, cv::THRESH_BINARY);
    thresholding_serial(image_ptr, output_ptr, image.rows * image.cols * 3);
    auto endThresholdSerialTimer = std::chrono::system_clock::now();
    auto thresholdSerialTimerDuration = std::chrono::duration_cast<std::chrono::microseconds>(endThresholdSerialTimer - startThresholdSerialTimer).count();
    std::cout << "Threshold Serial Time Taken: " << thresholdSerialTimerDuration << " ms. " << std::endl;

    cv::namedWindow("Original", 1);
    cv::imshow("Original", image);

    cv::namedWindow("Grey Scale Serial", 1);
    cv::imshow("Grey Scale Serial", grey_image_ptr);

    //cv::namedWindow("Threshold", 1);
    //cv::imshow("Threshold", thresholding_serial);
 
    cv::waitKey(0);

    return 0;
}