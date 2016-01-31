#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include "circle.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <QTime>
class paintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit paintWidget(QWidget *parent = 0);
    void  paintEvent(QPaintEvent *event);
    void setCircle(circle *_cercle);
    void reXY(int x, int y);

    void mouseReleaseEvent ( QMouseEvent * event );
    void mouseMoveEvent ( QMouseEvent * event );
    void mousePressEvent(QMouseEvent *event);
    void dropEvent(QDropEvent* event);
    void animation(paintWidget* circle,QRect coordinateStart,QRect coordinateStop );
    static int wID;
    int getX();
    int getY();

private:
    QPainter painter;
    circle* m_circle;
    QPoint parentPoint;

    int x,y;


public slots:
};

#endif // PAINTWIDGET_H
