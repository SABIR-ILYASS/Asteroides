#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QTimer>

#include "chronometer.h"
#include "gamewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void gameWindow();
    void cameraWindow();
    void gestionAffichageVie(int n);
    void stopTime();
    int nombreOfAsteroide_;

public slots:
    void pause();
    void exit();
    void UpdateTime();

private:
    Ui::MainWindow *ui;

    QPushButton * pause_;
    QPushButton * exit_;

    QLabel * timer_;
    QLabel * score_;
    QLabel * vieRestant1_;
    QLabel * vieRestant2_;
    QLabel * vieRestant3_;

    bool QuitterViaPause_ = false;

    Chronometer c_;
    QTimer time_;

    GameWidget * gameWidget_;

};
#endif // MAINWINDOW_H
