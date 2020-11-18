#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main(int argc, char** argv )
{
    if (argc < 2) {
        printf("not enough argument\n");
        exit(1);
    }

    //file load
    VideoCapture capture(argv[1]);
    Mat frame;

    //check
    if (!capture.isOpened())
    {
        printf("AVI file can not open.\n");
        return;
    }

    //create window
    namedWindow("w");

    while (1)
    {
        //grab frame from file & throw to Mat
        capture >> frame;
        if (frame.empty()) //Is video end?
            break;

        //processing example
        Sobel(frame, frame, frame.depth(), 1, 0);
        ////////////////////

        //display and delay
        imshow("w", frame);
        if (waitKey(10) > 0)
            break;
    }
    return 0;
}