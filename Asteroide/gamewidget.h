#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "vaisseau.h"
#include "listasteroide.h"
#include "stationorbitalelogotse.h"
#include "keyboarddata.h"

#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QElapsedTimer>
#include <qpainter.h>
#include <iostream>

using namespace std;

class GameWidget : public QOpenGLWidget
{
public:

    GameWidget(QWidget * parent = nullptr);
    int nombreOfAst_;
    int getIdPressButton() {return idPressButton_;};
    void setIdPressButton(int n){idPressButton_ = n;};

    ListAsteroide getListOfAsteroide(){return * listAsteroide_;};

    void detecteCollision();

    int getPositionOfStationX();
    int getPositionOfStationY();
    int getPositionOfStationZ();

    QString getDetectionAction(){return detectionAction_;};
    void setDetectionAction(QString str){detectionAction_ = str;};


    int getScore(){return score_;};
    int getNombreOfCollision(){return nombreOfCollision_;};

    // void keyPressEvent(QKeyEvent *event);

protected:
    void initializeGL();
    void paintGL();

private:

    Vaisseau * vaisseau_ = nullptr;
    ListAsteroide * listAsteroide_ = nullptr;
    StationorbitaleLogoTSE * stationOrbitale_ = nullptr;

    int positionListAsteroide_;
    int positionStationOrbitale_;

    float m_TimeElapsed { 0.0f };
    QTimer * m_AnimationTimer;
    QElapsedTimer * timer;

    QString detectionAction_;

    string evenement_ = "nothing";

    int idPressButton_;

    int score_;
    int nombreOfCollision_;


};

#endif // GAMEWIDGET_H
