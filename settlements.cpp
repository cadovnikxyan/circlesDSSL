#include "settlements.h"



settlements::settlements(circle* s){

    this->currentCircle=s;

}

settlements::~settlements(){
}


//поток получает на вход текущий экземпляр класса с координатами шарика и находит ближайщий к нему из вектора со всеми
//координатами и передает его координаты в слот завершения потока где будет перезапускаться анимация


void settlements::run(){

    vector();
    emit finish(currentCircle,vec_map.find(vec_m[1])->second);
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





