#ifndef COLLISIONVAISSEAUASTEROIDE_H
#define COLLISIONVAISSEAUASTEROIDE_H

#include "listasteroide.h"

class CollisionVaisseauAsteroide
{
public:
    CollisionVaisseauAsteroide();
    int collisionVaissauAsteroide();

    void setListOfAsteroide(ListAsteroide listOfAsteroide){ listOfAsteroide_ = listOfAsteroide;};


private:
    ListAsteroide listOfAsteroide_;
};

#endif // COLLISIONVAISSEAUASTEROIDE_H
