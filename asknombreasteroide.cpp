#include "asknombreasteroide.h"
#include "ui_asknombreasteroide.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

using namespace std;

AskNombreAsteroide::AskNombreAsteroide(QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint),
    ui(new Ui::AskNombreAsteroide)
{
    ui->setupUi(this);
    setFixedSize(320, 480);

    // add buttons and Labels
    titleGame_ = new QLabel("<h1>Jeu Astéroïde</h1>", this);
    textNbrAst_ = new QLabel("<p> Entrez le nombre d'astéroïdes </p>", this); // entre 1 et 40 asteroide
    nbrAst_ = new QLineEdit("16", this);
    play_ = new QPushButton("Jouer", this);

    QString styleSheetnbrAst = "color: #FFFFFF;"
                               "font-size: 35px";

    QString styleSheettitleGame = "color: white;"
                                  "font-size: 22px";

    QString styleSheetTextNbrAst = "color: white;"
                                   "font-size: 20px";

    QString styleSheetPlay = "color: white;"
                             "font-size: 20px";

    titleGame_->setGeometry(20, 30, 280, 60);
    titleGame_->setStyleSheet(styleSheettitleGame);

    textNbrAst_->setGeometry(15, 150, 290, 40);
    textNbrAst_->setStyleSheet(styleSheetTextNbrAst);

    nbrAst_->setGeometry(140, 270, 40, 40);
    nbrAst_->setStyleSheet(styleSheetnbrAst);

    play_->setGeometry(110, 390, 100, 40);
    play_->setStyleSheet(styleSheetPlay);

    // connect slot play:
    connect(play_, SIGNAL(clicked()), this, SLOT(play()));
}

AskNombreAsteroide::~AskNombreAsteroide()
{
    delete ui;
}

void AskNombreAsteroide::play()
{
    int n = this->nmbOfAsteroide();
    if (n > 0 && n <= 40) close();
}

int AskNombreAsteroide::nmbOfAsteroide()
{
    QString number = nbrAst_->text();
    int n = number.toInt();
    nombreOfAsteroide_ = n;
    qDebug()<<n;
    return n;
}

