#ifndef ASTEROIDE_H
#define ASTEROIDE_H

/*
 * un asteroide se définit par sa position spatiale
 * et son rayon tiré aléatoirement entre deux marge de valeurs.
 */

class Asteroide
{
public:
    Asteroide(int posX, int posY, int posZ);
    ~Asteroide();
    int getRayon();
    void setRayon();
    int * getPosition();
    void setPosition(int posX, int posY, int posZ);

protected:
    int rayon_;
    int positionX_;
    int positionY_;
    int positionZ_;
    static const double MIN_RAYON_;
    static const double MAX_RAYON_;

};

#endif // ASTEROIDE_H
