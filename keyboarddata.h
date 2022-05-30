#ifndef KEYBOARDDATA_H
#define KEYBOARDDATA_H

#include <QKeyEvent>

class KeyboardData
{
public:
    KeyboardData();
    void keyPressEvent(QKeyEvent * event);
    int getIdPressButton() {return idPressButton_;};

private:
    int idPressButton_;
};

#endif // KEYBOARDDATA_H
