#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "vaisseau.h"
#include "ground.h"
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

    // void keyPressEvent(QKeyEvent *event);

protected:
    void initializeGL();
    void paintGL();
    // void keyPressEvent(QKeyEvent * event) override;

private:

    Vaisseau * vaisseau_ = nullptr;
    Ground * ground_ = nullptr;
    ListAsteroide * listAsteroide_ = nullptr;
    StationorbitaleLogoTSE * stationOrbitale_ = nullptr;

    // int e

    int positionListAsteroide_;
    int positionStationOrbitale_;

    float m_TimeElapsed { 0.0f };
    QTimer * m_AnimationTimer;
    QElapsedTimer * timer;

    QString detectionAction_;

    string evenement_ = "nothing";

    int idPressButton_;

};

#endif // GAMEWIDGET_H
