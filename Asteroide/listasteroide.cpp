#include "listasteroide.h"
#include "asteroide.h"

#include <random>
#include <QtMath>
#include <QDebug>

ListAsteroide::ListAsteroide(int n)
{
    nombreOfAsteroide_ = n;
    vectAsteroide_ = new QVector<Asteroide>();
    score_ = 0;
    nombreOfcollision_ = 0;

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
    if (n > 0 and n < vectAsteroide_->length())
        vectAsteroide_->remove(n);
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

        while(disMinXYZ[0] < 10 && disMinXYZ[1] < 10 && disMinXYZ[2] < 10)
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
    qDebug()<<"nombre of asteroide";
    qDebug()<<nombreOfAsteroide_;

    for (int i = 0; i < nombreOfAsteroide_; i++)
    {
        posX = rand() % (this->MAX_X - this->MIN_X) + this->MIN_X;
        posY = rand() % (this->MAX_Y - this->MIN_Y) + this->MIN_Y;
        posZ = rand() % (this->MAX_Z - this->MIN_Z) + this->MIN_Z;
        int rayon = rand() % (this->MAX_RAYON - this->MIN_RAYON) + this->MIN_RAYON;


        int * disMinXYZ2 = this->minDistanceXYZ(posX, posY, posZ);

        while(disMinXYZ2[0] < 10 && disMinXYZ2[1] < 10 && disMinXYZ2[2] < 10)
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

void ListAsteroide::avancerX(int avancementX)
{
    QVector<Asteroide>::iterator itt;
    for (itt = vectAsteroide_->begin(); itt != vectAsteroide_->end(); ++itt)
    {
        itt->avancerX(avancementX);
    }
}

void ListAsteroide::avancerY(int avancementY)
{
    QVector<Asteroide>::iterator itt;
    for (itt = vectAsteroide_->begin(); itt != vectAsteroide_->end(); ++itt)
    {
        itt->avancerY(avancementY);
    }
}

void ListAsteroide::avancerZ(int avancementZ)
{
    QVector<Asteroide>::iterator itt;
    for (itt = vectAsteroide_->begin(); itt != vectAsteroide_->end(); ++itt)
    {
        itt->avancerZ(avancementZ);
    }
}

void ListAsteroide::detecteCollision()
{
    QVector<Asteroide>::iterator itt;
    for (itt = vectAsteroide_->begin(); itt != vectAsteroide_->end(); ++itt)
    {
        if((qSqrt(qPow(itt->getPositionX(),2) + qPow(itt->getPositionY(),2) + qPow(itt->getPositionZ() - 8,2))) < 4)
        {
            if (itt->getIdOfAsteroide())
                score_++;
            else
                nombreOfcollision_++;

        }
    }
}
