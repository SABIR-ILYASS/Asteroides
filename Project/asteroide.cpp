#include "asteroide.h"
#include <QRandomGenerator>

double const Asteroide::MAX_RAYON_ = 5.;
double const Asteroide::MIN_RAYON_ = 20.;


Asteroide::Asteroide(int posX, int posY, int posZ)
{
    this->positionX_ = posX;
    this->positionY_ = posY;
    this->positionZ_ = posZ;

    QRandomGenerator gen = QRandomGenerator();
    int rayon = gen.bounded(MAX_RAYON_- MIN_RAYON_) + MIN_RAYON_;
    this->rayon_ = rayon;
}

Asteroide::~Asteroide()
{

}


void Asteroide::setRayon()
{
    QRandomGenerator gen = QRandomGenerator();
    int rayon = gen.bounded(MAX_RAYON_- MIN_RAYON_) + MIN_RAYON_;
    this->rayon_ = rayon;
}

void Asteroide::setPosition(int posX, int posY, int posZ)
{
    this->positionX_ = posX;
    this->positionY_ = posY;
    this->positionZ_ = posZ;
}

int * Asteroide::getPosition()
{
    int * position = new int[3];
    position[0] = this->positionX_;
    position[1] = this->positionY_;
    position[2] = this->positionZ_;
    return position;
}

int Asteroide::getRayon()
{
    return this->rayon_;
}



