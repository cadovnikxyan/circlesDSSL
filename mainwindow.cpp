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

    cirlce_draw();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print(){

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){
    for(int i=100, j=0;i<200,j<300;i++,j++){
        m_paintwidget->reXY(i,i);
        m_paintwidget1->reXY(j,j);
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
//    int i=0;
//    if(obj->objectName()=="2"&&e->MouseButtonPress){
//        i++;
//        qDebug()<<obj->objectName()+ QString::number(i);
//    }

}



void MainWindow::cirlce_draw()
{
    circle* _circle= new circle(10);
     m_paintwidget= new paintWidget();
     m_paintwidget1= new paintWidget();
    m_paintwidget1->reXY(150,150);

//    QBoxLayout* layout= new QBoxLayout();

//   layout->addWidget(m_paintwidget);
//   layout->addWidget(m_paintwidget1);
//   ui->centralWidget->layout()->addWidget(m_paintwidget);
//   ui->centralWidget->layout()->addWidget(m_paintwidget1);
//   ui->centralWidget->layout()->addChildWidget();
   //    this->layout()->addItem(layout);
//    this->layout()->installEventFilter(m_paintwidget);
//    this->layout()->installEventFilter(m_paintwidget1);
    qDebug()<<m_paintwidget->objectName();
    qDebug()<<m_paintwidget1->objectName();

}
