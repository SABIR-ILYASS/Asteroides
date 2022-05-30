#include "pausewindow.h"
#include "ui_pausewindow.h"

#include <QMessageBox>
#include <QPushButton>
#include <QDebug>

PauseWindow::PauseWindow(QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint),
    ui(new Ui::PauseWindow)
{
    ui->setupUi(this);
    setFixedSize(300, 300);

    // add buttons and Labels
    textPause_ = new QLabel("<h1> Pause </h1>", this);
    continue_ = new QPushButton("Continuer", this);
    exit_ = new QPushButton("Quitter", this);

    QString styleSheetButton = "color: white;"
                               "background-color: rgb(3, 73, 252);"
                               "font-size: 20px;"
                               "border-radius:25%";

    QString styleSheetLabel = "color: rgb(3, 73, 252);"
                              "font-size: 30px;";

    textPause_->setGeometry(70, 15, 160, 70);
    textPause_->setStyleSheet(styleSheetLabel);

    continue_->setGeometry(100, 125, 100, 50);
    continue_->setStyleSheet(styleSheetButton);

    exit_->setGeometry(100, 225, 100, 50);
    exit_->setStyleSheet(styleSheetButton);

    // connect slots:
    connect(continue_, SIGNAL(clicked()), this, SLOT(close()));
    connect(exit_, SIGNAL(clicked()), this, SLOT(exit()));
}

PauseWindow::~PauseWindow()
{
    delete ui;
}

void PauseWindow::exit()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Attention", "Vous voulez quitter le jeu?",
                                  QMessageBox::No|QMessageBox::Yes);
    if (reply == QMessageBox::Yes) {
        quitter_ = true;
        close();
    }
    else{
        // pause
    }
}
