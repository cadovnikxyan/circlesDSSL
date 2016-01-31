#include "circle.h"
#include <QDebug>
circle::circle( int radius_):X(0),Y(0)
{

    this->radius=radius_;
    circle::countCircle++;
}
 int circle::countCircle=0;
circle::~circle(){
 circle::countCircle--;
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

