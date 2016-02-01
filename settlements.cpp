#include "settlements.h"

<<<<<<< HEAD

settlements::settlements(circle* s){

    this->currentCircle=s;

}

settlements::~settlements(){
=======
//идея рассчетов такая :
//поток будет получать на вход текущий экземпляр класса с координатами шарика и считать ближайщий к нему из вектора со всеми 
//координатами, определять массив координат и передавать их в слот завершения потока где будет перезапускаться анимация
settlements::settlements(QString s):name(s)
{
>>>>>>> 068b4f1443bc9f52d42403e8e2275ab0fc2551eb

}

void settlements::run(){

    vector();
//    for(int i=0;i<(int)vec_m.size();i++){
//        if(vec_m.at(i)!=0){
            qDebug()<<QString::number(vec_map.find(vec_m[1])->second->getID())+": "+QString::number(vec_map.find(vec_m[1])->first);
//        }
//    }

    emit finish(currentCircle);
}


void settlements::setArrayCircles(std::vector<circle*> *circles_){

    this->circles=circles_;

}

void settlements::vector(){

    double vec=0;
    for(int i=0;i<(int)circles->size();i++){
        circle* c = circles->at(i);
        vec=sqrt(pow(c->getX()-currentCircle->getX(),2)+pow(c->getY()-currentCircle->getY(),2));
        vec_m.push_back(vec);
        vec_map.insert(std::pair<double,circle*>(vec,c));
    }
    std::sort(vec_m.begin(),vec_m.end());

}





