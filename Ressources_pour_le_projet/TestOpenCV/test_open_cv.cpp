#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
    cout<<"OpenCV version: "<<CV_VERSION<<endl;
    Mat image=imread("../TestOpenCV/lena.jpg");
    namedWindow("My Image");
    imshow("My Image",image);
    waitKey(0);
//    int key = 0;
//    while (true){
//        if(!(key = waitKeyEx(100) < 0)){
//            cout<<"key ="<< key<<endl;
//        }

//    }
    return 0;
}
