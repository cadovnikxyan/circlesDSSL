#ifndef SETTLEMENTS_H
#define SETTLEMENTS_H
#include <QObject>
#include <QRunnable>
#include <vector>
#include <cmath>
#include <map>
#include "circle.h"




class settlements :public QObject, public QRunnable
{

Q_OBJECT

public:
     settlements(circle* s);
     ~settlements();
     void run();
     void setArrayCircles(std::vector<circle* >* circles_);

signals:
     void finish(circle* result,circle* target);
         	        
private:
        void vector();
        std::vector<double> vec_m;
        std::vector<circle* >* circles;
        std::map<double,circle*> vec_map;
        circle* currentCircle;

};

#endif // SETTLEMENTS_H
