#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include "windows.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <QLabel>
#include <QImage>
#include <QPixmap>

using namespace cv;

class CameraWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CameraWidget(QWidget *parent = nullptr);
    void DetectionMain();
    void setAction(QString act){action = act;}
    QString getAction(){return action;};

private:
    VideoCapture cap;
    QLabel *cadre_affichage;
    Mat frame;
    QImage image;
    int posx;
    int posy;
    float posr [3][2];
    QPixmap pimage ;
    cv::CascadeClassifier face_cascade;
    QString action;
signals:

};

#endif // CAMERAWIDGET_H
