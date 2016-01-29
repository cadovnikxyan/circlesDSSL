#include "circle.h"
#include <QDebug>
circle::circle(QWidget* widget, int radius_):X(0),Y(0)
{
    painter.begin(widget);
    this->radius=radius_;
    circle::countCircle++;
}
 int circle::countCircle=0;
circle::~circle(){
 circle::countCircle--;
}
QPaintEngine* circle::paintEngine(){

}

void circle::paintEvent(QPaintEvent *event){

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(100,50,150,150);
    painter.end();

}


void circle::setX(int X_){
    this->X=X_;
}

void circle::setY(int Y_){
    this->Y=Y_;
}

int circle::getX(){
    return this->X;
}

int circle::getY(){
    return this->Y;
}

