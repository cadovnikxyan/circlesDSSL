#include "paintwidget.h"

paintWidget::paintWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
}

void paintWidget::paintEvent(QPaintEvent *event){

    painter.begin(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(100,50,150,150);
    painter.end();
}
