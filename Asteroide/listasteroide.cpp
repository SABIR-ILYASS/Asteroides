#include "listasteroide.h"
#include "asteroide.h"

#include <random>
#include <QDebug>

ListAsteroide::ListAsteroide(int n)
{
    nombreOfAsteroide_ = n;
    vectAsteroide_ = new QVector<Asteroide>();

}

/*
ListAsteroide::~ListAsteroide()
{
    for (int i = 0; i < vectAsteroide_->length(); i++)
        vectAsteroide_->removeLast();
}
*/

void ListAsteroide::ajouterAsteroide(Asteroide a)
{
    vectAsteroide_->append(a);
    // this->creat();
}

void ListAsteroide::supprimerAsteroide(int n)
{

}

void ListAsteroide::creat()
{
    // creation des asteroides positifs
    int posX = rand() % (this->MAX_X - this->MIN_X) + this->MIN_X;
    int posZ = rand() % (this->MAX_Z - this->MIN_Z) + this->MIN_Z;

    Asteroide * asteroide = new Asteroide(posX, 0, posZ, true);
    vectAsteroide_->append(* asteroide);

    for (int i = 1; i < 20; i++)
    {
        posX = rand() % (this->MAX_X - this->MIN_X) + this->MIN_X;
        posZ = rand() % (this->MAX_Z - this->MIN_Z) + this->MIN_Z;

        int * disMinXZ = this->minDistanceXZ(posX, posZ);

        while(disMinXZ[0] < 7 && disMinXZ[1] < 7)
        {
            int posX = rand() % (this->MAX_X - this->MIN_X) + this->MIN_X;
            int posZ = rand() % (this->MAX_Z - this->MIN_Z) + this->MIN_Z;
            disMinXZ = this->minDistanceXZ(posX, posZ);
        }

        Asteroide * asteroide = new Asteroide(posX, 0, posZ, true);
        vectAsteroide_->append(* asteroide);
    }

    qDebug()<<nombreOfAsteroide_;

    // creation des asteroides negatifs


    for (int i = 0; i < nombreOfAsteroide_; i++)
    {
        posX = rand() % (this->MAX_X - this->MIN_X) + this->MIN_X;
        posZ = rand() % (this->MAX_Z - this->MIN_Z) + this->MIN_Z;

        int * disMinXZ2 = this->minDistanceXZ(posX, posZ);

        while(disMinXZ2[0] < 7 && disMinXZ2[1] < 7)
        {
            int posX = rand() % (this->MAX_X - this->MIN_X) + this->MIN_X;
            int posZ = rand() % (this->MAX_Z - this->MIN_Z) + this->MIN_Z;
            disMinXZ2 = this->minDistanceXZ(posX, posZ);
        }

        Asteroide * asteroide = new Asteroide(posX, 0, posZ, false);
        vectAsteroide_->append(* asteroide);
    }


}

void ListAsteroide::Display() const
{
    for (int i = 0; i < vectAsteroide_->length(); i++)
        vectAsteroide_->at(i).Display();

}

int * ListAsteroide::minDistanceXZ(int posX, int posZ)
{
    int * minDistance = new int[2];
    Asteroide a = vectAsteroide_->at(0);

    int minX = abs(a.getPositionX() - posX);
    int minZ = abs(a.getPositionZ() - posZ);

    for (int i = 1; i < vectAsteroide_->length(); i++)
    {
        Asteroide a = vectAsteroide_->at(i);
        int positionX = a.getPositionX();
        int positionZ = a.getPositionZ();

        int distanceX = abs(positionX - posX);
        int distanceZ = abs(positionZ - posZ);

        if (distanceX < minX)
            minX = distanceX;
        if (distanceZ < minZ)
            minZ = distanceZ;
    }
    minDistance[0] = minX;
    minDistance[1] = minZ;

    return minDistance;
}

