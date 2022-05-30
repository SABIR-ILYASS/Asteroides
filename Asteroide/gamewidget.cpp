#include "gamewidget.h"
#include <QApplication>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

GameWidget::GameWidget(QWidget * parent) : QOpenGLWidget(parent)
{
    /*
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f;
        update();
    });
    */

    detectionAction_ = "";
    m_AnimationTimer = new QTimer(this);

    m_AnimationTimer->setInterval(10);
    m_AnimationTimer->start();

    // listAsteroide_ = new ListAsteroide(nombreOfAst_);
    listAsteroide_ = new ListAsteroide(nombreOfAst_);
    listAsteroide_->creat();

    vaisseau_ = new Vaisseau();

    stationOrbitale_ = new StationorbitaleLogoTSE();
    idPressButton_ = 0;

    score_ = 0;
    nombreOfCollision_ =0;
}

void GameWidget::initializeGL()
{
    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.f, width()/height(), 0.1f, 120.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0., 11., 12.,0. ,5. ,5., 0. ,1. ,0.);


    //activer la gestion de lumière
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Reglage de la lampe
     GLfloat color_ambient[] = {1.0, 1.0, 1.0, 1.0};
     GLfloat color_diffuse[] = {1.0, 1.0, 1.0, 1.0};
     GLfloat color_speculaire[]={1.0,1.0,1.0,1.0};
     glLightfv(GL_LIGHT0, GL_AMBIENT, color_ambient);
     glLightfv(GL_LIGHT0, GL_DIFFUSE, color_diffuse);
     glLightfv(GL_LIGHT0, GL_SPECULAR, color_speculaire);

}

// Fonction d'affichage
void GameWidget::paintGL()
{
    // Reinitialisation des tampons
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0, 11., 12., 0., 5., 5., 0., 1., 0.);

        glPushMatrix();

        vaisseau_->Display();

        //ground_->Display();
        qDebug()<<idPressButton_;
        qDebug()<<"---------------";

        double avancementX = 0, avancementY = 0, avancementZ = 0;
        if (detectionAction_ == "RIGHT" || idPressButton_ == 2)
        {
            avancementX = -1;
            avancementY = 0;
            avancementZ = 0;
            qDebug()<<"Right";
        }
        else if (detectionAction_ == "LEFT" || idPressButton_ == 1)
        {
            avancementX = 1;
            avancementY = 0;
            avancementZ = 0;
            qDebug()<<"LEFT";

        }
        else if (detectionAction_ == "UP" || idPressButton_ == 4)
        {
            avancementX = 0;
            avancementY = 1;
            avancementZ = 0;
            qDebug()<<"Up";
        }
        else if (detectionAction_ == "DOWN" || idPressButton_ == 3)
        {
            avancementX = 0;
            avancementY = -1;
            avancementZ = 0;
            qDebug()<<"Down";
        }
        else if (detectionAction_ == "STOP" || idPressButton_ == -1)
        {
            avancementX = 0;
            avancementY = 0;
            avancementZ = 0;
            qDebug()<<"Stop";
        }

        else if (detectionAction_ == "AVANCER" || idPressButton_ == 0)
        {
            avancementX = 0;
            avancementY = 0;
            avancementZ = 1;
            qDebug()<<"Avancer";
        }
        else
        {
        }

        int angle = stationOrbitale_->getAngleRoration();
        stationOrbitale_->setRotation(angle + 9);

        stationOrbitale_->setPositionX(stationOrbitale_->getPositionX() + avancementX);
        stationOrbitale_->setPositionY(stationOrbitale_->getPositionY() + avancementY);
        stationOrbitale_->setPositionZ(stationOrbitale_->getPositionZ() + avancementZ);

        stationOrbitale_->Display();
        vaisseau_->Display();

        listAsteroide_->avancerX(avancementX);
        listAsteroide_->avancerY(avancementY);
        listAsteroide_->avancerZ(avancementZ);

        qDebug()<<listAsteroide_->getPositionZ();
        listAsteroide_->Display();

        glPopMatrix();
}

void GameWidget::detecteCollision()
{
    score_ = listAsteroide_->getScore();
    nombreOfCollision_ = listAsteroide_->getNombreOfCollision();
}
