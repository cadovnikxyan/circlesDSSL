#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QBoxLayout>
#include <QTimer>
#include <QThreadPool>
#include <QHash>
#include <vector>

#include "settlements.h"
#include "paintwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QThread thr;

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

    void threadPoll(circle* c);
    void timer_overflow();

private:
    QTimer* timer;
    QList<paintWidget *> paintW_circles;
    std::vector<circle*> circles;
    QList<QPropertyAnimation*> animations;
    Ui::MainWindow *ui;
    QHash<int,paintWidget*> paintHash;
    bool mouseflag;
};

#endif // MAINWINDOW_H
