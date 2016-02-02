#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThreadPool>
#include <QHash>
#include <vector>
#include <QTime>

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
    void widgetCircle(QMouseEvent* event);


signals:

    void circlePosChange(int i);

public slots:

    void threadPoll(circle* c,circle* target);
    void timer_overflow();

private:

    QTimer* timer;
    std::vector<circle*> circles;
    Ui::MainWindow *ui;
    QHash<int,paintWidget*> paintHash;

};

#endif // MAINWINDOW_H
