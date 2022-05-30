#ifndef GROUND_H
#define GROUND_H

#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>
#include <QImage>

class Ground
{
public:
    Ground();

    // Destructeur
    ~Ground();

    // Methode d'affichage
    void Display() const;

private:
    GLuint galaxy_;
};

#endif // GROUND_H
