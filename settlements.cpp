#include "settlements.h"

//идея рассчетов такая :
//поток будет получать на вход текущий экземпляр класса с координатами шарика и считать ближайщий к нему из вектора со всеми 
//координатами, определять массив координат и передавать их в слот завершения потока где будет перезапускаться анимация
settlements::settlements(QString s):name(s)
{

}

void settlements::run(){
//    qDebug()<<QThread::currentThreadId();
//    for(int i=0;i<circles->size();i++){
//         qDebug()<<circles->at(i)->getX()<<circles->at(i)->getY();
//    }
    qDebug()<<QThread::currentThreadId();
    qDebug()<<name+QString::number(i++);
    exec();
}

void settlements::setArrayCircles(std::vector<circle*> *circles_){
    this->circles=circles_;
}


