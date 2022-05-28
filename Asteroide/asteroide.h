#ifndef ASTEROIDE_H
#define ASTEROIDE_H

class Asteroide
{
public:
    Asteroide();
    Asteroide(double posX,double posY, double posZ, bool b);
    // ~Asteroide();

    void Display() const;


    double getPositionX(){return posX_;};
    double getPositionY(){return posY_;};
    double getPositionZ(){return posZ_;};
    bool getIdOfAsteroide() {return idOfAsteroide_;};

    void setPosition(double x,double y,double z);
    void avancerZ(double avanceZ);
    void avancerX(double avanceX);

private:
    double posX_;
    double posY_;
    double posZ_;
    bool idOfAsteroide_;
};

#endif // ASTEROIDE_H
