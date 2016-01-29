#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
class paintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit paintWidget(QWidget *parent = 0);
    void  paintEvent(QPaintEvent *event);
private:
    QPainter painter;
signals:

public slots:
};

#endif // PAINTWIDGET_H
