#include <qdebug.h>
#include "widget.h"
#include "ui_widget.h"

#include <QMouseEvent>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<imgVaisseau.load(":/Images/Vaisseau.bmp");
    qDebug()<<imgTir.load(":/Images/Tir.bmp");
    qDebug()<<imgBomb[0].load(":/Images/BombA.bmp");
    qDebug()<<imgBomb[1].load(":/Images/BombB.bmp");
    qDebug()<<imgExplode.load(":/Images/Explode.bmp");
    qDebug()<<imgInvader[0][0].load(":/Images/Invader1A.bmp");
    qDebug()<<imgInvader[1][0].load(":/Images/Invader2A.bmp");
    qDebug()<<imgInvader[2][0].load(":/Images/Invader3A.bmp");
    qDebug()<<imgInvader[0][1].load(":/Images/Invader1B.bmp");
    qDebug()<<imgInvader[1][1].load(":/Images/Invader2B.bmp");
    qDebug()<<imgInvader[2][1].load(":/Images/Invader3B.bmp");

    //    for(int i=0; i<3; i++){
    //        qDebug()<<imgInvader[i][0].load(":/Images/Invader"+QString::number(i+1)+".bmp");
    //    }
    connect(&timer,SIGNAL(timeout()),SLOT(onTimeout()));
    initInvaders();
    timer.start(40);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(ship.x,ship.y,imgVaisseau);
    for(int lig=0; lig<INVLIGS; lig++){
        for(int col=0; col<INVCOLS; col++){
            if(invaders[lig][col].status>0){
                painter.drawImage(invaders[lig][col].x + xOff,invaders[lig][col].y + yOff,imgInvader[invaders[lig][col].version][(numImg/4)%2]);
            }
        }
    }
    for(int i=0; i<NBRSHOOT; i++){
        if(shoot[i].status>0){
            painter.drawImage(shoot[i].x,shoot[i].y,imgTir);
        }
    }
}

void Widget::initInvaders(){
    for(int lig=0; lig<INVLIGS; lig++){
        for(int col=0; col<INVCOLS; col++){
            invaders[lig][col].status=ALIVE;
            invaders[lig][col].x=col*INVSPCE;
            invaders[lig][col].y=lig*INVSPCE;
            invaders[lig][col].version=(lig+1)/2;
        }
    }
    for(int i=0; i<NBRSHOOT; i++){
        shoot[i].status = 0;
        delay=0;
    }
    numImg=0;
    xOff=yOff=INVSPCE;
    speed=2.0;
    ship.x=400;
    ship.y=500;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->x()>0 && event->x()<width()-imgVaisseau.width()){
        ship.x=event->x();
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(delayTir<0){
        if(event->button()=Qt::LeftButton){
            for(int i=0; i<NBRSHOOT; i++){
                if(shoot[i].status==0){
                    shoot[i].x=event->x()+imgVaisseau.width()/2;
                    shoot[i].y=500-2;
                    shoot[i].status=1;
                    delayTir=5;
                    break;
                }
            }
        }
    }
}

void Widget::onTimeout()
{
    numImg++;
    xOff=xOff+speed;
    bool tourne=false;
    for(int lig=0; lig<INVLIGS; lig++){
        for(int col=0; col<INVCOLS; col++){
            if(invaders[lig][col].x+xOff>=width()-INVSPCE && speed>0){
                tourne=true;
                break;
            } else if(invaders[lig][col].x+xOff<=0 && speed<0){
                tourne=true;
                break;
            }
        }
        if(tourne){
            speed=speed*-1.1;
            yOff=yOff+INVSPCE/2;
        }
        for(int i=0; i<NBRSHOOT; i++){
            if(shoot[i].status>0){
                shoot[i].y=shoot[i].y-SPEEDSHOOT;
                if(shoot[i].y<0){
                    shoot[i].status=0;
                }
            }
        }
    }
    repaint();
}
