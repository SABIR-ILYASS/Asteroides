#include "camerawidget.h"

#include <iostream>
#include <QPixmap>
#include <QDebug>

using namespace std;

// constructeur de CameraWidget
CameraWidget::CameraWidget(QWidget *parent)
    : QWidget{parent}
{
    detecteAction_ = "";
    cadreAffichage_ = new QLabel(this);

    setGeometry(parent->width()*0.505,parent->height() * 0.01,parent->width() * 0.49,parent->height() * 0.8);
    setStyleSheet("border-radius:25%");
    cadreAffichage_->setGeometry(0,0,this->width(),this->height());
    cadreAffichage_->setStyleSheet("background-color:green");

    // ouvrir la camera par défaut:
    capture_ = VideoCapture(0);

   if( !faceCascade_.load("C:/Users/Dell/Desktop/Nouveau dossier (2)/Asteroides/Asteroide/detection.xml"))
   {
       cerr<<"Attention, erreur de telechargement haarcascade"<<endl;
   }


   // Verifier si la camera est ouverte
   if(!capture_.isOpened()) {
           cerr << "Attention, erreur d'ouverture, merci de verifier la camera par défaut de votre ordinateur" << endl;
   }
   else {
           cout<<"Telechargement reussi"<<endl;

   }
   this->detectionOfHand();

}

// fonction pour detecter les evenements des mains
void CameraWidget::detectionOfHand()
{
    Mat frameGray;
    vector<Rect> faces, Hands;
    // Get frame
    capture_ >>frame_;
    // Mirror effect
    flip(frame_, frame_, 1);
    // Convert to gray
    cvtColor(frame_,frameGray,COLOR_BGR2GRAY);

    faceCascade_.detectMultiScale( frameGray, faces, 1.1, 4, 0|CASCADE_SCALE_IMAGE, Size(60, 60) );
    //cout<<faces.size()<<endl;
    if(faces.size() == 1){
        // Draw green rectangle
        for (int i = 0; i<(int) Hands.size(); i++)
        {
            rectangle(frame_, Hands[i], Scalar(0,255,0), 2);
            posR[i][0] = Hands[i].width + ((Hands[i].x) / 2);
            posR[i][1] = Hands[i].height + ((Hands[i].y) / 2);
        }

        detecteAction_ = "AVANCER";

    } else if (faces.size()==2)
    {
        // Draw green rectangle

        for (int i = 0; i<(int)faces.size(); i++)
        {
            rectangle(frame_,faces[i],Scalar(0,255,0),2);

            posR[i][0] = faces[i].width + ((faces[i].x) / 2);
            posR[i][1] = faces[i].height + ((faces[i].y) / 2);
        }

        if(posR[0][0] > 0 && posR[1][0] > 0)
        {
            //s'il y a deux mains visibles
            //on a alors soit la main gauche est la premiere dans la liste soit c'est la deuxième
            //et soit la main gauche est plus haute avec une marge suffisante, soit elle est plus basse
            //avec une marche suffisante (soit les deux mains sont a peu pres collées et on ne fait rien)

            /* ******* */
            if ((posR[0][1] < frame_.rows / 4 ) && (posR[1][1] < frame_.rows / 4))
            {
                     //move up
                     detecteAction_ = "UP";

             }
            else if ((posR[0][1] > frame_.rows / 3) && (posR[1][1] > frame_.rows / 3))
            {
                     //move down
                     detecteAction_ = "DOWN";
             }



             else if (posR[0][1] - posR[1][1] > 50 && posR[0][0] > posR[1][0])
            {
                 //move right
                 detecteAction_ = "RIGHT";
            }
             else if (posR[0][1] - posR[1][1] < -50 && posR[0][0] > posR[1][0])
            {
                 //move left
                 detecteAction_ = "LEFT";
            }
            else if (posR[0][1] - posR[1][1] > 50 && posR[1][0] > posR[0][0])
            {
                 //move left
                 detecteAction_ = "LEFT";
            }
             else if (posR[0][1] - posR[1][1] < -50 && posR[1][0] > posR[0][0])
            {
                 //move right
                 detecteAction_ = "RIGHT";
            }
        }
    }
    else
    {
        detecteAction_ = "STOP";
    }
    qDebug()<<detecteAction_;

    image_ = QImage(frame_.data, cadreAffichage_->width(), cadreAffichage_->height(), frame_.step, QImage::Format_BGR888);

    pImage_ = QPixmap::fromImage(image_);

    cadreAffichage_->setPixmap(pImage_);
}
