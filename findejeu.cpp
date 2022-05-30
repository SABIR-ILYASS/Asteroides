#include "findejeu.h"
#include "ui_findejeu.h"

FinDeJeu::FinDeJeu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FinDeJeu)
{
    ui->setupUi(this);
}

FinDeJeu::~FinDeJeu()
{
    delete ui;
}
