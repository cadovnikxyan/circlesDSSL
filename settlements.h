#ifndef SETTLEMENTS_H
#define SETTLEMENTS_H
#include <QThread>
#include <QString>

#include "circle.h"

class settlements : public QThread
{
public:

Q_OBJECT
    explicit settlements(QString* s);
        void run();
private:
        QString* name;
};

#endif // SETTLEMENTS_H
