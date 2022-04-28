#include "asteroide.h"
#include <QRandomGenerator>
#include <GL/glu.h>
#include <QApplication>
#include <QDebug>

float const Asteroide::MAX_RAYON_ = 1.f;
float const Asteroide::MIN_RAYON_ = 0.f;


Asteroide::Asteroide(float posX, float posY, float posZ)
{
    this->positionX_ = posX;
    this->positionY_ = posY;
    this->positionZ_ = posZ;

    QRandomGenerator gen = QRandomGenerator();
    double rayon = gen.generateDouble() * (MAX_RAYON_- MIN_RAYON_) + MIN_RAYON_;
    QString h = QString::number(rayon);
    qDebug(h.toLatin1());
    this->rayon_ = rayon;

    GLUquadric * quadrique = gluNewQuadric();
    gluQuadricDrawStyle(quadrique, GLU_LINE);
    gluSphere(quadrique, this->rayon_, 20, 20);
    gluDeleteQuadric(quadrique);
}

Asteroide::~Asteroide()
{

}


void Asteroide::setRayon()
{
    QRandomGenerator gen = QRandomGenerator();
    float rayon = gen.bounded(MAX_RAYON_- MIN_RAYON_) + MIN_RAYON_;
    this->rayon_ = rayon;
}

void Asteroide::setPosition(float posX, float posY, float posZ)
{
    this->positionX_ = posX;
    this->positionY_ = posY;
    this->positionZ_ = posZ;
}

float * Asteroide::getPosition()
{
    float * position = new float[3];
    position[0] = this->positionX_;
    position[1] = this->positionY_;
    position[2] = this->positionZ_;
    return position;
}

float Asteroide::getRayon()
{
    return this->rayon_;
}



