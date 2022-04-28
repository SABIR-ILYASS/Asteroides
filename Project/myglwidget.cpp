#include "myglwidget.h"
#include "stationorbitalelogotse.h"
#include "asteroide.h"

#include "asteroide.h"
#include <GL/glu.h>
#include <QApplication>

// Declarations des constantes
const unsigned int WIN_WIDTH_HEIGHT = 900;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QOpenGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH_HEIGHT, WIN_WIDTH_HEIGHT);

}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    // ...
    //this->paintGL();


}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    glClearColor(colorfR_/255.f,colorfG_/255.f,colorfB_/255.f,1.f);
    // Reinitialisation du tampon de couleur
    glClear(GL_COLOR_BUFFER_BIT);

    // couleur à utiliser pour dessiner les objets
    glColor3ub(colortR_, colortB_, colortB_);

    // Affichage des primitives
    // ...
    /*

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //gluPerspective(70.f, 1, 0.1f, 12.f);

    new StationOrbitaleLogoTSE(10., 20., 20.);
    */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -50.0, 20.0, 0.0, 20.0);
    new StationOrbitaleLogoTSE(0., 0., 0.);

    //new Asteroide(5, 2, 1);

}


