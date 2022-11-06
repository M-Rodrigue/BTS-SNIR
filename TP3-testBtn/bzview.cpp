#include "bzview.h"
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>

BzView::BzView(QWidget *parent) : QWidget(parent)
{
    nbPoints = 0;
}

void BzView::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);
    for(int i=0; i<nbPoints; i++){
        painter.drawEllipse(points[i], 6, 6);
    }
}

void BzView::onEffacer()
{
    qDebug() << "Effacer";
}

void BzView::onConstruire(bool checked)
{
    qDebug() << "Construire" << checked;
}

void BzView::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(nbPoints<NBPTS){
            points[nbPoints]=event->pos();
            nbPoints++;
            update();
        }

    }
}
