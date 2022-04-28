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
    float l = 2.f;

    gluPerspective(70.f, 1, 0.1f, 12.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0., 0., 15., 0., 0., 0., 0., 1., 0.);

    glBegin(GL_QUADS);

    //1
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f(x - 9.f * l, y + 7.f * l, z + 10.f);
    glVertex3f(x - 10.f * l, y + 7.f * l, z + 10.f);
    glVertex3f(x - 10.f * l, y + l, z + 10.f);
    glVertex3f(x - 9.f * l, y + l, z + 10.f);
    qDebug("1");

    glColor3f( 0.0, 0.5, 0.0 );
    glVertex3f(x - 10.f * l, y + l, z - 10.f);
    glVertex3f(x - 9.f * l, y + l, z - 10.f);
    glVertex3f(x - 9.f * l, y + 7.f * l, z - 10.f);
    glVertex3f(x - 10.f * l, y + 7.f * l, z - 10.f);

    QString h = QString::number(x - 10.f * l);
    qDebug(h.toLatin1());

    glColor3f( 0.0, 1.0, 0.0 );
    glVertex3f(x - 10.f * l, y + l, z + 10.f);
    glVertex3f(x - 9.f * l, y + l, z + 10.f);
    glVertex3f(x - 9.f * l, y + l, z - 10.f);
    glVertex3f(x - 10.f * l, y + l, z - 10.f);

    glColor3f( 0.0, 0.0, 0.5 );
    glVertex3f(x - 10.f * l, y + 7.f * l, z + 10.f);
    glVertex3f(x - 9.f * l, y + 7.f * l, z + 10.f);
    glVertex3f(x - 9.f * l, y + 7.f * l, z - 10.f);
    glVertex3f(x - 10.f * l, y + 7.f * l, z - 10.f);
    qDebug("3");

    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f(x - 10 * l, y + l, z + 10);
    glVertex3f(x - 10 * l, y + l, z - 10);
    glVertex3f(x - 10 * l * l, y + 7 * l, z - 10);
    glVertex3f(x - 10 * l, y + 7 * l, z + 10);
    qDebug("4");

    glColor3f( 0.5, 0.0, 0.0 );
    glVertex3f((x - 9 * l), y + l, z + 10);
    glVertex3f(x - 9 * l, y + l, z - 10);
    glVertex3f(x - 9 * l * l, y + 7 * l, z - 10);
    glVertex3f(x - 9 * l, y + 7 * l, z + 10);
    qDebug("5");

    glEnd();

    qDebug("end");

}



StationOrbitaleLogoTSE::~StationOrbitaleLogoTSE()
{

}

