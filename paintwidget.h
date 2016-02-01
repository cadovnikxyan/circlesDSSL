#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QPropertyAnimation>
#include <QTime>

#include "circle.h"

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
    bool eventFilter(QObject *obj, QEvent *event);

    void dropEvent(QDropEvent* event);
    QPropertyAnimation* animation(paintWidget* circle, QRect coordinateStart, QRect coordinateStop , int speed);
    int getX();
    int getY();
    QPropertyAnimation*  animation_;

     int getWID() const;
     void setWID(int value);

private:
    QPainter painter;
    circle* m_circle;
    QPoint parentPoint;

    int x,y,wID;
    static int allID;


public slots:
};

#endif // PAINTWIDGET_H
