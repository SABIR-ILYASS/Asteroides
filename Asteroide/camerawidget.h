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

    void detectionOfHand();
    void setAction(QString action){detecteAction_ = action;};
    QString getAction(){return detecteAction_;};

private:
    int posX_;
    int posY_;

    VideoCapture capture_;
    QLabel * cadreAffichage_;
    Mat frame_;
    QImage image_;

    float posR [3][2];
    QPixmap pImage_ ;
    cv::CascadeClassifier faceCascade_;
    QString detecteAction_;
signals:

};

#endif // CAMERAWIDGET_H
