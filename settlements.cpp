#include "settlements.h"



settlements::settlements(circle* s){

    this->currentCircle=s;

}

settlements::~settlements(){

}


//поток получает на вход текущий экземпляр класса с координатами шарика и находит ближайщий к нему из вектора со всеми
//координатами и передает его координаты в слот завершения потока где будет перезапускаться анимация


void settlements::run(){

    double min=vector();
    emit finish(currentCircle,vec_map.find(min)->second);
}


void settlements::setArrayCircles(std::vector<circle*> *circles_){

    this->circles=circles_;

}

double settlements::vector(){
    double vec=0;
    try{
        circles->size();
    }catch(...){
        qDebug()<<"123";
    }

    for(int i=0;i<(int)circles->size();i++){
        circle* c = circles->at(i);
        vec=sqrt(pow(c->getX()-currentCircle->getX(),2)+pow(c->getY()-currentCircle->getY(),2));
        if(vec!=0){
            vec_m.push_back(vec);
            vec_map.insert(std::pair<double,circle*>(vec,c));
        }
    }    
    std::sort(vec_m.begin(),vec_m.end());
    return vec_m.at(0);
}

double settlements::min_elem(std::vector<double> *a)
{
    double min = a->at(0);
    for (int i = 0 ; i < (int)a->size() ; i++)
     if (a->at(i)<min) min=a->at(i);
    return min;
}



