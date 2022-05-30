#include "keyboarddata.h"

KeyboardData::KeyboardData()
{

}

void KeyboardData::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        idPressButton_ = 1;
        qDebug()<<"A";
    }
    else if (event->key() == Qt::Key_E)
    {
        idPressButton_ = 2;
        qDebug()<<"E";
    }
    else if (event->key() == Qt::Key_Z)
    {
        idPressButton_ = 3;
        qDebug()<<"Z";
    }
    else if (event->key() == Qt::Key_S)
    {
        idPressButton_ = 4;
        qDebug()<<"S";
    }
    else if (event->key() == Qt::Key_X)
    {
        idPressButton_ = 0;
        qDebug()<<"X";
    }
    else
    {
        idPressButton_ = -1;
        qDebug()<<"clavier";
    }
}
