#ifndef ASKNOMBREASTEROIDE_H
#define ASKNOMBREASTEROIDE_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class AskNombreAsteroide;
}

class AskNombreAsteroide : public QDialog
{
    Q_OBJECT

public:
    explicit AskNombreAsteroide(QWidget *parent = nullptr);
    ~AskNombreAsteroide();

public slots:
    void play();
    int nmbOfAsteroide();

private:
    Ui::AskNombreAsteroide *ui;

    QPushButton * play_;

    QLabel * textNbrAst_;
    QLabel * titleGame_;
    QLineEdit * nbrAst_;
};

#endif // ASKNOMBREASTEROIDE_H
