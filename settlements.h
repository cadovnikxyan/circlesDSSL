#ifndef SETTLEMENTS_H
#define SETTLEMENTS_H
#include <QThread>
#include <QString>
#include <QDebug>
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
     void finish(circle* result);
         	        
private:
        void vector();
        std::vector<double> vec_m;
        std::vector<circle* >* circles;
        std::map<double,circle*> vec_map;
        std::map<double,circle*>::iterator it;
        circle* currentCircle;

};

#endif // SETTLEMENTS_H
