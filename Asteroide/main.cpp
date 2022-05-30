#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // titre de la fenetre principale
    w.setWindowTitle("Jeu Astéroïde");
    w.setWindowIcon(QIcon(":/images/textures/icon.png"));
    w.show();
    return a.exec();
}
