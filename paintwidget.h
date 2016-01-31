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
    ~paintWidget();
    void  paintEvent(QPaintEvent *event);
    void setCircle(circle* _circle);

    void mouseReleaseEvent ( QMouseEvent * event );
    void mouseMoveEvent ( QMouseEvent * event );
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent* event);

    void dropEvent(QDropEvent* event);
    QPropertyAnimation* animation(paintWidget* circle, QRect coordinateStart, QRect coordinateStop , int speed);
    int getX();
    int getY();
    QPropertyAnimation*  animation_;

private:
    QPainter painter;
    circle* m_circle;
    QPoint parentPoint;

    int x,y;
    static int wID;


public slots:
};

#endif // PAINTWIDGET_H
