#ifndef LISTASTEROIDE_H
#define LISTASTEROIDE_H

#include "asteroide.h"
#include  <QVector>
#include <QKeyEvent>

class ListAsteroide : public Asteroide
{
public:
    int static const MIN_X = -100;
    int static const MAX_X = 100;
    int static const MAX_Y = 20;
    int static const MIN_Y = -20;
    int static const MIN_Z = -200;
    int static const MAX_Z = 1;
    int static const MAX_RAYON  = 5;
    int static const MIN_RAYON = 1;

    ListAsteroide(int n);
    void ajouterAsteroide(Asteroide a);
    void supprimerAsteroide(int idOfAsteroide);
    void Display() const;
    void creat();
    int * minDistanceXYZ(int posX, int posY, int posZ);

    void avancerX(int avancementX);
    void avancerY(int avancementY);
    void avancerZ(int avancementZ);

    void setNombreOfAsteroide(int n){ nombreOfAsteroide_ = n;};
    int getNombreOfAsteroide() {return nombreOfAsteroide_;};

    int getScore(){return score_;};
    int getNombreOfCollision(){return nombreOfcollision_;};

    void detecteCollision();

    QVector<Asteroide> getListOfAsteroide(){return * vectAsteroide_;};

private:
    int nombreOfAsteroide_;
    QVector<Asteroide> * vectAsteroide_;
    int score_;
    int nombreOfcollision_;

};

#endif // LISTASTEROIDE_H
