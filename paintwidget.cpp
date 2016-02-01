#include "paintwidget.h"
#include <QDrag>
#include <QMimeData>

int paintWidget::allID=0;
paintWidget::paintWidget(QWidget *parent) : QWidget(parent),x(0),y(0){
    wID=allID++;
    setMouseTracking(true);
    setMaximumSize(200,200);
    setObjectName("circle "+QString::number(wID));
    setAcceptDrops(true);
    parentPoint=parent->pos();

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));



}

paintWidget::~paintWidget(){
   allID--;

}
//отрисовка шарика
void paintWidget::paintEvent(QPaintEvent *event){

    painter.begin(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(0,0,30,30);
    painter.end();
}

//установка класса хранителя координат шарика
void paintWidget::setCircle(circle* _circle){

    this->m_circle=_circle;
    x=_circle->getX();
    y=_circle->getY();
}



void paintWidget::mouseReleaseEvent(QMouseEvent *event){

}
void paintWidget::mouseMoveEvent(QMouseEvent *event){


}
//лопание шарика по нажатию правой кнопки мыши
//перетаскивание шарика левой кнопкой мыши (dropEvent не определен)
void paintWidget::mousePressEvent(QMouseEvent *event){

    if(event->button()==Qt::RightButton){
       this->hide();


    }
    if(event->button()==Qt::LeftButton){
        QPixmap pix(QWidget::grab(QRect(0,0,28,28)));
        QDrag *drag = new QDrag(this);
        QMimeData *mime = new QMimeData;
        drag->setMimeData(mime);
        drag->setPixmap(pix);
        Qt::DropAction dropAction = drag->start(Qt::CopyAction | Qt::MoveAction);

    }
}

void paintWidget::mouseDoubleClickEvent(QMouseEvent *event){
    qDebug()<<event->pos();
}

bool paintWidget::eventFilter(QObject *obj, QEvent *event){

}

void paintWidget::dropEvent(QDropEvent *event){
    qDebug()<<event->source()->objectName();
}
//функция определения анимации шарика
//QEasingCurve::OutExpo практически соответсвует заданной функции силы притяжения 

QPropertyAnimation* paintWidget::animation(paintWidget *circle, QRect coordinateStart, QRect coordinateStop, int speed){
    animation_= new QPropertyAnimation(this,"geometry");
    animation_->setDuration(speed);
    animation_->setStartValue(coordinateStart);
    animation_->setEasingCurve(QEasingCurve::OutExpo);
    animation_->setEndValue(coordinateStop);
    animation_->start(QAbstractAnimation::DeleteWhenStopped);

    return animation_;
}

int paintWidget::getX(){
    return this->x;
}

int paintWidget::getY(){
    return this->y;
}

int paintWidget::getWID() const
{
    return wID;
}

void paintWidget::setWID(int value)
{
    wID = value;
}


