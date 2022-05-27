#ifndef LISTASTEROIDE_H
#define LISTASTEROIDE_H

#include "asteroide.h"
#include  <QVector>

// using namespace std;

class ListAsteroide : public Asteroide
{
public:
    int static const MIN_X = -120;
    int static const MAX_X = 120;
    int static const MIN_Z = -200;
    int static const MAX_Z = 1;

    ListAsteroide(int n);
    // ~ListAsteroide();
    void ajouterAsteroide(Asteroide a);
    void supprimerAsteroide(int idOfAsteroide);
    void Display() const;
    void creat();
    int * minDistanceXZ(int posX, int posZ);

private:
    int nombreOfAsteroide_;
    QVector<Asteroide> * vectAsteroide_;

};

#endif // LISTASTEROIDE_H
