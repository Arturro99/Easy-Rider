#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <QPainter>
#include <QFrame>
#include <QRegularExpression>
#include <QtGlobal>
#include <QTime>

MainWindow::MainWindow(DriveThreadCreator *threadCreator, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    this->threadCreator = threadCreator;
    ui->setupUi(this);
    assignStreets();
    assignSigns();

    ui->horizontalSlider->setValue(50);
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
        std::string name = line->objectName().toStdString();
        RoadRepository::addVerticalRoad(RoadPointer(new Road(startCoordinates, endCoordinates, name)));

        if (verticalUpLines.contains(line)) {
            RoadRepository::addVerticalUpRoad(RoadPointer(new Road(startCoordinates, endCoordinates, name)));
        } else if (verticalDownLines.contains(line)) {
            RoadRepository::addVerticalDownRoad(RoadPointer(new Road(startCoordinates, endCoordinates, name)));
        }


        if (startCoordinates[1] <= 0 && verticalDownLines.contains(line)) {
            RoadRepository::addSpawningVerticalDownRoad(RoadRepository::getVerticalRoad(i));
        } else if (endCoordinates[1] >= 900 && verticalUpLines.contains(line)) {
            RoadRepository::addSpawningVerticalUpRoad(RoadRepository::getVerticalRoad(i));
        }
        if ((startCoordinates[1] <= 0 && (verticalUpLines.contains(line))) ||
                (endCoordinates[1] >= 900 && verticalDownLines.contains(line))) {
            RoadRepository::addEndingVerticalRoad(RoadRepository::getVerticalRoad(i));
        }
    }
    //Initiate horizontal roads both right- and left-sided
    //Also add spawning/ending roads if requirements met
    for (int i = 0; i < horizontalLines.length(); i++) {
        QFrame *line = horizontalLines.at(i);
        int *startCoordinates = new int[]{line->x(), line->y()};
        int *endCoordinates = new int[]{line->x() + line->width(), line->y()};
        std::string name = line->objectName().toStdString();
        RoadRepository::addHorizontalRoad(RoadPointer(new Road(startCoordinates, endCoordinates, name)));

        if (horizontalRightLines.contains(line)) {
            RoadRepository::addHorizontalRightRoad(RoadPointer(new Road(startCoordinates, endCoordinates, name)));
        } else if (horizontalLeftLines.contains(line)) {
            RoadRepository::addHorizontalLeftRoad(RoadPointer(new Road(startCoordinates, endCoordinates, name)));
        }


        if ((startCoordinates[0] <= 0 && (horizontalRightLines.contains(line)))){
            RoadRepository::addSpawningHorizontalRoad(RoadRepository::getHorizontalRoad(i));
        }
        if ((startCoordinates[0] <= 0 && (horizontalLeftLines.contains(line)))){
            RoadRepository::addEndingHorizontalRoad(RoadRepository::getHorizontalRoad(i));
        }
    }
    RoadRepository::addRoads(RoadRepository::getHorizontalRoads());
    RoadRepository::addRoads(RoadRepository::getVerticalRoads());
}

void MainWindow::assignSigns() {
    QRegularExpression giveWaySignExpression("^.+GIVE.*$");
    QRegularExpression giveWayRightSignExpression("^.+GIVE.*Right$");
    QRegularExpression giveWayLeftSignExpression("^.+GIVE.*Left$");

    QList<QFrame*> giveWaySigns = ui->centralwidget->findChildren<QFrame*>(giveWaySignExpression);
    QList<QFrame*> giveWayRightSigns = ui->centralwidget->findChildren<QFrame*>(giveWayRightSignExpression);
    QList<QFrame*> giveWayLeftSigns = ui->centralwidget->findChildren<QFrame*>(giveWayLeftSignExpression);

    std::pair<std::string, std::string> directionAndNumber;
    std::string number;
    for (auto sign : giveWaySigns) {
        SignPointer obj(new Sign(GIVE_WAY));
        SignRepository::addSign(obj);
        if (giveWayRightSigns.contains(sign)) {
            if (sign->objectName().size() == 14) number = sign->objectName().toStdString().substr(8, 1);
            else if (sign->objectName().size() == 15) number = sign->objectName().toStdString().substr(8, 2);
            else if (sign->objectName().size() == 16) number = sign->objectName().toStdString().substr(8, 3);
            else if (sign->objectName().size() == 17) number = sign->objectName().toStdString().substr(8, 4);
            directionAndNumber = std::make_pair("Right", number);
        }
        else if (giveWayLeftSigns.contains(sign)) {
            if (sign->objectName().size() == 13) number = sign->objectName().toStdString().substr(8, 1);
            else if (sign->objectName().size() == 14) number = sign->objectName().toStdString().substr(8, 2);
            else if (sign->objectName().size() == 15) number = sign->objectName().toStdString().substr(8, 3);
            else if (sign->objectName().size() == 16) number = sign->objectName().toStdString().substr(8, 4);
            directionAndNumber = std::make_pair("Left", number);
        }
        directionAndNumber.first == "Right" ?
                    RoadRepository::assignSignToRoad(RoadRepository::findByNumberAndDirection(directionAndNumber.second, RIGHT), obj) :
                    RoadRepository::assignSignToRoad(RoadRepository::findByNumberAndDirection(directionAndNumber.second, LEFT), obj);
    }
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    double cpuConverter = 10.0 / QThread::idealThreadCount() * 1.0;
    value = value / 10 + 1;     // [1;2...;10]

    int currentThreadsNumber = threadCreator->getThreadsNumber();
    int targetThreadsNumber = value / cpuConverter;

    while (currentThreadsNumber != targetThreadsNumber) {
        targetThreadsNumber > currentThreadsNumber ? threadCreator->addThread() : threadCreator->removeThread();
        currentThreadsNumber = threadCreator->getThreadsNumber();
    }
}

void MainWindow::paintEvent(QPaintEvent *event) {
    background = QSharedPointer<QPixmap>(new QPixmap(":/img/img/background2.png"));
    QPainter painter(background.get());

    for (auto &vehicle : VehicleRepository::getVehicles()) {
        if (vehicle->getImage() == NULL) {
            VehicleRepository::removeVehicle(vehicle->getId());
            continue;
        }
        QPoint point;
        QImage image = *vehicle->getImage();
        point.setX(vehicle->getCurrentCoordinates()[0]);
        point.setY(vehicle->getCurrentCoordinates()[1]);
        this->qPoints.append(point);
        painter.drawImage(point, image);
    }

    ui->map->setPixmap(*background);
}
