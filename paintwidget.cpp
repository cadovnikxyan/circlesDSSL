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

//    QTime midnight(0,0,0);
//    qsrand(midnight.secsTo(QTime::currentTime()));

}

paintWidget::~paintWidget(){
   allID--;

}
//отрисовка шарика
void paintWidget::paintEvent(QPaintEvent *){

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


void paintWidget::dropEvent(QDropEvent *event){

}


//функция определения анимации шарика
//QEasingCurve::OutExpo практически соответсвует заданной функции силы притяжения 
void paintWidget::animation( QRect coordinateStart, QRect coordinateStop, int speed){
   QPropertyAnimation* animation_= new QPropertyAnimation(this,"geometry");
    animation_->setDuration(speed);
    animation_->setStartValue(coordinateStart);
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


