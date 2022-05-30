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

// constructeur de MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    nombreScore_ = 0;
    nombreOfNegatifCollision_ = 0;

    detectionAction_ = "";

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
    m_AnimationTimer_->setInterval(3);

    connect(m_AnimationTimer_, SIGNAL(timeout()),this, SLOT(updateAllWidget()));

    // connect(m_AnimationTimer_, SIGNAL(timeout()),this, SLOT(finDejeu()));
    m_AnimationTimer_->start();

    inPause_ = false;
    seconds1_ = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

// fonction permet d'ajouter un label de scene de jeu
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

// fonction permet d'ajouter un label de camera
void MainWindow::cameraWindow()
{
    cameraWidget_ = new CameraWidget(this);
    cameraWidget_->detectionOfHand();
    cameraWidget_->getAction();

    // cameraWidget_->setGeometry(w * 0.505 , h * 0.01, w * 0.49, h * 0.8);
    // cameraWindow_->setStyleSheet("background-color:yellow;border-radius:25%");

    this->gestionAffichageVie();
}

// fonction permet de faire les pause
void MainWindow::pause()
{
    inPause_ = true;
    PauseWindow pauseWindow(this);
    pauseWindow.exec();
    bool b = pauseWindow.quitter_;
    if (b){
        close();
    }

}

// fonction permet de quitter
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

// fonction permet de voir nombre de vie restée pour le vaisseau
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

// fonction permet de faire mise à jour du temps
void MainWindow::UpdateTime()
{
    int seconds2 = QTime(0, 0, 0).secsTo(c_.getTime());
    if (seconds2 > seconds1_){
        qDebug()<<seconds2;
        seconds1_ = seconds2;
    }
}

void MainWindow::stopTime()
{

}

// fonction permet de faire mise à jour et synchroniser les éléments du fenetre principale
void MainWindow::updateAllWidget()
{
    if(! inPause_ && !finDeJeu_)
    {
        cameraWidget_->detectionOfHand();
        cameraWidget_->getAction();
        // QString str = cameraWidget_->getAction();
        // gameWidget_->setAction(str);

        gameWidget_->setIdPressButton(this->idPressButton_);
        gameWidget_->detecteCollision();
        this->detectionOfHand();
        this->detecteFinPartie();
        this->detecteCollision();
        this->updateStringScore();
        this->gestionAffichageVie();
        this->fin();
        gameWidget_->update();
        m_TimeElapsed_ += 0.75f;

    }
}

// fonction pour récuperer les événements du clavier
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
    else if (event->key() == Qt::Key_W)
    {
        idPressButton_ = 0;
        qDebug()<<"w";
    }

    else
    {
        idPressButton_ = -1;
        qDebug()<<"clavier";
    }

}

// fonction pour detecter les collisions
void MainWindow::detecteCollision()
{
    nombreScore_ = gameWidget_->getScore();
    nombreOfNegatifCollision_ = gameWidget_->getNombreOfCollision();
}

// fonction pour faire mise à jour du score
void MainWindow::updateStringScore()
{
    QString stringScore = QString::number(nombreScore_);
    score_->setText("<h1>Score: " + stringScore + "</h1>");
}

// fonction pour detecter la fin du jeu
void MainWindow::detecteFinPartie()
{
    int getPositionX = gameWidget_->getPositionOfStationX();
    int getPositionY = gameWidget_->getPositionOfStationY();
    int getPositionZ = gameWidget_->getPositionOfStationZ();

    if (nombreOfNegatifCollision_ >= 1){
        finDeJeu_ = true;
        isWin_ = false;
    }
    else if (getPositionZ > 3)
    {
        if(qSqrt(qPow(getPositionX,2) + qPow(getPositionY,2) + qPow(getPositionZ,2)) < 7)
        {
            finDeJeu_ = true;
            isWin_ = true;
        }
        else
        {
            finDeJeu_ = true;
            isWin_ = false;
        }
    }
}

// fonction pour afficher la fenetre du fin de jeu
void MainWindow::finDeJeu()
{

    FinDeJeu finDeJeuWindow(this);

    finDeJeuWindow.setNbrIsGagne(isWin_);

    finDeJeuWindow.setNbrScore(nombreScore_);
    finDeJeuWindow.setNbrstrTime(QString::number(seconds1_));



    finDeJeuWindow.exec();

}

// fonction permet d'appeler la fonction finDejeu() si le jeu est terminer
void MainWindow::fin()
{

    if (finDeJeu_)
    {
        finDeJeu();
    }
}

// fonction permet de faire mise a jour des evenements de la main
void MainWindow::detectionOfHand()
{
    detectionAction_ = cameraWidget_->getAction();
    gameWidget_->setDetectionAction(detectionAction_);
}
