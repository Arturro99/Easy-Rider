#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "traffic.h"
#include "road.h"
#include "trafficrules.h"

#include <QMainWindow>
#include <QSharedPointer>
#include <QVector>

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
    void paintCars(QPaintEvent *event);
    void loadVehicles();

    QPixmap *getBackground() const;
    void setBackground(QPixmap *newPixmap);

    void rotateVehicle(Direction direction, VehiclePointer vehicle);


private:
    Ui::MainWindow *ui;
    Traffic traffic;
    TrafficRules trafficRules;
    QVector<RoadPointer> horizontalRoads;
    QVector<RoadPointer> verticalRoads;
    QSharedPointer<QPixmap> background;
    uchar* data;
    void delay();
    void assignStreets();
//    void resizeEvent(QResizeEvent *evt); // declare The members

    VehiclePointer car;

signals:

private slots:
    void on_horizontalSlider_valueChanged(int value);
};
#endif // MAINWINDOW_H
