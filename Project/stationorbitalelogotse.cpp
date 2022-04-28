#include "stationorbitalelogotse.h"
#include <GL/glu.h>
#include <QApplication>
#include <QDebug>

void StationOrbitaleLogoTSE::setPositions(float x, float y, float z){
    this->positionX_ = x;
    this->positionY_ = y;
    this->positionZ_ = z;
}


StationOrbitaleLogoTSE::StationOrbitaleLogoTSE(float posX, float posY, float posZ)
{
    float x = posX, y = posY, z = posZ;

    // dessin du station orbitale
    float l = 2.0f;

    for (int n = 0; n <= 3; n++){
        for (int m = 0; m <= 1; m++){
            glBegin(GL_QUADS);
            //1
            glColor3f( 1.0, 0.0, 0.0);
            glVertex3f(x - (9.f - 2 * n) * l, y + (7.f -8 * m) * l, z - 20.f);
            glVertex3f(x - (10.f - 2 * n) * l, y + (7.f -8 * m) * l, z - 20.f);
            glVertex3f(x - (10.f - 2 * n) * l, y + l * (1.0 - 8 * m), z - 20.f);
            glVertex3f(x - (9.f - 2 * n) * l, y + l * (1.0 - 8 * m), z - 20.f);

            glColor3f( 0.0, 0.5, 0.0);
            glVertex3f(x - (10.f - 2 * n) * l, y + l * (1.0 - 8 * m), z - 40.f);
            glVertex3f(x - (9.f - 2 * n) * l, y + l * (1.0 - 8 * m), z - 40.f);
            glVertex3f(x - (9.f - 2 * n) * l, y + (7.f -8 * m) * l, z - 40.f);
            glVertex3f(x - (10.f - 2 * n) * l, y + (7.f -8 * m) * l, z - 40.f);

            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3f(x - (10.f - 2 * n) * l, y + l * (1.0 - 8 * m), z - 20.f);
            glVertex3f(x - (9.f - 2 * n) * l, y + l * (1.0 - 8 * m), z - 20.f);
            glVertex3f(x - (9.f - 2 * n) * l, y + l * (1.0 - 8 * m), z - 40.f);
            glVertex3f(x - (10.f - 2 * n) * l, y + l * (1.0 - 8 * m), z - 40.f);

            glColor3f( 0.0, 0.0, 0.5 );
            glVertex3f(x - (10.f - 2 * n) * l, y + (7.f -8 * m) * l, z - 20.f);
            glVertex3f(x - (9.f - 2 * n) * l, y + (7.f -8 * m) * l, z - 20.f);
            glVertex3f(x - (9.f - 2 * n) * l, y + (7.f -8 * m) * l, z - 40.f);
            glVertex3f(x - (10.f - 2 * n) * l, y + (7.f -8 * m) * l, z - 40.f);

            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3f(x - (10.f - 2 * n) * l, y + l * (1.0 - 8 * m), z - 20.0f);
            glVertex3f(x - (10.f - 2 * n) * l, y + l * (1.0 - 8 * m), z - 40.0f);
            glVertex3f(x - (10.f - 2 * n) * l * l, y + (7.f -8 * m) * l, z - 40.0f);
            glVertex3f(x - (10.f - 2 * n) * l, y + (7.f -8 * m) * l, z - 20.0f);

            glColor3f( 0.5, 0.0, 0.0 );
            glVertex3f(x - (9.f - 2 * n) * l, y + l * (1.0 - 8 * m), z - 20.0f);
            glVertex3f(x - (9.f - 2 * n) * l, y + l * (1.0 - 8 * m), z - 40.0f);
            glVertex3f(x - (9.f - 2 * n) * l * l, y + (7.f -8 * m) * l, z - 40.0f);
            glVertex3f(x - (9.f - 2 * n) * l, y + (7.f -8 * m) * l, z - 20.0f);

            glEnd();
        }
    }

    for (int n = 0; n <= 3; n++){
        for (int m = 0; m <= 1; m++){
            glBegin(GL_QUADS);
            //1
            glColor3f( 1.0, 0.0, 0.0);
            glVertex3f(x + (3.f + 2 * n) * l, y + (7.f -8 * m) * l, z - 20.f);
            glVertex3f(x + (4.f + 2 * n) * l, y + (7.f -8 * m) * l, z - 20.f);
            glVertex3f(x + (4.f + 2 * n) * l, y + l * (1.0 - 8 * m), z - 20.f);
            glVertex3f(x + (3.f + 2 * n) * l, y + l * (1.0 - 8 * m), z - 20.f);

            glColor3f( 0.0, 0.5, 0.0);
            glVertex3f(x + (4.f + 2 * n) * l, y + l * (1.0 - 8 * m), z - 40.f);
            glVertex3f(x + (3.f + 2 * n) * l, y + l * (1.0 - 8 * m), z - 40.f);
            glVertex3f(x + (3.f + 2 * n) * l, y + (7.f -8 * m) * l, z - 40.f);
            glVertex3f(x + (4.f + 2 * n) * l, y + (7.f -8 * m) * l, z - 40.f);

            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3f(x + (4.f + 2 * n) * l, y + l * (1.0 - 8 * m), z - 20.f);
            glVertex3f(x + (3.f + 2 * n) * l, y + l * (1.0 - 8 * m), z - 20.f);
            glVertex3f(x + (3.f + 2 * n) * l, y + l * (1.0 - 8 * m), z - 40.f);
            glVertex3f(x + (4.f + 2 * n) * l, y + l * (1.0 - 8 * m), z - 40.f);

            glColor3f( 0.0, 0.0, 0.5 );
            glVertex3f(x + (4.f + 2 * n) * l, y + (7.f -8 * m) * l, z - 20.f);
            glVertex3f(x + (3.f + 2 * n) * l, y + (7.f -8 * m) * l, z - 20.f);
            glVertex3f(x + (3.f + 2 * n) * l, y + (7.f -8 * m) * l, z - 40.f);
            glVertex3f(x + (4.f + 2 * n) * l, y + (7.f -8 * m) * l, z - 40.f);

            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3f(x + (4.f + 2 * n) * l, y + l * (1.0 - 8 * m), z - 20.0f);
            glVertex3f(x + (4.f + 2 * n) * l, y + l * (1.0 - 8 * m), z - 40.0f);
            glVertex3f(x + (4.f + 2 * n) * l * l, y + (7.f -8 * m) * l, z - 40.0f);
            glVertex3f(x + (4.f + 2 * n) * l, y + (7.f -8 * m) * l, z - 20.0f);

            glColor3f( 0.5, 0.0, 0.0 );
            glVertex3f(x + (3.f + 2 * n) * l, y + l * (1.0 - 8 * m), z - 20.0f);
            glVertex3f(x + (3.f + 2 * n) * l, y + l * (1.0 - 8 * m), z - 40.0f);
            glVertex3f(x + (3.f + 2 * n) * l * l, y + (7.f -8 * m) * l, z - 40.0f);
            glVertex3f(x + (3.f + 2 * n) * l, y + (7.f -8 * m) * l, z - 20.0f);

            glEnd();
        }
    }

    // cylindre 1
    glTranslated(-12 * l, 0, 0);
    glRotated(90.f, 0.f, 1.f, 0.f);

    GLUquadric * quadrique1 = gluNewQuadric();
    gluQuadricDrawStyle(quadrique1, GLU_LINE);
    gluCylinder(quadrique1, l, l, 24 * l, 40, 40);
    gluDeleteQuadric(quadrique1);

    // cylindre 2
    glTranslated(12 * l, 3 * l, 0.f);
    glRotated(90.f, 1.f, 0.f, 0.f);

    GLUquadric * quadrique2 = gluNewQuadric();
    gluQuadricDrawStyle(quadrique2, GLU_LINE);
    gluCylinder(quadrique2, l, l, 8 * l, 40, 40);
    gluDeleteQuadric(quadrique2);

    // cylindre 3


    // glLoadIdentity();
    glTranslated(0, l, 0);
    GLUquadric * quadrique3 = gluNewQuadric();
    gluQuadricDrawStyle(quadrique3, GLU_LINE);
    gluCylinder(quadrique3, 0.5 * l, 0.5 * l, l, 40, 40);
    gluDeleteQuadric(quadrique3);

    // cylindre 4
    glTranslated(0, l, 0);
    GLUquadric * quadrique4 = gluNewQuadric();
    gluQuadricDrawStyle(quadrique4, GLU_LINE);
    gluCylinder(quadrique4, l, l, l, 40, 40);
    gluDeleteQuadric(quadrique4);

    // cylindre 5

    /*
    // glLoadIdentity();
    glTranslated(0, l, 0);
    GLUquadric * quadrique5 = gluNewQuadric();
    gluQuadricDrawStyle(quadrique5, GLU_LINE);
    gluCylinder(quadrique5, 0.5 * l, l, l, 40, 40);
    gluDeleteQuadric(quadrique5);
    */

}

StationOrbitaleLogoTSE::~StationOrbitaleLogoTSE()
{

}

