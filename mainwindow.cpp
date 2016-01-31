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
    paintWidget* paint= new paintWidget(this);
    circles.append(paint);
    circles.front()->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){


    for(int i=0;i<circles.size();i++){
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));


        int x=qrand()%764;
        int y=qrand()%495;
        circles.at(i)->animation(circles.at(i), QRect(x, y, 100, 30), QRect(circles.at(i)->getX(), circles.at(i)->getY(), 100, 30));


    }



}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton){

        paintWidget* paint= new paintWidget(this);
        paint->move(event->pos().x(),event->pos().y());
        paint->show();
        circles.append(paint);
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

}

void MainWindow::keyPressEvent(QKeyEvent *key)
{
    paintWidget* paint= new paintWidget(this);
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));


    int x=qrand()%764;
    int y=qrand()%495;
    paint->move(x,y);
    paint->show();
    circles.append(paint);


}

void MainWindow::dropEvent(QDropEvent *event)
{
    qDebug()<<event->source()->objectName();

}


void MainWindow::cirlce_draw()
{


}
