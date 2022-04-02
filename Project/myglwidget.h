#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>


// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);

    // gérer les interactions clavier
    void keyPressEvent(QKeyEvent * keyEvent);

protected:
    // la forme qu'on veut
    int count_ = 0;
    // couleurs du fond
    int colorfR_ = 0;
    int colorfG_ = 0;
    int colorfB_ = 0;

    // couleur de triangle
    int colortR_ = 0;
    int colortG_ = 0;
    int colortB_ = 255;

    // angle de rotation: par défaut veut zero
    float angleRotat_ = 0;

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();
};

#endif // MYGLWIDGET_H
