#ifndef PAUSEWINDOW_H
#define PAUSEWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class PauseWindow;
}

class PauseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PauseWindow(QWidget *parent = nullptr);
    ~PauseWindow();
    bool quitter_  = false;

public slots:
    // void returnToGame();
    void exit();


private:
    Ui::PauseWindow *ui;

    QLabel * textPause_;

    QPushButton * continue_;
    QPushButton * exit_;

};

#endif // PAUSEWINDOW_H