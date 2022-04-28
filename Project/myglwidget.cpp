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

    // Reinitialisation de la matrice courante
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0f, 5.0f, -5.0f, 5.0f, 2.0f, 10.0f);

    // Affichage des primitives
    // ...
    glClearColor(0.f, 0.f, 0.7f, 1.f);
    // Reinitialisation du tampon de couleur
    glClear(GL_COLOR_BUFFER_BIT |GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.f, 1, 0.1f, 12.f);
    glMatrixMode(GL_MODELVIEW);

    //new StationOrbitaleLogoTSE(10., 20., 20.);
    new Asteroide(5, 2, 1);

}

void MyGLWidget::keyPressEvent(QKeyEvent * keyEvent){
    QString text = keyEvent->text();
    if (text == "c"){
        colorfR_ = rand() % 255;
        colorfG_ = rand() % 255;
        colorfB_ = rand() % 255;
        update();
    }else if (text == "o"){
        colortR_ = rand() % 255;
        colortG_ = rand() % 255;
        colortB_ = rand() % 255;
        update();

    } else if (text == "r"){
        angleRotat_ = -90 + rand() % 180;
        update();
    } else if (text == " "){
        count_ +=1;
        count_ %= 3;
        update();
    }

}

