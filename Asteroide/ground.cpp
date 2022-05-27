#include "ground.h"
#include <GL/glu.h>
#include <QImage>
// include <QGLWidget>

Ground::Ground()
{
    glEnable(GL_TEXTURE_2D);
    // QImage textureGalaxy = QGLWidget::convertToGLFormat(QImage(":/images/textures/galaxy.jpg"));

}

Ground::~Ground()
{
}

void Ground::Display() const
{
    glEnable(GL_TEXTURE_2D);

    QImage galaxy  = QImage(":/images/textures/galaxy.jpg");
    QImage textureSpace = galaxy.convertToFormat(QImage ::Format_RGBA8888);



    GLuint textures ;
    glGenTextures(1,&textures);
    glBindTexture(GL_TEXTURE_2D, textures);
    // on definit les caracteristique de la textures courantes
    glTexImage2D(GL_TEXTURE_2D,0,4, textureSpace.width(),textureSpace.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,textureSpace.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


    glBindTexture(GL_TEXTURE_2D, textures);
    glBegin(GL_QUADS);
    //glColor3ub(60, 169, 113);
    glTexCoord2f(0,0);glVertex3f(-130, -3.0,-200.0);
    glTexCoord2f(1,0);glVertex3f(130, -3.0, -200.0);
    glTexCoord2f(1,1);glVertex3f(130, -3.0, 10.0);
    glTexCoord2f(0,1);glVertex3f(-130, -3.0, 10.0);
    glEnd();
}
