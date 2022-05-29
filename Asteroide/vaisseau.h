#ifndef VAISSEAU_H
#define VAISSEAU_H

#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QImage>

class Vaisseau
{
public:
    Vaisseau();
    ~Vaisseau();

    // eclairage
    void eclairageVaisseau() const;

    void Display() const;
};

#endif // VAISSEAU_H
