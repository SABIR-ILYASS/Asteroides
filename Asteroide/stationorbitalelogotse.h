#ifndef STATIONORBITALELOGOTSE_H
#define STATIONORBITALELOGOTSE_H

#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QImage>

class StationorbitaleLogoTSE
{
public:
    static int const POSITION_X = 0;
    static int const POSITION_Y = 0;
    static int const POSITION_Z = -200;

    StationorbitaleLogoTSE();
    void Display() const;
};

#endif // STATIONORBITALELOGOTSE_H
