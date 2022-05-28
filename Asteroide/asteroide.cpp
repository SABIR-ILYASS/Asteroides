#include "asteroide.h"
#include <QDebug>
#include <GL/glu.h>
#include <QImage>
#include <QDebug>
// #include <QGLWidget>

Asteroide::Asteroide()
{
    posX_ = 0;
    posY_ = 0;
    posZ_ = 0;
    idOfAsteroide_ = false;

}


Asteroide::Asteroide(double posX,double posY,double posZ, bool b)
{
    posX_ = posX;
    posY_ = posY;
    posZ_ = posZ;
    idOfAsteroide_ = b;
}

void Asteroide::Display() const
{
    QString pathImage;
    glEnable(GL_TEXTURE_2D);
    if(! idOfAsteroide_)
        pathImage = ":/images/textures/asteroide.jpg";
    else{
        pathImage = ":/images/textures/positiveAsteroide.jpg";
    }
    QImage astrImage  = QImage(pathImage);
    QImage textureAstr = astrImage.convertToFormat(QImage ::Format_RGBA8888);

    GLuint textures;
    glGenTextures(1,&textures);
    // on definit la texture courante
    glBindTexture(GL_TEXTURE_2D, textures);
    // on definit les caracteristique de la textures courantes
    glTexImage2D(GL_TEXTURE_2D,0,4, textureAstr.width(),textureAstr.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,textureAstr.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    GLUquadric* quadrique2 = gluNewQuadric();
    gluQuadricDrawStyle(quadrique2,GLU_FILL);
    gluQuadricTexture(quadrique2,GLU_TRUE);
    glPushMatrix();

    glTranslated(posX_ ,posY_ ,posZ_);
    gluSphere(quadrique2,2,10,10);
    glNormal3f(0.0,0.0,1.0);
    glPopMatrix();
}

void Asteroide::setPosition(double x,double y,double z)
{
    posX_ = x;
    posY_ = y;
    posZ_ = z;
}

void Asteroide::avancerZ(double avanceZ)
{
    posZ_ += avanceZ;
}

void Asteroide::avancerX(double avanceX)
{
    posX_ += avanceX;
}
