#include "findejeu.h"
#include "ui_findejeu.h"

#include <QMessageBox>

// constructeur de fin de jeu
FinDeJeu::FinDeJeu(QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint),
    ui(new Ui::FinDeJeu)
{
    ui->setupUi(this);
    setFixedSize(320, 480);

    QString styleSheettitleGame = "color: black;"
                                  "font-size: 15px;";
    // add buttons and Labels
    titleGame_ = new QLabel("<h1>Fin du jeu</h1>", this);
    titleGame_->setGeometry(20, 20, 280, 40);
    titleGame_->setStyleSheet(styleSheettitleGame);

    titleGame_->setAlignment(Qt::AlignCenter);


    /*
    time_ = new QLabel("<h1>Temps du jeu: " + strTime_ + "</h1>", this);
    time_ ->setAlignment(Qt::AlignCenter);

    */

    rejouer_ = new QPushButton("Rejouer", this);
    quitter_ = new QPushButton("Quitter", this);


    QString styleSheetPlay = "color: black;"
                             "font-size: 10px";


    /*
    QString styleSheetnbrAst = "color: black;"
                               "font-size: 15px;";

    QString styleSheetText = "color: black;"
                                   "font-size: 10px";



    gagner_->setGeometry(20, 100, 280, 40);
    gagner_->setStyleSheet(styleSheetText);

    score_->setGeometry(20, 180, 280, 40);
    score_->setStyleSheet(styleSheetnbrAst);

    */

    /*
    time_->setGeometry(20, 260, 280, 40);
    time_->setStyleSheet(styleSheetPlay);
    */

    rejouer_->setGeometry(120, 340, 80, 40);
    rejouer_->setStyleSheet(styleSheetPlay);

    quitter_->setGeometry(120, 420, 80, 40);
    quitter_->setStyleSheet(styleSheetPlay);

    // connect slot play:
    connect(rejouer_, SIGNAL(clicked()), this, SLOT(play()));
    connect(quitter_, SIGNAL(clicked()), this, SLOT(quitter()));

    // isGagne_ = false;
    // reprendeJeu_ = false;
    // quitteer_ = false;
}

FinDeJeu::~FinDeJeu()
{
    delete ui;
}

// reprendre le jeu
void FinDeJeu::play()
{
    reprendeJeu_ = true;
    close();
}

// quitter le jeu
void FinDeJeu::quitter()
{
    quitteer_ = true;
    close();

}

void FinDeJeu::paint()
{
    QString isWin;

    if (isGagne_){
        isWin = "Bravo, vous avez gagné le jeu";
    }
    else
    {
        isWin = "Partie perdue!";
    }

    gagner_ = new QLabel(isWin, this);
    gagner_->setAlignment(Qt::AlignCenter);

    score_ = new QLabel("<h1> Score: " + QString::number(nbrScore_) + "</h1>", this); // entre 1 et 40 asteroide
    score_ ->setAlignment(Qt::AlignCenter);

    QString styleSheettitleGame = "color: black;"
                                  "font-size: 15px;";

    QString styleSheetnbrAst = "color: black;"
                               "font-size: 15px;";

    QString styleSheetText = "color: black;"
                                   "font-size: 10px";

    QString styleSheetPlay = "color: black;"
                             "font-size: 10px";


    gagner_->setGeometry(20, 100, 280, 40);
    gagner_->setStyleSheet(styleSheetText);

    score_->setGeometry(20, 180, 280, 40);
    score_->setStyleSheet(styleSheetnbrAst);

    /*
    time_->setGeometry(20, 260, 280, 40);
    time_->setStyleSheet(styleSheetPlay);
    */

}
