#include "gamewidget.h"
#include <QApplication>
#include <cmath>
#include <algorithm>

GameWidget::GameWidget(QWidget * parent) : QOpenGLWidget(parent)
{
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f;
        update();
    });

    m_AnimationTimer.setInterval(200);
    m_AnimationTimer.start();
}

void GameWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.8f, 0.8f, 0.8f, 0.0f);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.f,width()/height(),0.1f,50.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,30,0,0,0,0,0,1,0);


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


    vaisseau_ = new Vaisseau();
    asteroide_ = new Asteroide();

}

// Fonction d'affichage
void GameWidget::paintGL()
{
    // Reinitialisation des tampons
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0, 11., 10., 0., 0., 0., 0., 1., 0.);
        glPushMatrix();
        vaisseau_->Display();
        ground_->Display();
        asteroide_->Display();
        glPopMatrix();
}
