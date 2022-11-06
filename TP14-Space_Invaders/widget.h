#ifndef WIDGET_H
#define WIDGET_H

#include <QTimer>
#include <QWidget>

namespace Ui {
class Widget;
}

#define INVCOLS 11 // Nombre de vaisseaux par ligne
#define INVLIGS 5 // Nombre de ligne de vaisseaux
#define INVSPCE 32 // Espace entre les vaisseaux en pixels
#define ALIVE 6 // Valeur initiale pour un vaisseau
#define NBRSHOOT 4 // Nombre de tirs

struct Sprite
{
    int x,y;
    int xOff, yOff;
    int status;
    int version;
};

class Widget : public QWidget
{
    Q_OBJECT
    QImage imgInvader[3][2];
    QImage imgVaisseau,imgTir,imgExplode,imgBomb[2];
    Sprite  invaders[INVLIGS][INVCOLS];
    Sprite ship;
    Sprite shoot[NBRSHOOT];
    QTimer timer;
    int numImg, xOff, yOff;
    double speed;
    int delayTir;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *);
    void initInvaders();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void onTimeout();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
