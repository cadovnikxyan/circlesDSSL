#ifndef SETTLEMENTS_H
#define SETTLEMENTS_H
#include <QThread>
#include <QString>
#include <QDebug>
#include <vector>

#include "circle.h"

class settlements : public QThread
{
public:
    explicit settlements(QString s);
        void run();
        void setArrayCircles(std::vector<circle* >* circles_);
private:
        int i=0;
        std::vector<circle* >* circles;
        QString name;
};

#endif // SETTLEMENTS_H
