#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QPropertyAnimation>

#include "circle.h"

class paintWidget : public QWidget
{
    Q_OBJECT

public:
    explicit paintWidget(QWidget *parent = 0);
    ~paintWidget();

    void  paintEvent(QPaintEvent *);
    void setCircle(circle* _circle);

    void mouseMoveEvent ( QMouseEvent * event );
    void mousePressEvent(QMouseEvent *event);
    void dropEvent(QDropEvent* event);

    void animation(QRect coordinateStart, QRect coordinateStop , int speed);
    int getX() const;
    int getY() const;

    int getWID() const;
    void setWID(int value);

private:
    QPainter painter;
    circle* m_circle;

    int x,y,wID;
    static int allID;


public slots:
};

#endif // PAINTWIDGET_H
