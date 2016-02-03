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

int circle::getX()const{
    return this->X;
}

int circle::getY()const{
    return this->Y;
}

int circle::getID() const{
    return ID;
}

void circle::setID(int value){
    ID = value;
}

void circle::del(){
    delete this;
}

