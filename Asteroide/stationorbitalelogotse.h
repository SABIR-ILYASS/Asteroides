#ifndef STATIONORBITALELOGOTSE_H
#define STATIONORBITALELOGOTSE_H

#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QImage>

class StationorbitaleLogoTSE
{
public:
    static int const MIN_POSITION_X = -50;
    static int const MAX_POSITION_X = 50;
    static int const MIN_POSITION_Y = -10;
    static int const MAX_POSITION_Y = 10;

    StationorbitaleLogoTSE();

    double getPositionX(){return posX_;};
    void setPositionX(double posX){posX_ = posX;};
    double getPositionY(){return posY_;};
    void setPositionY(double posY){posY_ = posY;};
    double getPositionZ(){return posZ_;};
    void setPositionZ(double posZ){posZ_ = posZ;};
    int getAngleRoration(){return angleRotation_;};
    void setRotation(int angle){angleRotation_ = angle;};


    void Display() const;

    void avancerX(double avanceX);
    void avancerY(double avanceY);
    void avancerZ(double avanceZ);

private:
    double posX_;
    double posY_;
    double posZ_;
    int angleRotation_;
    bool clign_ = false;

};

#endif // STATIONORBITALELOGOTSE_H
