#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include "circle.h"
#include <QDebug>

class paintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit paintWidget(QWidget *parent = 0);
    void  paintEvent(QPaintEvent *event);
    void setCircle(circle *_cercle);
    void reXY(int x, int y);

    void mouseReleaseEvent ( QMouseEvent * event );
    void mouseMoveEvent ( QMouseEvent * event );
    void mousePressEvent(QMouseEvent *event);

    void dragEnterEvent(QDragEnterEvent* event);
    void dragMoveEvent(QDragMoveEvent* event);
    void dragLeaveEvent(QDragLeaveEvent* event);
    void dropEvent(QDropEvent* event);
    static int wID;
    bool eventFilter(QObject *obj, QEvent *e);
    int i=0;

private:
    QPainter painter;
    circle* m_circle;
    int x,y;


public slots:
};

#endif // PAINTWIDGET_H
