#ifndef FINDEJEU_H
#define FINDEJEU_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class FinDeJeu;
}

class FinDeJeu : public QDialog
{
    Q_OBJECT

public:
    explicit FinDeJeu(QWidget *parent = nullptr);
    ~FinDeJeu();

    bool getQuitteer(){return quitteer_;};
    void setNbrScore(int n){nbrScore_ = n;};
    void setNbrstrTime(QString strTime){strTime_ = strTime;};
    void setNbrIsGagne(bool isGagne){isGagne_ = isGagne;};



public slots:
    void play();
    void quitter();

private:
    Ui::FinDeJeu *ui;

    QPushButton * rejouer_;
    QPushButton * quitter_;

    QLabel * titleGame_;
    QLabel * gagner_;
    QLabel * score_;
    QLabel * time_;

    int nbrScore_;
    QString strTime_;

    bool isGagne_ = false;

    bool quitteer_ = false;
    bool reprendeJeu_ = false;
};

#endif // FINDEJEU_H
