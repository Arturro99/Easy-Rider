#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "traffic.h"
#include "road.h"
#include "trafficrules.h"
#include "drivethread.h"
#include "car.h"
#include "roadrepository.h"

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
    MainWindow(VehiclePointer vehicle, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    VehiclePointer car;
    RoadRepository roadRepository;
    Traffic traffic;
    TrafficRules trafficRules;
    QSharedPointer<QPixmap> background;
    void assignStreets();
    void paintEvent(QPaintEvent *event);
    void paintCars(QPaintEvent *event);
    QPixmap *getBackground() const;
    void setBackground(QPixmap *newPixmap);


signals:

private slots:
    void on_horizontalSlider_valueChanged(int value);
};
#endif // MAINWINDOW_H
