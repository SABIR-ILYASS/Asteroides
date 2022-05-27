#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "asknombreasteroide.h"
#include "pausewindow.h"
#include "gamewidget.h"

#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
#include <QTime>

#include <QElapsedTimer>

#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1200, 600);

    // add buttons and Labels
    exit_ = new QPushButton("Quitter la partie", this);
    pause_ = new QPushButton("Pause", this);
    timer_ = new QLabel(this);
    score_ = new QLabel("<h1>Score: </h1>", this);
    vieRestant1_ = new QLabel(this);
    vieRestant2_ = new QLabel(this);
    vieRestant3_ = new QLabel(this);

    /*
    timer_->setText(QTime(0, 0).toString());
    QElapsedTimer t;
    t.restart();
    QTime time = QTime(0,0).addMSecs(t.elapsed());
*/

    QString styleSheetButton = "color: rgb(0, 0, 120);"
                               "background-color: white;"
                               "font-size: 30px;"
                               "border-radius:25%";

    QString styleSheetLabel = "color: white;"
                               "background-color: rgb(0, 0, 120);"
                               "font-size: 10px;"
                               "border-radius:25%";

    int w = ui->centralwidget->width();
    int h = ui->centralwidget->height();

    exit_->setGeometry(w * 0.01, h * 0.855, w * 0.18, h * 0.1);
    exit_->setStyleSheet(styleSheetButton);

    pause_->setGeometry(w * 0.21, h * 0.855, w * 0.18, h * 0.1);
    pause_->setStyleSheet(styleSheetButton);

    /*
    timer_->setGeometry(w * 0.41, h * 0.855, w * 0.18, h * 0.1);
    timer_->setStyleSheet(styleSheetLabel);
    timer_->setText(QTime(0, 0).toString());
    c_.restart();
    time_.start(1000);
    */

    score_->setGeometry(w * 0.61, h * 0.855, w * 0.18, h * 0.1);
    score_->setAlignment(Qt::AlignCenter);
    score_->setStyleSheet(styleSheetLabel);

    QPixmap pix(":/images/textures/vaisseau-spatial.png");
    vieRestant1_->setPixmap(pix.scaled(w * 0.6, h * 0.1,Qt::KeepAspectRatio));
    vieRestant2_->setPixmap(pix.scaled(w * 0.6, h * 0.1,Qt::KeepAspectRatio));
    vieRestant3_->setPixmap(pix.scaled(w * 0.6, h * 0.1,Qt::KeepAspectRatio));
    vieRestant1_->setGeometry(w * 0.81, h * 0.855, w * 0.6, h * 0.1);
    vieRestant2_->setGeometry(w * 0.87, h * 0.855, w * 0.6, h * 0.1);
    vieRestant3_->setGeometry(w * 0.93, h * 0.855, w * 0.6, h * 0.1);

    QPixmap logo(":/images/textures/logo.png");
    timer_->setPixmap(logo.scaled(w * 0.7 , h * 0.15 ,Qt::KeepAspectRatio));
    timer_->setGeometry(w * 0.47, h * 0.855,  w * 0.6, h * 0.1);

    AskNombreAsteroide asknombreasteroide(this);
    this->nombreOfAsteroide_ = asknombreasteroide.nombreOfAsteroide_;
    asknombreasteroide.exec();

    // connect slots:
    connect(exit_, SIGNAL(clicked()), this, SLOT(exit()));
    connect(pause_, SIGNAL(clicked()), this, SLOT(pause()));

    gameWindow();
    cameraWindow();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gameWindow()
{
    int w = ui->centralwidget->width();
    int h = ui->centralwidget->height();

    // QLabel * gameWindow_ = new QLabel(this);
    // gameWindow_->setGeometry(w * 0.005, h * 0.01, w * 0.49, h * 0.8);
    // gameWindow_->setStyleSheet("background-color:red;border-radius:25%");


    gameWidget_ = new GameWidget(this);
    gameWidget_->nombreOfAst_ = this->nombreOfAsteroide_;

    gameWidget_->setGeometry(w * 0.005, h * 0.01, w * 0.49, h * 0.8);
    gameWidget_->setStyleSheet("border-radius:25%");

    //gameWidget_->setGeometry(w * 0.005, h * 0.01, w * 0.49, h * 0.8);




}

void MainWindow::cameraWindow()
{
    int w = ui->centralwidget->width();
    int h = ui->centralwidget->height();

    QLabel * cameraWindow_ = new QLabel(this);
    cameraWindow_->setGeometry(w * 0.505 , h * 0.01, w * 0.49, h * 0.8);
    cameraWindow_->setStyleSheet("background-color:yellow;border-radius:25%");

    this->gestionAffichageVie(9);

}

void MainWindow::pause()
{
    PauseWindow pauseWindow(this);
    pauseWindow.exec();
    bool b = pauseWindow.quitter_;
    if (b){
        close();
    }
    qDebug()<<33333333333;

}

void MainWindow::exit()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Attention", "Vous voulez quitter le jeu?",
                                  QMessageBox::No|QMessageBox::Yes);
    if (reply == QMessageBox::Yes) {
        close();
    }
    else{
        // pause
    }
}

void MainWindow::gestionAffichageVie(int n){
    if (n == 0){
        vieRestant1_->hide();
        vieRestant2_->hide();
        vieRestant3_->hide();
    } else if(n == 1){
        vieRestant2_->hide();
        vieRestant3_->hide();
    } else if (n == 2){
        vieRestant3_->hide();
    }
}

void MainWindow::UpdateTime()
{
    /*
    int seconds1 = 0;
    int seconds2 = QTime(0, 0, 0).secsTo(c_.getTime());
    if (seconds2 > seconds1){
        qDebug()<<seconds2;
        seconds1 = seconds2;

    }
    while(seconds1 < 3600){
        timer_->setText(this->c_.getTime().toString());
    }
    */

}

void MainWindow::stopTime()
{

}
