#include "stationorbitalelogotse.h"

#include <random>
#include <QDebug>

// constructeur pour StationorbitaleLogoTSE
StationorbitaleLogoTSE::StationorbitaleLogoTSE()
{
    posX_ = rand() % (this->MAX_POSITION_X - this->MIN_POSITION_X) + this->MIN_POSITION_X;
    posY_ = rand() % (this->MAX_POSITION_Y - this->MIN_POSITION_Y) + this->MIN_POSITION_Y;
    posZ_ = -100;
    angleRotation_ = 0;
}

// fonction d'affichage de StationorbitaleLogoTSE
void StationorbitaleLogoTSE::Display() const
{
    glEnable(GL_TEXTURE_2D);
    // Initialisation des paramètres
    QImage tex1  = QImage(":/images/textures/tse.jpg");
    QImage texture1 = tex1.convertToFormat(QImage ::Format_RGBA8888);

    QImage tex2  = QImage(":/images/textures/verre.jpg");
    QImage texture2 = tex2.convertToFormat(QImage ::Format_RGBA8888);

    QImage tex3  = QImage(":/images/textures/verre2.jpg");
    QImage texture3 = tex3.convertToFormat(QImage ::Format_RGBA8888);

    GLuint *textures = new GLuint[3];
    glGenTextures(5,textures);

    // on definit la texture courante
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    // on definit les caracteristique de la textures courantes
    glTexImage2D(GL_TEXTURE_2D,0,4, texture1.width(),texture1.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texture1.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, textures[1]);
    // on definit les caracteristique de la textures courantes
    glTexImage2D(GL_TEXTURE_2D,0,4, texture2.width(),texture2.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texture2.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, textures[2]);
    // on definit les caracteristique de la textures courantes
    glTexImage2D(GL_TEXTURE_2D,0,4, texture3.width(),texture3.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texture3.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


    // ajouter moteur vaisseau

    glPushMatrix();

    glTranslated(posX_ ,posY_ ,posZ_);
    glRotated(angleRotation_, 0, 0, 1);

    glBindTexture(GL_TEXTURE_2D, textures[0]);
    //ajouter_eclairage();

    glBegin(GL_QUADS);

    glNormal3f(0.0,0.0,-1.0);
    glTexCoord2d(1,0),glVertex3f(-1.f, -0.5f, 3.f);
    glTexCoord2d(1,1),glVertex3f(1.f, -0.5f, 3.f);
    glTexCoord2d(0,1),glVertex3f(1.f, 0.5f, 3.f);
    glTexCoord2d(0,0),glVertex3f(-1.f, 0.5f, 3.f);


    //glColor3ub(255, 0, 0);
    glNormal3f(0.0,0.0,1.0);
    glTexCoord2d(1,0),glVertex3f(-1.f, -0.5f, 5.f);
    glTexCoord2d(1,1),glVertex3f(1.f, -0.5f, 5.f);
    glTexCoord2d(0,1),glVertex3f(1.f, 0.5f, 5.f);
    glTexCoord2d(0,0),glVertex3f(-1.f, 0.5f, 5.f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(0,0),glVertex3f(-1.f, 0.5f, 5.f);
    glTexCoord2d(0,1),glVertex3f(1.f, 0.5f, 5.f);
    glTexCoord2d(1,1),glVertex3f(1.f, 0.5f, 3.f);
    glTexCoord2d(1,0),glVertex3f(-1.f, 0.5f, 3.f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(1,0),glVertex3f(-1.f, -0.5f, 5.f);
    glTexCoord2d(1,1),glVertex3f(1.f, -0.5f, 5.f);
    glTexCoord2d(1,1),glVertex3f(1.f, -0.5f, 3.f);
    glTexCoord2d(0,0),glVertex3f(-1.f, -0.5f, 3.f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(1.f, 0.5f, 5.f);
    glVertex3f(1.f, -0.5f, 5.f);
    glVertex3f(1.f, -0.5f, 3.f);
    glVertex3f(1.f, 0.5f, 3.f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(-1.f, 0.5f, 5.f);
    glVertex3f(-1.f, -0.5f, 5.f);
    glVertex3f(-1.f, -0.5f, 3.f);
    glVertex3f(-1.f, 0.5f, 3.f);
    glEnd();


    // 1

    glBindTexture(GL_TEXTURE_2D, textures[1]);

    glBegin(GL_QUADS);

    glColor3ub(255, 0, 0);

    glNormal3f(0.0,0.0,-1.0);
    glTexCoord2d(1,0),glVertex3f(-3.f, -0.5f, 3.25f);
    glTexCoord2d(1,1),glVertex3f(-1.f, -0.5f, 3.25f);
    glTexCoord2d(0,1),glVertex3f(-1.f, 0.5f, 3.25f);
    glTexCoord2d(0,0),glVertex3f(-3.f, 0.5f, 3.25f);


    //glColor3ub(100, 0, 0);
    glNormal3f(0.0,0.0,1.0);
    glTexCoord2d(1,0),glVertex3f(-3.f, -0.5f, 3.5f);
    glTexCoord2d(1,1),glVertex3f(-1.f, -0.5f, 3.5f);
    glTexCoord2d(0,1),glVertex3f(-1.f, 0.5f, 3.5f);
    glTexCoord2d(0,0),glVertex3f(-3.f, 0.5f, 3.5f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(0,0),glVertex3f(-3.f, 0.5f, 3.5f);
    glTexCoord2d(0,1),glVertex3f(-1.f, 0.5f, 3.5f);
    glTexCoord2d(1,1),glVertex3f(-1.f, 0.5f, 3.25f);
    glTexCoord2d(1,0),glVertex3f(-3.f, 0.5f, 3.25f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(1,0),glVertex3f(-3.f, -0.5f, 3.5f);
    glTexCoord2d(1,1),glVertex3f(-1.f, -0.5f, 3.5f);
    glTexCoord2d(1,1),glVertex3f(-1.f, -0.5f, 3.25f);
    glTexCoord2d(0,0),glVertex3f(-3.f, -0.5f, 3.25f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(-1.f, 0.5f, 3.5f);
    glVertex3f(-1.f, -0.5f, 3.5f);
    glVertex3f(-1.f, -0.5f, 3.25f);
    glVertex3f(-1.f, 0.5f, 3.25f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(-3.f, 0.5f, 3.5f);
    glVertex3f(-3.f, -0.5f, 3.5f);
    glVertex3f(-3.f, -0.5f, 3.25f);
    glVertex3f(-3.f, 0.5f, 3.25f);
    glEnd();

    // 2

    glBindTexture(GL_TEXTURE_2D, textures[2]);

    glBegin(GL_QUADS);

    glNormal3f(0.0,0.0,-1.0);
    glTexCoord2d(1,0),glVertex3f(-3.f, -0.5f, 3.75f);
    glTexCoord2d(1,1),glVertex3f(-1.f, -0.5f, 3.75f);
    glTexCoord2d(0,1),glVertex3f(-1.f, 0.5f, 3.75f);
    glTexCoord2d(0,0),glVertex3f(-3.f, 0.5f, 3.75f);


    //glColor3ub(100, 0, 0);
    glNormal3f(0.0,0.0,1.0);
    glTexCoord2d(1,0),glVertex3f(-3.f, -0.5f, 4.f);
    glTexCoord2d(1,1),glVertex3f(-1.f, -0.5f, 4.f);
    glTexCoord2d(0,1),glVertex3f(-1.f, 0.5f, 4.f);
    glTexCoord2d(0,0),glVertex3f(-3.f, 0.5f, 4.f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(0,0),glVertex3f(-3.f, 0.5f, 4.f);
    glTexCoord2d(0,1),glVertex3f(-1.f, 0.5f, 4.f);
    glTexCoord2d(1,1),glVertex3f(-1.f, 0.5f, 3.75f);
    glTexCoord2d(1,0),glVertex3f(-3.f, 0.5f, 3.75f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(1,0),glVertex3f(-3.f, -0.5f, 4.f);
    glTexCoord2d(1,1),glVertex3f(-1.f, -0.5f, 4.f);
    glTexCoord2d(1,1),glVertex3f(-1.f, -0.5f, 3.75f);
    glTexCoord2d(0,0),glVertex3f(-3.f, -0.5f, 3.75f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(-1.f, 0.5f, 4.f);
    glVertex3f(-1.f, -0.5f, 4.f);
    glVertex3f(-1.f, -0.5f, 3.75f);
    glVertex3f(-1.f, 0.5f, 3.75f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(-3.f, 0.5f, 4.f);
    glVertex3f(-3.f, -0.5f, 4.f);
    glVertex3f(-3.f, -0.5f, 3.75f);
    glVertex3f(-3.f, 0.5f, 3.75f);
    glEnd();

    // 3

    glBindTexture(GL_TEXTURE_2D, textures[1]);

    glBegin(GL_QUADS);

    glNormal3f(0.0,0.0,-1.0);
    glTexCoord2d(1,0),glVertex3f(-3.f, -0.5f, 4.25f);
    glTexCoord2d(1,1),glVertex3f(-1.f, -0.5f, 4.25f);
    glTexCoord2d(0,1),glVertex3f(-1.f, 0.5f, 4.25f);
    glTexCoord2d(0,0),glVertex3f(-3.f, 0.5f, 4.25f);

    //glColor3ub(100, 0, 0);
    glNormal3f(0.0,0.0,1.0);
    glTexCoord2d(1,0),glVertex3f(-3.f, -0.5f, 4.5f);
    glTexCoord2d(1,1),glVertex3f(-1.f, -0.5f, 4.5f);
    glTexCoord2d(0,1),glVertex3f(-1.f, 0.5f, 4.5f);
    glTexCoord2d(0,0),glVertex3f(-3.f, 0.5f, 4.5f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(0,0),glVertex3f(-3.f, 0.5f, 4.5f);
    glTexCoord2d(0,1),glVertex3f(-1.f, 0.5f, 4.5f);
    glTexCoord2d(1,1),glVertex3f(-1.f, 0.5f, 4.25f);
    glTexCoord2d(1,0),glVertex3f(-3.f, 0.5f, 4.25f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(1,0),glVertex3f(-3.f, -0.5f, 4.5f);
    glTexCoord2d(1,1),glVertex3f(-1.f, -0.5f, 4.5f);
    glTexCoord2d(1,1),glVertex3f(-1.f, -0.5f, 4.25f);
    glTexCoord2d(0,0),glVertex3f(-3.f, -0.5f, 4.25f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(-1.f, 0.5f, 4.5f);
    glVertex3f(-1.f, -0.5f, 4.5f);
    glVertex3f(-1.f, -0.5f, 4.25f);
    glVertex3f(-1.f, 0.5f, 4.25f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(-3.f, 0.5f, 4.5f);
    glVertex3f(-3.f, -0.5f, 4.5f);
    glVertex3f(-3.f, -0.5f, 4.25f);
    glVertex3f(-3.f, 0.5f, 4.25f);
    glEnd();

    // 4

    glBindTexture(GL_TEXTURE_2D, textures[1]);

    glBegin(GL_QUADS);

    glNormal3f(0.0,0.0,-1.0);
    glTexCoord2d(1,0),glVertex3f(1.f, -0.5f, 3.25f);
    glTexCoord2d(1,1),glVertex3f(3.f, -0.5f, 3.25f);
    glTexCoord2d(0,1),glVertex3f(3.f, 0.5f, 3.25f);
    glTexCoord2d(0,0),glVertex3f(1.f, 0.5f, 3.25f);

    //glColor3ub(100, 0, 0);
    glNormal3f(0.0,0.0,1.0);
    glTexCoord2d(1,0),glVertex3f(1.f, -0.5f, 3.5f);
    glTexCoord2d(1,1),glVertex3f(3.f, -0.5f, 3.5f);
    glTexCoord2d(0,1),glVertex3f(3.f, 0.5f, 3.5f);
    glTexCoord2d(0,0),glVertex3f(1.f, 0.5f, 3.5f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(0,0),glVertex3f(1.f, 0.5f, 3.5f);
    glTexCoord2d(0,1),glVertex3f(3.f, 0.5f, 3.5f);
    glTexCoord2d(1,1),glVertex3f(3.f, 0.5f, 3.25f);
    glTexCoord2d(1,0),glVertex3f(1.f, 0.5f, 3.25f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(1,0),glVertex3f(1.f, -0.5f, 3.5f);
    glTexCoord2d(1,1),glVertex3f(3.f, -0.5f, 3.5f);
    glTexCoord2d(1,1),glVertex3f(3.f, -0.5f, 3.25f);
    glTexCoord2d(0,0),glVertex3f(1.f, -0.5f, 3.25f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(3.f, 0.5f, 3.5f);
    glVertex3f(3.f, -0.5f, 3.5f);
    glVertex3f(3.f, -0.5f, 3.25f);
    glVertex3f(3.f, 0.5f, 3.25f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(1.f, 0.5f, 3.5f);
    glVertex3f(1.f, -0.5f, 3.5f);
    glVertex3f(1.f, -0.5f, 3.25f);
    glVertex3f(1.f, 0.5f, 3.25f);
    glEnd();

    // 5

    glBindTexture(GL_TEXTURE_2D, textures[2]);

    glBegin(GL_QUADS);

    glNormal3f(0.0,0.0,-1.0);
    glTexCoord2d(1,0),glVertex3f(1.f, -0.5f, 3.75f);
    glTexCoord2d(1,1),glVertex3f(3.f, -0.5f, 3.75f);
    glTexCoord2d(0,1),glVertex3f(3.f, 0.5f, 3.75f);
    glTexCoord2d(0,0),glVertex3f(1.f, 0.5f, 3.75f);


    //glColor3ub(100, 0, 0);
    glNormal3f(0.0,0.0,1.0);
    glTexCoord2d(1,0),glVertex3f(1.f, -0.5f, 4.f);
    glTexCoord2d(1,1),glVertex3f(3.f, -0.5f, 4.f);
    glTexCoord2d(0,1),glVertex3f(3.f, 0.5f, 4.f);
    glTexCoord2d(0,0),glVertex3f(1.f, 0.5f, 4.f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(0,0),glVertex3f(1.f, 0.5f, 4.f);
    glTexCoord2d(0,1),glVertex3f(3.f, 0.5f, 4.f);
    glTexCoord2d(1,1),glVertex3f(3.f, 0.5f, 3.75f);
    glTexCoord2d(1,0),glVertex3f(1.f, 0.5f, 3.75f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(1,0),glVertex3f(1.f, -0.5f, 4.f);
    glTexCoord2d(1,1),glVertex3f(3.f, -0.5f, 4.f);
    glTexCoord2d(1,1),glVertex3f(3.f, -0.5f, 3.75f);
    glTexCoord2d(0,0),glVertex3f(1.f, -0.5f, 3.75f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(3.f, 0.5f, 4.f);
    glVertex3f(3.f, -0.5f, 4.f);
    glVertex3f(3.f, -0.5f, 3.75f);
    glVertex3f(3.f, 0.5f, 3.75f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(1.f, 0.5f, 4.f);
    glVertex3f(1.f, -0.5f, 4.f);
    glVertex3f(1.f, -0.5f, 3.75f);
    glVertex3f(1.f, 0.5f, 3.75f);
    glEnd();

    // 6

    glBindTexture(GL_TEXTURE_2D, textures[1]);

    glBegin(GL_QUADS);

    glNormal3f(0.0,0.0,-1.0);
    glTexCoord2d(1,0),glVertex3f(1.f, -0.5f, 4.25f);
    glTexCoord2d(1,1),glVertex3f(3.f, -0.5f, 4.25f);
    glTexCoord2d(0,1),glVertex3f(3.f, 0.5f, 4.25f);
    glTexCoord2d(0,0),glVertex3f(1.f, 0.5f, 4.25f);


    //glColor3ub(100, 0, 0);
    glNormal3f(0.0,0.0,1.0);
    glTexCoord2d(1,0),glVertex3f(1.f, -0.5f, 4.5f);
    glTexCoord2d(1,1),glVertex3f(3.f, -0.5f, 4.5f);
    glTexCoord2d(0,1),glVertex3f(3.f, 0.5f, 4.5f);
    glTexCoord2d(0,0),glVertex3f(1.f, 0.5f, 4.5f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(0,0),glVertex3f(1.f, 0.5f, 4.5f);
    glTexCoord2d(0,1),glVertex3f(3.f, 0.5f, 4.5f);
    glTexCoord2d(1,1),glVertex3f(3.f, 0.5f, 4.25f);
    glTexCoord2d(1,0),glVertex3f(1.f, 0.5f, 4.25f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(1,0),glVertex3f(1.f, -0.5f, 4.5f);
    glTexCoord2d(1,1),glVertex3f(3.f, -0.5f, 4.5f);
    glTexCoord2d(1,1),glVertex3f(3.f, -0.5f, 4.25f);
    glTexCoord2d(0,0),glVertex3f(1.f, -0.5f, 4.25f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(3.f, 0.5f, 4.5f);
    glVertex3f(3.f, -0.5f, 4.5f);
    glVertex3f(3.f, -0.5f, 4.25f);
    glVertex3f(3.f, 0.5f, 4.25f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(1.f, 0.5f, 4.5f);
    glVertex3f(1.f, -0.5f, 4.5f);
    glVertex3f(1.f, -0.5f, 4.25f);
    glVertex3f(1.f, 0.5f, 4.25f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslated(posX_ ,posY_ ,posZ_);
    glTranslated(0 ,0.5 ,0);
    GLUquadric* quadriqueCli = gluNewQuadric();
    gluQuadricDrawStyle(quadriqueCli,GLU_FILL);
    glNormal3f(0.0,0.0,1.0);
    if (clign_ == true){
        glColor3f(1.0f,0.0f,0.0f),gluDisk(quadriqueCli,0,0.5,20,1);
    }
    else {
        glColor3f(0.0f,0.0f,0.0f),gluDisk(quadriqueCli,0,0.5,20,1);
    }

    glDisable(GL_COLOR);
    glPopMatrix();

    delete[] textures;

}

// fonction pour avancer la station dans l'axe des X
void StationorbitaleLogoTSE::avancerX(double avanceX)
{
    posX_ += avanceX;
}

// fonction pour avancer la station dans l'axe des Y
void StationorbitaleLogoTSE::avancerY(double avanceY)
{
    posX_ += avanceY;
}

// fonction pour avancer la station dans l'axe des Z
void StationorbitaleLogoTSE::avancerZ(double avanceZ)
{
    posZ_ += avanceZ;
}
