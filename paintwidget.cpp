#include "paintwidget.h"
#include <QDrag>
#include <QMimeData>

int paintWidget::wID=0;
paintWidget::paintWidget(QWidget *parent) : QWidget(parent),x(0),y(0)
{
    wID++;
    setMouseTracking(true);
    setMaximumSize(200,200);
    setObjectName("circle "+QString::number(wID));
    setAcceptDrops(true);
    parentPoint=parent->pos();
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
     x=qrand()%764;
     y=qrand()%495;


}

void paintWidget::paintEvent(QPaintEvent *event){

    painter.begin(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(0,0,30,30);
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

}
void paintWidget::mouseMoveEvent(QMouseEvent *event){


}

void paintWidget::mousePressEvent(QMouseEvent *event){

    if(event->button()==Qt::RightButton){
       this->hide();
    }
    if(event->button()==Qt::LeftButton){
        QPixmap pix(QWidget::grab(QRect(0,0,30,30)));
        QDrag *drag = new QDrag(this);
        QMimeData *mime = new QMimeData;
        drag->setMimeData(mime);
        drag->setPixmap(pix);
        Qt::DropAction dropAction = drag->start(Qt::CopyAction | Qt::MoveAction);

    }
}

void paintWidget::dropEvent(QDropEvent *event)
{
    qDebug()<<event->source()->objectName();
}

void paintWidget::animation(paintWidget *circle, QRect coordinateStart, QRect coordinateStop)
{
    QPropertyAnimation*  animation= new QPropertyAnimation(this,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(coordinateStart);
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->setEndValue(coordinateStop);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}

int paintWidget::getX()
{
    return this->x;
}

int paintWidget::getY()
{
    return this->y;
}


