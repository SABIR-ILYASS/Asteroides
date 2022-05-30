#ifndef FINDEJEU_H
#define FINDEJEU_H

#include <QDialog>

namespace Ui {
class FinDeJeu;
}

class FinDeJeu : public QDialog
{
    Q_OBJECT

public:
    explicit FinDeJeu(QWidget *parent = nullptr);
    ~FinDeJeu();

private:
    Ui::FinDeJeu *ui;
};

#endif // FINDEJEU_H
