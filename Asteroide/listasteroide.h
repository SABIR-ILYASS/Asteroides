#ifndef LISTASTEROIDE_H
#define LISTASTEROIDE_H

#include "asteroide.h"
#include  <QVector>
#include <QKeyEvent>

// using namespace std;

class ListAsteroide : public Asteroide
{
public:
    int static const MIN_X = -50;
    int static const MAX_X = 50;
    int static const MIN_Z = -200;
    int static const MAX_Z = 1;

    ListAsteroide(int n);
    // ~ListAsteroide();
    void ajouterAsteroide(Asteroide a);
    void supprimerAsteroide(int idOfAsteroide);
    void Display() const;
    void creat();
    int * minDistanceXZ(int posX, int posZ);
    void avancerZ();

private:
    int nombreOfAsteroide_;
    QVector<Asteroide> * vectAsteroide_;

};

#endif // LISTASTEROIDE_H
