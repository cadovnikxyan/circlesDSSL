#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QDebug>
#include <QVBoxLayout>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    paintWidget* paint= new paintWidget(this);
//    paint->show();
//    circles.append(paint);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));


    if(flag){
        for(int i=0;i<paintW_circles.size();i++){
            int x=qrand()%500;
            int y=qrand()%300;
            animations.append(paintW_circles.at(i)->
                    animation(paintW_circles.at(i), QRect(x, y, 30, 30)
                              ,QRect(paintW_circles.at(i)->getX(), paintW_circles.at(i)->getY(), 30, 30)
                              ,30000));
            }
        }
    }

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton){
        paintWidget* paint= new paintWidget(this);
        circle* m_circle = new circle();

        m_circle->setX(event->pos().x());
        m_circle->setY(event->pos().y());
        circles.append(m_circle);
        paint->setCircle(m_circle);
        paint->move(event->pos().x(),event->pos().y());
        paint->show();

        paintW_circles.append(paint);

    }else if(event->button()==Qt::LeftButton){
        if(flag){
            for(int i=0;i<animations.size();i++){
                animations.at(i)->pause();
                flag=false;
            }
        }else{
            for(int i=0;i<animations.size();i++){
                animations.at(i)->resume();
                flag=true;
            }
            }
        }
    }


void MainWindow::animationCircle(paintWidget *circle, QRect coordinateStart, QRect coordinateStop)
{
    QPropertyAnimation*  animation= new QPropertyAnimation(circle,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(coordinateStart);
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->setEndValue(coordinateStop);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    animation->setDuration(100);

}

void MainWindow::keyPressEvent(QKeyEvent *key)
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    if(key->key()==Qt::Key_Space){

        paintWidget* paint= new paintWidget(this);
        int x=qrand()%764;
        int y=qrand()%495;
        circle* m_circle = new circle();
        m_circle->setX(x);
        m_circle->setY(y);
        paint->setCircle(m_circle);
        paint->move(x,y);
        paint->show();
        circles.append(m_circle);
        paintW_circles.append(paint);
    }else if(key->key()==Qt::Key_Control){
        for(int i=0;i<circles.size();i++){
            qDebug()<<QString::number(circles.at(i)->getX())+"  "+QString::number(circles.at(i)->getY());
        }
    }


}

void MainWindow::dropEvent(QDropEvent *event)
{
    qDebug()<<event->source()->objectName();

}


void MainWindow::cirlce_draw()
{


}
