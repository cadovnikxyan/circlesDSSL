#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QBoxLayout>
#include <QTimer>
#include <vector>

#include "paintwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mouseDoubleClickEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent* key);
    void dropEvent(QDropEvent* event);
    void animation();
    void widgetCircle(QMouseEvent* event);
    void animationStartStop();

signals:
    void circlePosChange(int i);

public slots:
    void timer_overflow();

private:
    QTimer* timer;
    QList<paintWidget *> paintW_circles;
    std::vector<circle*> circles;
    QList<QPropertyAnimation*> animations;
    Ui::MainWindow *ui;

    bool mouseflag;
};

#endif // MAINWINDOW_H
