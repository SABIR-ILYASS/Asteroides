#include "vaisseau.h"

Vaisseau::Vaisseau()
{
}

// fonction d'affichage du vaisseau
void Vaisseau::Display() const
{
    glEnable(GL_TEXTURE_2D);

    // Initialisation des paramètres
    QImage tex1  = QImage(":/images/textures/textureVaisseau1.jpg");
    QImage texture1 = tex1.convertToFormat(QImage ::Format_RGBA8888);

    QImage tex2  = QImage(":/images/textures/textureVaisseau2.jpg");
    QImage texture2 = tex2.convertToFormat(QImage ::Format_RGBA8888);

    QImage tex3  = QImage(":/images/textures/textureVaisse3.jpg");
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
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    GLUquadric* quadrique = gluNewQuadric();
    gluQuadricDrawStyle(quadrique,GLU_FILL);
    gluQuadricTexture(quadrique,GLU_TRUE);

    glPushMatrix();
    glTranslated(0.0,0.0 ,7.0);
    gluCylinder(quadrique,0.5,1,1.1,10,10);
    glNormal3f(0.0,0.0,1.0);
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    GLUquadric* quadrique2 = gluNewQuadric();
    gluQuadricDrawStyle(quadrique2,GLU_FILL);
    gluQuadricTexture(quadrique2,GLU_TRUE);
    glPushMatrix();

    glTranslated(0.0,0.0 ,8.2);
    gluSphere(quadrique2,0.5,10,10);
    glNormal3f(0.0,0.0,1.0);

    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, textures[0]);
    //ajouter_eclairage();

    glBegin(GL_QUADS);

    glNormal3f(0.0,0.0,-1.0);
    glTexCoord2d(1,0),glVertex3f(-1.f, -1.f, 3.f);
    glTexCoord2d(1,1),glVertex3f(1.f, -1.f, 3.f);
    glTexCoord2d(0,1),glVertex3f(1.f, 1.f, 3.f);
    glTexCoord2d(0,0),glVertex3f(-1.f, 1.f, 3.f);

    //glColor3ub(100, 0, 0);
    glNormal3f(0.0,0.0,1.0);
    glTexCoord2d(1,0),glVertex3f(-1.f, -1.f, 7.f);
    glTexCoord2d(1,1),glVertex3f(1.f, -1.f, 7.f);
    glTexCoord2d(0,1),glVertex3f(1.f, 1.f, 7.f);
    glTexCoord2d(0,0),glVertex3f(-1.f, 1.f, 7.f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(0,0),glVertex3f(-1.f, 1.f, 7.f);
    glTexCoord2d(0,1),glVertex3f(1.f, 1.f, 7.f);
    glTexCoord2d(1,1),glVertex3f(1.f, 1.f, 3.f);
    glTexCoord2d(1,0),glVertex3f(-1.f, 1.f, 3.f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2d(1,0),glVertex3f(-1.f, -1.f, 7.f);
    glTexCoord2d(1,1),glVertex3f(1.f, -1.f, 7.f);
    glTexCoord2d(1,1),glVertex3f(1.f, -1.f, 3.f);
    glTexCoord2d(0,0),glVertex3f(-1.f, -1.f, 3.f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(1.f, 1.f, 7.f);
    glVertex3f(1.f, -1.f, 7.f);
    glVertex3f(1.f, -1.f, 3.f);
    glVertex3f(1.f, 1.f, 3.f);

    glNormal3f(1.0,0.0,0.0);
    glVertex3f(-1.f, 1.f, 7.f);
    glVertex3f(-1.f, -1.f, 7.f);
    glVertex3f(-1.f, -1.f, 3.f);
    glVertex3f(-1.f, 1.f, 3.f);
    glEnd();

    delete[] textures;
}

// fonction permet d'ajouter un eclairage au vaisseau
void Vaisseau::eclairageVaisseau() const
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_tab[] = {0.0,0.0 ,0 ,1.0};
    glLightfv(GL_LIGHT0,GL_POSITION,light_tab);
}
