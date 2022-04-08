#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/objdetect.hpp>

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;


int main(int, char**)
{
    int frameWidth=640;
    int frameHeight=480;

    VideoCapture cap(0); // open the default camera
    cout<<"width :"<<cap.get(CAP_PROP_FRAME_WIDTH)<<endl;
    cout<<"height :"<<cap.get(CAP_PROP_FRAME_HEIGHT)<<endl;
    cap.set(CAP_PROP_FRAME_WIDTH,frameWidth);
    cap.set(CAP_PROP_FRAME_HEIGHT,frameHeight);
    if(!cap.isOpened())  // check if we succeeded
    {
        cerr<<"Error openning the default camera"<<endl;
        return -1;
    }

    CascadeClassifier fist_cascade;
    if( !fist_cascade.load( "../TestDetectMultiScale/closed_frontal_palm.xml" ) )
    {
        cerr<<"Error loading closed_frontal_palm"<<endl;
        return -1;
    }

    // Init output window
    namedWindow("WebCam",1);

    while (waitKey(5)<0)
    {
        Mat frame,frame_gray;
        std::vector<Rect> fists;
        // Get frame
        cap >> frame;
        // Mirror effect
        cv::flip(frame,frame,1);
        // Convert to gray
        cv::cvtColor(frame,frame_gray,COLOR_BGR2GRAY);
        // Equalize graylevels
//        equalizeHist( frame_gray, frame_gray );
        //-- Detect fists
        fist_cascade.detectMultiScale( frame_gray, fists, 1.1, 4, 0, Size(60, 60) );
        if (fists.size()>0 && fists.size()<3)
        {
            int diffx,diffy = 0;
            // Draw green rectangle
            for (int i=0;i<(int)fists.size();i++){
                rectangle(frame,fists[i],Scalar(0,255,0),2);
                /* The coordinate of the center of this rectangle =
                (x coordinate of the top-left corner+x coordinate of the bottom-right corner)/2
                (y coordinate of the top-left corner+y coordinate of the bottom-right corner)/2
                */
                diffx = (fists[i].tl().x + fists[i].br().x)/2 - diffx;
                diffy = (fists[i].tl().y + fists[i].br().y)/2 - diffy;

//                cout<<"x coordinate of center " <<(fists[i].tl().x + fists[i].br().x)/2<<endl;
//                cout<<"y coordinate of center " <<(fists[i].tl().y + fists[i].br().y)/2<<endl;

            }
            //cout<<" diff x "<<diffx<<endl;

            if(diffx > 200 && diffx < 500){
                cout<<"stop"<<endl;

            }else{
                if(diffy < -200){
                    cout<<"move to right"<<endl;
                }
                if(diffy > 200){
                    cout<<"move to left"<<endl;
                }
            }
        }

        // Display frame
        imshow("WebCam", frame);
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
