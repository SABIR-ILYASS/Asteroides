#ifndef ASTEROIDE_H
#define ASTEROIDE_H

class Asteroide
{
public:
    Asteroide();
    Asteroide(double posX,double posY,double posZ,double rayon, bool b);
    // ~Asteroide();

    void Display() const;

    // getters and setters
    double getPositionX(){return posX_;};
    double getPositionY(){return posY_;};
    double getPositionZ(){return posZ_;};
    bool getIdOfAsteroide() {return idOfAsteroide_;};
    double getRayon() {return rayon_;};

    void setRayon(double r) {rayon_ = r;};
    void setPosition(double x,double y,double z);

    void avancerZ(double avanceZ);
    void avancerY(double avanceY);
    void avancerX(double avanceX);

private:
    double posX_;
    double posY_;
    double posZ_;
    bool idOfAsteroide_;
    double rayon_;
};

#endif // ASTEROIDE_H
