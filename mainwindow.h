#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "traffic.h"
#include "road.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
    Traffic traffic;
    Road *horizontalRoads;
    Road *verticalRoads;
    void assignStreets();
//    void resizeEvent(QResizeEvent *evt); // declare The members

signals:

private slots:
    void on_horizontalSlider_valueChanged(int value);
};
#endif // MAINWINDOW_H
