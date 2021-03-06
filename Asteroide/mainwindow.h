#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QTimer>

#include "chronometer.h"
#include "gamewidget.h"
#include "camerawidget.h"
#include "findejeu.h"

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
    void gestionAffichageVie();
    void stopTime();

    void updateStringScore();

    void detecteCollision();

    void detecteFinPartie();

    void detectionOfHand();

    void keyPressEvent(QKeyEvent * event);

    void fin();
    void rejouer();

public slots:
    void pause();
    void exit();
    void UpdateTime();
    void updateAllWidget();
    void finDeJeu();

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
    bool inPause_ = false;

    bool finDeJeu_ = false;
    bool isWin_ = false;

    Chronometer c_;
    QTimer time_;

    float m_TimeElapsed_ { 0.0f };
    QTimer * m_AnimationTimer_;

    GameWidget * gameWidget_;
    CameraWidget * cameraWidget_;

    FinDeJeu * finDeJeuWidget_;

    int idPressButton_;

    int nombreOfAsteroide_;

    int nombreScore_;
    int nombreOfNegatifCollision_;

    int seconds1_;

    QString detectionAction_;

};
#endif // MAINWINDOW_H
