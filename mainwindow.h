#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "paintwidget.h"
#include <QBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void cirlce_draw();
    void mouseDoubleClickEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void animationCircle(paintWidget* circle,QRect coordinateStart,QRect coordinateStop );
    void keyPressEvent(QKeyEvent* key);
    void dropEvent(QDropEvent* event);

private slots:

 signals:


private:
    paintWidget* m_paintwidget;
    paintWidget* m_paintwidget1;
    QList<paintWidget *> paintW_circles;
    QList<circle*> circles;
    QList<QPropertyAnimation*> animations;
    Ui::MainWindow *ui;
  //  QPropertyAnimation* animation;
    bool flag=true;
};

#endif // MAINWINDOW_H
