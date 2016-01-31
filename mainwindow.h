#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "paintwidget.h"
#include "circle.h"
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
    void print();
    void cirlce_draw();
    void mouseDoubleClickEvent(QMouseEvent* event);
    bool eventFilter(QObject *obj, QEvent *e);

private slots:

 signals:


private:
    QPainter painter;
    paintWidget* m_paintwidget;
    paintWidget* m_paintwidget1;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
