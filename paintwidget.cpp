#include "paintwidget.h"
#include <QDrag>
#include <QMimeData>

int paintWidget::wID=0;
paintWidget::paintWidget(QWidget *parent) : QWidget(parent),x(100),y(100)
{
    wID++;
    setMouseTracking(true);
    setMinimumSize(x,y);
    setAcceptDrops(true);
    setObjectName(QString::number(wID));
    this->installEventFilter(this);

}

void paintWidget::paintEvent(QPaintEvent *event){


    painter.begin(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(x,y,100,100);
    painter.end();
}


void paintWidget::setCircle(circle* _cercle){

    this->m_circle=_cercle;
}

void paintWidget::reXY(int x, int y){
    this->x=x;
    this->y=y;
    repaint();
}

void paintWidget::mouseReleaseEvent(QMouseEvent *event){
    if(event->MouseButtonPress){
      //  qDebug()<<"circle push!"<<event->pos();
        reXY(event->pos().x(),event->pos().y());

    }
}
void paintWidget::mouseMoveEvent(QMouseEvent *event){
   //qDebug()<<event->pos();
}

void paintWidget::mousePressEvent(QMouseEvent *event){

//    QDrag* drag= new QDrag(this);
//    QMimeData *mimeData = new QMimeData();


//           drag->setMimeData(mimeData);

//     Qt::DropAction dropAction = drag->exec();

}

void paintWidget::dragEnterEvent(QDragEnterEvent *event)
{



}

void paintWidget::dragMoveEvent(QDragMoveEvent *event)
{
  reXY(event->pos().x(),event->pos().y());
  repaint();
}

void paintWidget::dropEvent(QDropEvent *event)
{

}

bool paintWidget::eventFilter(QObject *obj, QEvent *e)
{

    if(e->MouseButtonPress){
        i++;
        qDebug()<<QString::number(wID)+ QString::number(i)+obj->objectName();

    }

}
void paintWidget::dragLeaveEvent(QDragLeaveEvent *event)
{

}
