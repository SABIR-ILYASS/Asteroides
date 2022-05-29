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
    int posY = rand() % (this->MAX_Y - this->MIN_Y) + this->MIN_Y;
    int posZ = rand() % (this->MAX_Z - this->MIN_Z) + this->MIN_Z;
    int rayon = rand() % (this->MAX_RAYON - this->MIN_RAYON) + this->MIN_RAYON;

    Asteroide * asteroide = new Asteroide(posX, posY, posZ, rayon, true);
    vectAsteroide_->append(* asteroide);

    for (int i = 1; i < 20; i++)
    {
        posX = rand() % (this->MAX_X - this->MIN_X) + this->MIN_X;
        posY = rand() % (this->MAX_Y - this->MIN_Y) + this->MIN_Y;
        posZ = rand() % (this->MAX_Z - this->MIN_Z) + this->MIN_Z;
        int rayon = rand() % (this->MAX_RAYON - this->MIN_RAYON) + this->MIN_RAYON;

        int * disMinXYZ = this->minDistanceXYZ(posX, posY, posZ);

        while(disMinXYZ[0] < 7 && disMinXYZ[1] < 7 && disMinXYZ[2] < 7)
        {
            int posX = rand() % (this->MAX_X - this->MIN_X) + this->MIN_X;
            int posY = rand() % (this->MAX_Y - this->MIN_Y) + this->MIN_Y;
            int posZ = rand() % (this->MAX_Z - this->MIN_Z) + this->MIN_Z;
            disMinXYZ = this->minDistanceXYZ(posX, posY, posZ);
        }

        Asteroide * asteroide = new Asteroide(posX, posY, posZ, rayon, true);
        vectAsteroide_->append(* asteroide);
    }

    // creation des asteroides negatifs

    for (int i = 0; i < nombreOfAsteroide_; i++)
    {
        posX = rand() % (this->MAX_X - this->MIN_X) + this->MIN_X;
        posY = rand() % (this->MAX_Y - this->MIN_Y) + this->MIN_Y;
        posZ = rand() % (this->MAX_Z - this->MIN_Z) + this->MIN_Z;
        int rayon = rand() % (this->MAX_RAYON - this->MIN_RAYON) + this->MIN_RAYON;


        int * disMinXYZ2 = this->minDistanceXYZ(posX, posY, posZ);

        while(disMinXYZ2[0] < 7 && disMinXYZ2[1] < 7 && disMinXYZ2[2] < 7)
        {
            int posX = rand() % (this->MAX_X - this->MIN_X) + this->MIN_X;
            int posY = rand() % (this->MAX_Y - this->MIN_Y) + this->MIN_Y;
            int posZ = rand() % (this->MAX_Z - this->MIN_Z) + this->MIN_Z;
            disMinXYZ2 = this->minDistanceXYZ(posX, posY, posZ);
        }

        Asteroide * asteroide = new Asteroide(posX, posY, posZ, rayon, false);
        vectAsteroide_->append(* asteroide);
    }
}

void ListAsteroide::Display() const
{
    for (int i = 0; i < vectAsteroide_->length(); i++)
        vectAsteroide_->at(i).Display();

}

int * ListAsteroide::minDistanceXYZ(int posX, int posY, int posZ)
{
    int * minDistance = new int[3];
    Asteroide a = vectAsteroide_->at(0);

    int minX = abs(a.getPositionX() - posX);
    int minY = abs(a.getPositionY() - posY);
    int minZ = abs(a.getPositionZ() - posZ);

    for (int i = 1; i < vectAsteroide_->length(); i++)
    {
        Asteroide a = vectAsteroide_->at(i);
        int positionX = a.getPositionX();
        int positionY = a.getPositionY();
        int positionZ = a.getPositionZ();

        int distanceX = abs(positionX - posX);
        int distanceY = abs(positionY - posY);
        int distanceZ = abs(positionZ - posZ);

        if (distanceX < minX)
            minX = distanceX;
        if (distanceY < minY)
            minY = distanceY;
        if (distanceZ < minZ)
            minZ = distanceZ;
    }
    minDistance[0] = minX;
    minDistance[1] = minY;
    minDistance[2] = minZ;

    return minDistance;
}

void ListAsteroide::avancerX()
{
    QVector<Asteroide>::iterator itt;
    for (itt = vectAsteroide_->begin(); itt != vectAsteroide_->end(); ++itt)
    {
        itt->avancerX(1);
    }
}

void ListAsteroide::avancerY()
{
    QVector<Asteroide>::iterator itt;
    for (itt = vectAsteroide_->begin(); itt != vectAsteroide_->end(); ++itt)
    {
        itt->avancerY(1);
    }
}

void ListAsteroide::avancerZ()
{
    QVector<Asteroide>::iterator itt;
    for (itt = vectAsteroide_->begin(); itt != vectAsteroide_->end(); ++itt)
    {
        itt->avancerZ(1);
    }
}


