#ifndef SOUND_H
#define SOUND_H

#include <QString>

class Sound
{
private:
    QString * listOfSound_;


public:
    Sound();
    Sound(QString * filesDirections);
    void addSound(QString fileDirection);
    void readSound(int n);

};

#endif // SOUND_H
