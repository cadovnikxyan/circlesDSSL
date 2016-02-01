#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QDebug>
#include <QVBoxLayout>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),mouseflag(true){

    ui->setupUi(this);
    timer=new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), this, SLOT(timer_overflow()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    if(event->button()==Qt::LeftButton){
         mouseflag=true;
         animation();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::RightButton){

        widgetCircle(event);

    }else if(event->button()==Qt::LeftButton){

            animationStartStop();
            timer->start(100);
        }
    }


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

        paint->setCircle(m_circle);
        paint->move(x,y);
        paint->show();

        circles.push_back(m_circle);
        paintW_circles.append(paint);

    }else if(key->key()==Qt::Key_Control){
        for(int i=0;i<circles.size();i++){
            qDebug()<<QString::number(circles.at(i)->getX())+"  "+QString::number(circles.at(i)->getY());
        }
    }
}

void MainWindow::dropEvent(QDropEvent *event){
    qDebug()<<event->source()->objectName();

}

void MainWindow::animation(){

    for(int i=0;i<paintW_circles.size();i++){
        int x=qrand()%500;
        int y=qrand()%300;
        animations.append(paintW_circles.at(i)->
                animation(paintW_circles.at(i), QRect(x, y, 30, 30)
                          ,QRect(paintW_circles.at(i)->getX(), paintW_circles.at(i)->getY(), 30, 30)
                          ,30000));
    }

}

void MainWindow::widgetCircle(QMouseEvent* event){

    paintWidget* paint= new paintWidget(this);
    circle* m_circle = new circle();

    m_circle->setX(event->pos().x());
    m_circle->setY(event->pos().y());

    paint->setCircle(m_circle);
    paint->move(event->pos().x(),event->pos().y());
    paint->show();

    circles.push_back(m_circle);
    paintW_circles.append(paint);

}

void MainWindow::animationStartStop(){

    if(mouseflag){

        for(int i=0;i<animations.size();i++){
            animations.at(i)->pause();
            mouseflag=false;
            timer->stop();
            }
    }else{

        for(int i=0;i<animations.size();i++){
            animations.at(i)->resume();
            mouseflag=true;
            timer->start(100);
            }
    }
}



void MainWindow::timer_overflow(){

    for(int i=0;i<paintW_circles.size();i++){
        circles.at(i)->setX(paintW_circles.at(i)->pos().x());
        circles.at(i)->setY(paintW_circles.at(i)->pos().y());
   }
    qDebug()<<QThread::currentThreadId();
    settlements* thread= new settlements("thread");
    thread->setArrayCircles(&circles);
    thread->run();
}



