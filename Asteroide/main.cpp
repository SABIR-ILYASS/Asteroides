#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    // titre de la fenetre principale
    w.setWindowTitle("Jeu Astéroïde, SABIR - SAIF");
    w.setWindowIcon(QIcon(":/images/textures/icon.png"));
    w.show();
    return a.exec();
}
