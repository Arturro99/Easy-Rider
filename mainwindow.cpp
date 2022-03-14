#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "car.h"

#include <iostream>
#include <QPainter>
#include <QPoint>
#include <QFrame>
#include <QRegularExpression>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    assignStreets();

    car = VehiclePointer(new Car(RIGHT));
    car->setCurrentCoordinates(this->horizontalRoads.at(0)->getStartCoordinates());

    ui->horizontalSlider->setValue(50);
    traffic.generateTraffic(car);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::assignStreets()
{
    QRegularExpression verticalLinesExpression("^.+ver.*$");
    QRegularExpression horizontalLinesExpression("^.+hor.*$");
    QRegularExpression verticalDownLinesExpression("^.*verDown$");
    QRegularExpression verticalUpLinesExpression("^.*verUp$");
    QRegularExpression horizontalLeftLinesExpression("^.*horLeft$");
    QRegularExpression horizontalRightLinesExpression("^.*horRight$");

    QList<QFrame*> horizontalLines = ui->centralwidget->findChildren<QFrame*>(horizontalLinesExpression);
    QList<QFrame*> verticalLines = ui->centralwidget->findChildren<QFrame*>(verticalLinesExpression);
    QList<QFrame*> horizontalLeftLines = ui->centralwidget->findChildren<QFrame*>(horizontalLeftLinesExpression);
    QList<QFrame*> horizontalRightLines = ui->centralwidget->findChildren<QFrame*>(horizontalRightLinesExpression);
    QList<QFrame*> verticalUpLines = ui->centralwidget->findChildren<QFrame*>(verticalUpLinesExpression);
    QList<QFrame*> verticalDownLines = ui->centralwidget->findChildren<QFrame*>(verticalDownLinesExpression);


    //Initiate vertical roads both right- and left-sided
    //Also add spawning/ending roads if requirements met
    for (int i = 0; i < verticalLines.length(); i++) {
        QFrame *line = verticalLines.at(i);
        int *startCoordinates = new int[]{line->x(), line->y()};
        int *endCoordinates = new int[]{line->x(), line->y() + line->height()};
        verticalRoads.append(RoadPointer(new Road(startCoordinates, endCoordinates)));

        if (verticalUpLines.contains(line)) {
            trafficRules.addVerticalUpRoad(RoadPointer(new Road(startCoordinates, endCoordinates)));
        } else if (verticalDownLines.contains(line)) {
            trafficRules.addVerticalDownRoad(RoadPointer(new Road(startCoordinates, endCoordinates)));
        }


        if ((startCoordinates[1] <= 0 && (verticalDownLines.contains(line))) ||
                (endCoordinates[1] >= 900 && verticalUpLines.contains(line))) {
            traffic.addSpawiningVerticalRoad(verticalRoads.at(i));
        }
        if ((startCoordinates[1] <= 0 && (verticalUpLines.contains(line))) ||
                (endCoordinates[1] >= 900 && verticalDownLines.contains(line))) {
            traffic.addEndingVerticalRoad(verticalRoads.at(i));
        }
    }
    //Initiate horizontal roads both right- and left-sided
    //Also add spawning/ending roads if requirements met
    for (int i = 0; i < horizontalLines.length(); i++) {
        QFrame *line = horizontalLines.at(i);
        int *startCoordinates = new int[]{line->x(), line->y()};
        int *endCoordinates = new int[]{line->x() + line->width(), line->y()};
        horizontalRoads.append(RoadPointer(new Road(startCoordinates, endCoordinates)));

        if (horizontalRightLines.contains(line)) {
            trafficRules.addHorizontalRightRoad(RoadPointer(new Road(startCoordinates, endCoordinates)));
        } else if (horizontalLeftLines.contains(line)) {
            trafficRules.addHorizontalLeftRoad(RoadPointer(new Road(startCoordinates, endCoordinates)));
        }


        if ((startCoordinates[0] <= 0 && (horizontalRightLines.contains(line)))){
            traffic.addSpawiningHorizontalRoad(horizontalRoads.at(i));
        }
        if ((startCoordinates[0] <= 0 && (horizontalLeftLines.contains(line)))){
            traffic.addEndingHorizontalRoad(horizontalRoads.at(i));
        }
    }
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    this->traffic.setTrafficIntensity(value);

//    qDebug() << this->traffic.getTrafficIntensity();
    car->setCurrentCoordinates(new int[]{value*2, value*2});
}

void MainWindow::paintEvent(QPaintEvent *event) {
    background = QSharedPointer<QPixmap>(new QPixmap(":/img/img/background.png"));
    QPainter painter(background.get());

    QPoint point;
    point.setX(car->getCurrentCoordinates()[0]);
    point.setY(car->getCurrentCoordinates()[1]);
    qDebug() << point.x();

    QImage copy = *car->getImage();
    painter.drawImage(point, copy);
    ui->map->setPixmap(*background);
}

void MainWindow::loadVehicles() {

}

void delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(500);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

