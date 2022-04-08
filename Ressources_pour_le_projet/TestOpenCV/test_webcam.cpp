#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    cap.set(CAP_PROP_FRAME_WIDTH,10000);
    cap.set(CAP_PROP_FRAME_HEIGHT,10000);
    cout<<"max width: "<<cap.get(CAP_PROP_FRAME_WIDTH)<<endl;
    cout<<"max height: "<<cap.get(CAP_PROP_FRAME_HEIGHT)<<endl;
    cap.set(CAP_PROP_FRAME_WIDTH,640);
    cap.set(CAP_PROP_FRAME_HEIGHT,480);
    cout<<"width: "<<cap.get(CAP_PROP_FRAME_WIDTH)<<endl;
    cout<<"height: "<<cap.get(CAP_PROP_FRAME_HEIGHT)<<endl;
    if(!cap.isOpened())  // check if we succeeded
    {
        cerr<<"Error openning the default camera"<<endl;
        return -1;
    }

    Mat frame;
    namedWindow("WebCam",1);
    for(;;)
    {
        cap >> frame; // get a new frame from camera
        imshow("WebCam", frame);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
