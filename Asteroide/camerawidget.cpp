#include "camerawidget.h"

#include <iostream>
#include <QPixmap>
#include <QDebug>

using namespace std;

CameraWidget::CameraWidget(QWidget *parent)
    : QWidget{parent}
{
    action ="";
    cadre_affichage = new QLabel(this);
    setGeometry(parent->width()*0.505,parent->height() * 0.01,parent->width() * 0.49,parent->height() * 0.8);
    setStyleSheet("background-color:green");
    cadre_affichage->setGeometry(0,0,this->width(),this->height());
    cadre_affichage->setStyleSheet("background-color:green");
    cap = VideoCapture(0); // open the default camera
    //cap.set(CAP_PROP_FRAME_WIDTH,366);
    //cap.set(CAP_PROP_FRAME_HEIGHT,291);
   if( !face_cascade.load("C:/Users/Dell/Desktop/Nouveau dossier (2)/Asteroides/Asteroide/detection.xml"))
   {
       cerr<<"Error telechargement haarcascade"<<endl;
   }

   if(!cap.isOpened()) { // check if we succeeded
           cerr << "Error openning the default camera" << endl;
   }
   else {
           cout<<"Telechargement reussi"<<endl;

   }
   DetectionMain();

}

void CameraWidget::DetectionMain()
{
    Mat frame_gray;
    vector<Rect> faces,Mains;
    // Get frame
    cap >>frame;
    // Mirror effect
    flip(frame,frame,1);
    // Convert to gray
    cvtColor(frame,frame_gray,COLOR_BGR2GRAY);
    // Equalize graylevelsx
    //equalizeHist( frame_gray, frame_gray );
    //-- Detect faces
    //palm_cascad.detectMultiScale(frame_gray, Mains, 1.1, 4, 0|CASCADE_SCALE_IMAGE, Size(60, 60));
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 4, 0|CASCADE_SCALE_IMAGE, Size(60, 60) );
    //cout<<faces.size()<<endl;
    if(faces.size()==1){
        // Draw green rectangle
        for (int i=0;i<(int)Mains.size();i++)
        {
            rectangle(frame,Mains[i],Scalar(0,255,0),2);
            posr[i][0]=Mains[i].width+((Mains[i].x)/2);
            posr[i][1]=Mains[i].height+((Mains[i].y)/2);
        }

        action = "AVANCER";
    } else if (faces.size()==2)
    {
        // Draw green rectangle
        for (int i=0;i<(int)faces.size();i++)
        {
            rectangle(frame,faces[i],Scalar(0,255,0),2);

            posr[i][0]=faces[i].width+((faces[i].x)/2);
            posr[i][1]=faces[i].height+((faces[i].y)/2);
        }

        if(posr[0][0]>0 && posr[1][0]>0)
        {
            //s'il y a deux mains visibles
            //on a alors soit la main gauche est la premiere dans la liste soit c'est la deuxième
            //et soit la main gauche est plus haute avec une marge suffisante, soit elle est plus basse
            //avec une marche suffisante (soit les deux mains sont a peu pres collées et on ne fait rien)
            if (posr[0][1]-posr[1][1]>50 && posr[0][0]>posr[1][0])
            {
                //move right
                action = "RIGHT";
            }

            else if (posr[0][1]-posr[1][1]<-50 && posr[0][0]>posr[1][0]) {
                //move left
                action = "LEFT";
                   }
               else if (posr[0][1]-posr[1][1]>50 && posr[1][0]>posr[0][0]) {
                   //move left
                   action = "LEFT";
            } else if (posr[0][1]-posr[1][1]<-50 && posr[1][0]>posr[0][0])
            {
                //move right
                action = "RIGHT";
            }
        }
    } else
    {
        action="STOP";
    }

    image = QImage(frame.data, cadre_affichage->width(), cadre_affichage->height(), frame.step, QImage::Format_BGR888);

    pimage = QPixmap::fromImage(image);

    cadre_affichage->setPixmap(pimage);
}
