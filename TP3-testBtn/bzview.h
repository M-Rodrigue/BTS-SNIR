#ifndef BZVIEW_H
#define BZVIEW_H

#include <QWidget>
#define NBPTS 4

class BzView : public QWidget
{
    Q_OBJECT
    int nbPoints;
    QPoint points[NBPTS];

public:
    explicit BzView(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void onEffacer();
    void onConstruire(bool checked);
    void mousePressEvent(QMouseEvent *event);
};

#endif // BZVIEW_H
