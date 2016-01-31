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



}

paintWidget::~paintWidget()
{
   wID--;

}

void paintWidget::paintEvent(QPaintEvent *event){

    painter.begin(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(0,0,30,30);
    painter.end();
}


void paintWidget::setCircle(circle* _circle){

    this->m_circle=_circle;
    x=_circle->getX();
    y=_circle->getY();
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

void paintWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<event->pos();
}

void paintWidget::dropEvent(QDropEvent *event)
{
    qDebug()<<event->source()->objectName();
}

QPropertyAnimation* paintWidget::animation(paintWidget *circle, QRect coordinateStart, QRect coordinateStop, int speed)
{
    animation_= new QPropertyAnimation(this,"geometry");
    animation_->setDuration(speed);
    animation_->setStartValue(coordinateStart);
    animation_->setEasingCurve(QEasingCurve::OutExpo);
    animation_->setEndValue(coordinateStop);
    animation_->start(QAbstractAnimation::DeleteWhenStopped);
    return animation_;
}

int paintWidget::getX()
{
    return this->x;
}

int paintWidget::getY()
{
    return this->y;
}


