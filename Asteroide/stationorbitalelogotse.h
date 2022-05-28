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
    static int const POSITION_Y = 0;
    static int const POSITION_Z = -200;

    double getPositionX(){return posX_;};
    double getPositionY(){return posY_;};
    double getPositionZ(){return posZ_;};

    StationorbitaleLogoTSE();
    void Display() const;

    void avancerZ(double avanceZ);
    void avancerX(double avanceX);

private:
    double posX_;
    double posY_;
    double posZ_;
};

#endif // STATIONORBITALELOGOTSE_H
