#include "findejeu.h"
#include "ui_findejeu.h"

// constructeur de fin de jeu
FinDeJeu::FinDeJeu(QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint),
    ui(new Ui::FinDeJeu)
{
    ui->setupUi(this);
    setFixedSize(320, 480);

    QString isWin;

    if (isGagne_){
        isWin = "Bravo, vous avez gagné le jeu";
    }
    else
    {
        isWin = "Partie perdue!";
    }

    // add buttons and Labels

    titleGame_ = new QLabel("<h1>Fin du jeu</h1>", this);
    titleGame_->setAlignment(Qt::AlignCenter);

    gagner_ = new QLabel(isWin, this);
    gagner_->setAlignment(Qt::AlignCenter);

    score_ = new QLabel(QString::number(nbrScore_), this); // entre 1 et 40 asteroide
    time_ = new QLabel(strTime_, this);

    rejouer_ = new QPushButton("Rejouer", this);
    quitter_ = new QPushButton("Quitter", this);


    QString styleSheetnbrAst = "color: black;"
                               "font-size: 35px";

    QString styleSheettitleGame = "color: black;"
                                  "font-size: 22px";

    QString styleSheetTextNbrAst = "color: black;"
                                   "font-size: 20px";

    QString styleSheetPlay = "color: black;"
                             "font-size: 20px";

    titleGame_->setGeometry(20, 30, 280, 60);
    titleGame_->setStyleSheet(styleSheettitleGame);

    gagner_->setGeometry(15, 150, 290, 40);
    gagner_->setStyleSheet(styleSheetTextNbrAst);

    score_->setGeometry(140, 270, 40, 40);
    score_->setStyleSheet(styleSheetnbrAst);

    time_->setGeometry(110, 390, 100, 40);
    time_->setStyleSheet(styleSheetPlay);

    rejouer_->setGeometry(110, 390, 100, 40);
    rejouer_->setStyleSheet(styleSheetPlay);

    quitter_->setGeometry(110, 390, 100, 40);
    quitter_->setStyleSheet(styleSheetPlay);

    // connect slot play:
    connect(rejouer_, SIGNAL(clicked()), this, SLOT(play()));
}

FinDeJeu::~FinDeJeu()
{
    delete ui;
}

// reprendre le jeu
void FinDeJeu::play()
{
    reprendeJeu_ = true;
}

// quitter le jeu
void FinDeJeu::quitter()
{
    close();
    quitteer_ = true;
}
