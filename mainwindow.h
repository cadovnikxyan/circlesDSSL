#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
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
    void  paintEvent(QPaintEvent *event);


private slots:
    void on_start_clicked();

 signals:
    void on_start_clicked_s();

private:
    QPainter painter;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
