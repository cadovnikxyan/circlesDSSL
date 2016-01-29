#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QDebug>
#include <QVBoxLayout>

#include "paintwidget.h"
#include "circle.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QObject::connect(this,SIGNAL(on_start_clicked_s()),this,SLOT(on_start_clicked()));
    ui->setupUi(this);
    emit on_start_clicked_s();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print(){

}

void MainWindow::paintEvent(QPaintEvent *event){

}

void MainWindow::on_start_clicked()
{

    paintWidget* m_paintwidget= new paintWidget();
    this->setCentralWidget(m_paintwidget);



}
