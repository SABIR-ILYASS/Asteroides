#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <QElapsedTimer>
#include <QTime>

class Chronometer
{
private:
    QElapsedTimer t_;

public:
    Chronometer();
    void restart() { t_.restart(); }
    QTime getTime() { return QTime(0,0).addMSecs(t_.elapsed()); }
};

#endif // CHRONOMETER_H
