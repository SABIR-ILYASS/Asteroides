#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "listasteroide.h"
// #include "asteroide.h"
#include "vaisseau.h"
#include "ground.h"

#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <iostream>

using namespace std;

class GameWidget : public QOpenGLWidget
{
public:
    GameWidget(QWidget * parent = nullptr);
    int nombreOfAst_;
    // void keyPressEvent(QKeyEvent *event);


protected:
    void initializeGL();
    void paintGL();
    // void keyPressEvent(QKeyEvent * event) override;

private:

    Vaisseau * vaisseau_ = nullptr;
    Ground * ground_ = nullptr;
    ListAsteroide * listAsteroide_ = nullptr;
    // Asteroide *a = nullptr;

    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;
    QKeyEvent *event_;

};

#endif // GAMEWIDGET_H
