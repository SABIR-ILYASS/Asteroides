#ifndef ASTEROIDE_H
#define ASTEROIDE_H

/*
 * un asteroide se définit par sa position spatiale
 * et son rayon tiré aléatoirement entre deux marge de valeurs.
 */

class Asteroide
{
public:
    Asteroide(float posX, float posY, float posZ);
    ~Asteroide();
    float getRayon();
    void setRayon();
    float * getPosition();
    void setPosition(float posX, float posY, float posZ);

protected:
    float rayon_;
    float positionX_;
    float positionY_;
    float positionZ_;
    static const float MIN_RAYON_;
    static const float MAX_RAYON_;

};

#endif // ASTEROIDE_H
