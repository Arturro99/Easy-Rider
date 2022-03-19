#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <QPainter>
#include <QPoint>
#include <QFrame>
#include <QRegularExpression>
#include <QtGlobal>
#include <QTime>

MainWindow::MainWindow(VehiclePointer vehicle, RoadRepositoryPointer roadRepository, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->roadRepository = roadRepository;
    ui->setupUi(this);
    assignStreets();

    car = vehicle;
    srand( unsigned(time(0)));
    int randomHorizontalRoad = rand() % this->roadRepository->getSpawningHorizontalRoads().length();
    car->setCurrentCoordinates(new int[] {this->roadRepository->getSpawningHorizontalRoads().at(randomHorizontalRoad)->getStartCoordinates()[0],
                this->roadRepository->getSpawningHorizontalRoads().at(randomHorizontalRoad)->getStartCoordinates()[1]});
    RoadPointer currentRoad;
    roadRepository->findByCoordinates(car->getCurrentCoordinates(), car->getCurrentDirection(), currentRoad);
    car->setCurrentRoad(currentRoad);
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
        roadRepository->addVerticalRoad(RoadPointer(new Road(startCoordinates, endCoordinates)));

        if (verticalUpLines.contains(line)) {
            roadRepository->addVerticalUpRoad(RoadPointer(new Road(startCoordinates, endCoordinates)));
        } else if (verticalDownLines.contains(line)) {
            roadRepository->addVerticalDownRoad(RoadPointer(new Road(startCoordinates, endCoordinates)));
        }


        if ((startCoordinates[1] <= 0 && (verticalDownLines.contains(line))) ||
                (endCoordinates[1] >= 900 && verticalUpLines.contains(line))) {
            roadRepository->addSpawningVerticalRoad(roadRepository->getVerticalRoad(i));
        }
        if ((startCoordinates[1] <= 0 && (verticalUpLines.contains(line))) ||
                (endCoordinates[1] >= 900 && verticalDownLines.contains(line))) {
            roadRepository->addEndingVerticalRoad(roadRepository->getVerticalRoad(i));
        }
    }
    //Initiate horizontal roads both right- and left-sided
    //Also add spawning/ending roads if requirements met
    for (int i = 0; i < horizontalLines.length(); i++) {
        QFrame *line = horizontalLines.at(i);
        int *startCoordinates = new int[]{line->x(), line->y()};
        int *endCoordinates = new int[]{line->x() + line->width(), line->y()};
        roadRepository->addHorizontalRoad(RoadPointer(new Road(startCoordinates, endCoordinates)));

        if (horizontalRightLines.contains(line)) {
            roadRepository->addHorizontalRightRoad(RoadPointer(new Road(startCoordinates, endCoordinates)));
        } else if (horizontalLeftLines.contains(line)) {
            roadRepository->addHorizontalLeftRoad(RoadPointer(new Road(startCoordinates, endCoordinates)));
        }


        if ((startCoordinates[0] <= 0 && (horizontalRightLines.contains(line)))){
            roadRepository->addSpawningHorizontalRoad(roadRepository->getHorizontalRoad(i));
        }
        if ((startCoordinates[0] <= 0 && (horizontalLeftLines.contains(line)))){
            roadRepository->addEndingHorizontalRoad(roadRepository->getHorizontalRoad(i));
        }
    }
    roadRepository->addRoads(roadRepository->getHorizontalRoads());
    roadRepository->addRoads(roadRepository->getVerticalRoads());
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    this->traffic.setTrafficIntensity(value);
}

void MainWindow::paintEvent(QPaintEvent *event) {
    background = QSharedPointer<QPixmap>(new QPixmap(":/img/img/background.png"));
    QPainter painter(background.get());

    QPoint point;
    point.setX(car->getCurrentCoordinates()[0]);
    point.setY(car->getCurrentCoordinates()[1]);

    QImage copy = *car->getImage();
    painter.drawImage(point, copy);
    ui->map->setPixmap(*background);
}
