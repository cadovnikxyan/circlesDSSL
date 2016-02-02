#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);
    timer=new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), this, SLOT(timer_overflow()));

}

MainWindow::~MainWindow(){
    delete ui;
}

//запуск анимации шариков
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    if(event->button()==Qt::LeftButton){


         timer->start(500);
    }
}

//добавление нового шарика в пустое место
//остановка - продолжение анимации шариков
void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::RightButton){

        widgetCircle(event);

    }else if(event->button()==Qt::LeftButton){
            timer->start(500);
        }
    }

//добавление новых шариков в случайную позицию
void MainWindow::keyPressEvent(QKeyEvent *key){

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    if(key->key()==Qt::Key_Space){

        paintWidget* paint= new paintWidget(this);
        circle* m_circle = new circle();

        int x=qrand()%764;
        int y=qrand()%495;

        m_circle->setX(x);
        m_circle->setY(y);
        m_circle->setID(paint->getWID());

        paint->setCircle(m_circle);
        paint->move(x,y);
        paint->show();

        circles.push_back(m_circle);
        paintHash.insert(paint->getWID(),paint);

    }
}

void MainWindow::dropEvent(QDropEvent *event){

}


void MainWindow::widgetCircle(QMouseEvent* event){

    paintWidget* paint= new paintWidget(this);
    circle* m_circle = new circle();

    m_circle->setX(event->pos().x());
    m_circle->setY(event->pos().y());
    m_circle->setID(paint->getWID());

    paint->setCircle(m_circle);
    paint->move(event->pos().x(),event->pos().y());
    paint->show();

    circles.push_back(m_circle);
    paintHash.insert(paint->getWID(),paint);

}


//слот завершения потока рассчета ближайшего шарика и запуск анимации движения к нему
void MainWindow::threadPoll(circle* c,circle* target){

      paintWidget* paint = paintHash.find(c->getID()).value();
      paint->animation(QRect(c->getX(), c->getY(), 30, 30),QRect(target->getX(), target->getY(), 30, 30),3000);
}

//получение координат шариков при анимации
void MainWindow::timer_overflow(){

    int i=0;
    QHash<int,paintWidget*>::iterator it=paintHash.begin();
    for(;it!=paintHash.end();it++){
        paintWidget* paint=it.value();
        if(i==(int)circles.size()){
            i=0;
        }
        circles.at(i)->setX(paint->pos().x());
        circles.at(i)->setY(paint->pos().y());

        settlements* s= new settlements(circles.at(i));

        QObject::connect(s,SIGNAL(finish(circle*,circle*)),this,SLOT(threadPoll(circle*,circle*)));
        s->setArrayCircles(&circles);

        QThreadPool::globalInstance()->start(s);
        i++;
   }
}




