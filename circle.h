#ifndef CIRCLE_H
#define CIRCLE_H

#include <QPaintEvent>
#include <QPainter>
#include <QMainWindow>

class circle : public QPainter{

public:
    circle(QWidget* widget,int radius_);
    ~circle();
    void paintEvent(QPaintEvent *event);
    void setX(int X_);
    void setY(int Y_);
    int getX();
    int getY();

    QPaintEngine* paintEngine();

    static int countCircle;
    int X,Y;

private:

    QPainter painter;
    int radius,speed;
};

#endif // CIRCLE_H
