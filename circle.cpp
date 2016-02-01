#include "circle.h"


circle::circle():X(0),Y(0){

    countCircle++;
}

int circle::countCircle=0;

circle::~circle(){
    countCircle--;
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

