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
    QRegion r(0,0,100,100, QRegion::Ellipse);
    this->setMask(r);

}

paintWidget::~paintWidget(){
   allID--;


}
//отрисовка шарика
void paintWidget::paintEvent(QPaintEvent *){

    painter.begin(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(0,0,100,100);
    painter.end();
}

//установка класса хранителя координат шарика
void paintWidget::setCircle(circle* _circle){

    this->m_circle=_circle;
    x=_circle->getX();
    y=_circle->getY();
}


void paintWidget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton)
        {
            this->move(mapToParent(event->pos() - offset));
            dragFlag=true;
        }

}

//лопание шарика по нажатию правой кнопки мыши
//перетаскивание шарика левой кнопкой мыши (dropEvent не определен)
void paintWidget::mousePressEvent(QMouseEvent *event){

    if(event->button()==Qt::RightButton){

        this->hide();
        m_circle->del();
        emit destroy(&wID);

    }
    if(event->button()==Qt::LeftButton){
          offset = event->pos();
    }
}

void paintWidget::mouseReleaseEvent(QMouseEvent *event){

    if(event->button()==Qt::LeftButton){
         this->move(mapToParent(event->pos()));
         dragFlag=false;
    }

}


qreal easingCurve(qreal progress){

    qreal progress_=progress*1000.0;
    qreal result=(1/progress_)-(1/(progress_*progress_));
    return result;
}

//функция определения анимации шарика
//QEasingCurve::OutBack практически соответсвует заданной функции силы притяжения

void paintWidget::animation( QRect coordinateStart, QRect coordinateStop, int speed){

    QPropertyAnimation* animation_= new QPropertyAnimation(this,"geometry");
    animation_->setDuration(speed);
    animation_->setStartValue(coordinateStart);

    QEasingCurve curve;
    QEasingCurve::EasingFunction f=&easingCurve;
    curve.setCustomType(f);

    animation_->setEasingCurve(QEasingCurve::OutBack);
    animation_->setEndValue(coordinateStop);
    animation_->start(QAbstractAnimation::DeleteWhenStopped);
}

int paintWidget::getX() const{
    return this->x;
}

int paintWidget::getY() const{
    return this->y;
}

int paintWidget::getWID() const{
    return wID;
}

void paintWidget::setWID(int value){
    wID = value;
}




