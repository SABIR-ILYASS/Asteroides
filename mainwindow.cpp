#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "asknombreasteroide.h"
#include "pausewindow.h"
#include "listasteroide.h"
#include "gamewidget.h"
#include "findejeu.h"

#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
#include <QtMath>
#include <QElapsedTimer>
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    nombreScore_ = 0;
    nombreOfNegatifCollision_ = 0;

    ui->setupUi(this);
    setFixedSize(1200, 600);

    QString stringScore = QString::number(nombreScore_);

    // add buttons and Labels
    exit_ = new QPushButton("Quitter la partie", this);
    pause_ = new QPushButton("Pause", this);
    timer_ = new QLabel(this);
    score_ = new QLabel("Score: " + stringScore, this);
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


    gameWidget_ = new GameWidget(this);
    gameWidget_->setIdPressButton(this->idPressButton_);

    gameWindow();
    cameraWindow();

    m_AnimationTimer_ = new QTimer(this);
    //Create and set timer
    m_AnimationTimer_->setInterval(10);
    connect(m_AnimationTimer_, SIGNAL(timeout()),this, SLOT(updateAllWidget()));
    m_AnimationTimer_->start();

    inPause_ = false;

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

    gameWidget_->nombreOfAst_ = this->nombreOfAsteroide_;
    gameWidget_->setGeometry(w * 0.005, h * 0.01, w * 0.49, h * 0.8);

    //gameWidget_->setGeometry(w * 0.005, h * 0.01, w * 0.49, h * 0.8);

}

void MainWindow::cameraWindow()
{
    cameraWidget_ = new CameraWidget(this);
    cameraWidget_->detectionOfHand();
    cameraWidget_->getAction();

    // cameraWidget_->setGeometry(w * 0.505 , h * 0.01, w * 0.49, h * 0.8);
    // cameraWindow_->setStyleSheet("background-color:yellow;border-radius:25%");

    this->gestionAffichageVie();
}

void MainWindow::pause()
{
    inPause_ = true;
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

void MainWindow::gestionAffichageVie(){
    if (nombreOfNegatifCollision_ >= 3){
        vieRestant1_->hide();
        vieRestant2_->hide();
        vieRestant3_->hide();
    } else if(nombreOfNegatifCollision_ == 2){
        vieRestant2_->hide();
        vieRestant3_->hide();
    } else if (nombreOfNegatifCollision_ == 1){
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

void MainWindow::updateAllWidget()
{
    if(! inPause_)
    {
        cameraWidget_->detectionOfHand();
        cameraWidget_->getAction();
        // QString str = cameraWidget_->getAction();
        // gameWidget_->setAction(str);

        gameWidget_->setIdPressButton(this->idPressButton_);
        gameWidget_->detecteCollision();
        this->detecteCollision();
        this->updateStringScore();
        this->gestionAffichageVie();
        gameWidget_->update();
        m_TimeElapsed_ += 0.75f;

        if(finDeJeu_)
        {
            this->finDeJeu();
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
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
    qDebug()<<idPressButton_;
}

void MainWindow::detecteCollision()
{
    nombreScore_ = gameWidget_->getScore();
    nombreOfNegatifCollision_ = gameWidget_->getNombreOfCollision();
}

void MainWindow::updateStringScore()
{
    QString stringScore = QString::number(nombreScore_);
    score_->setText("<h1>Score: " + stringScore + "</h1>");
}

void MainWindow::detecteFinPartie()
{
    int getPositionX = gameWidget_->getPositionOfStationX();
    int getPositionY = gameWidget_->getPositionOfStationY();
    int getPositionZ = gameWidget_->getPositionOfStationZ();

    if (getPositionZ > 7)
    {
        if(qSqrt(abs(getPositionX) + abs(getPositionY) + abs(getPositionZ)) < 3 && nombreOfNegatifCollision_ <= 3)
        {
            finDeJeu_ = true;
            isWin_ = true;
        }

        else{
            finDeJeu_ = true;
            isWin_ = false;
        }
    } else
    {
        finDeJeu_ = false;
        isWin_ = false;
    }

}

void MainWindow::finDeJeu()
{
    inPause_ = true;
    FinDeJeu finDeJeuWindow(this);
    finDeJeuWindow.exec();
}
