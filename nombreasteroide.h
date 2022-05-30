#ifndef NOMBREASTEROIDE_H
#define NOMBREASTEROIDE_H

#include <QDialog>

namespace UI{
class NombreAsteroide;
}


class NombreAsteroide : public QDialog
{
    Q_OBJECT
public:
    explicit NombreAsteroide(QWidget *parent = 0);
    ~NombreAsteroide();

signals:
    void startGame();

private slots:

private:
    UI::NombreAsteroide *ui;

};

#endif // NOMBREASTEROIDE_H
