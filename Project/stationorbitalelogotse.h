#ifndef STATIONORBITALELOGOTSE_H
#define STATIONORBITALELOGOTSE_H


class StationOrbitaleLogoTSE
{

protected:
    int positionX_;
    int positionY_;
    int positionZ_;

public:
    StationOrbitaleLogoTSE(float posX, float posY, float posZ);
    ~StationOrbitaleLogoTSE();
    float gitPositionX() {return positionX_;}
    float gitPositionY() {return positionZ_;}
    float gitPositionZ() {return positionZ_;}
    void setPositions(float x, float y, float z);
};

#endif // STATIONORBITALELOGOTSE_H
