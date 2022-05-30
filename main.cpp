#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Jeu Astéroïde");
    w.setWindowIcon(QIcon(":/images/textures/icon.png"));
    w.show();
    return a.exec();
}
