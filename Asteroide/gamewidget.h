#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "listasteroide.h"
// #include "asteroide.h"
#include "vaisseau.h"
#include "ground.h"

#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>

class GameWidget : public QOpenGLWidget
{
public:
    GameWidget(QWidget * parent = nullptr);
    int nombreOfAst_;


protected:
    void initializeGL();
    void paintGL();

private:

    Vaisseau * vaisseau_ = nullptr;
    Ground * ground_ = nullptr;
    ListAsteroide * listAsteroide_ = nullptr;
    // Asteroide *a = nullptr;

    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;

};

#endif // GAMEWIDGET_H
