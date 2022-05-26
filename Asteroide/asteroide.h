#ifndef ASTEROIDE_H
#define ASTEROIDE_H

class Asteroide
{
public:
    Asteroide();
    Asteroide(double posX,double posY, double posZ);
    ~Asteroide();

    void Display() const;


    double getPositionX(){return posX_;};
    double getPositionY(){return posY_;};
    double getPositionZ(){return posZ_;};

    void setPosition(double x,double y,double z);

private:
    double posX_;
    double posY_;
    double posZ_;
};

#endif // ASTEROIDE_H
