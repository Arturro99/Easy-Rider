#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "traffic.h"
#include "road.h"
#include "trafficrules.h"
#include "drivethread.h"
#include "car.h"
#include "roadrepository.h"
#include "vehiclerepository.h"
#include "threadmanager.h"

#include <QMainWindow>
#include <QSharedPointer>
#include <QVector>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(RoadRepositoryPointer &roadRepository, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    RoadRepositoryPointer roadRepository;
    Traffic traffic;
    TrafficRules trafficRules;
    QSharedPointer<QPixmap> background;
    QVector<QPoint> qPoints;
    QVector<QImage> qImages;
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
