#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "car.h"

#include <iostream>
#include <QPainter>
#include <QPoint>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSlider->setValue(50);
    assignStreets();

//    QPixmap pix(":/img/img/background.png");
//    pix.scaled(size(), Qt::IgnoreAspectRatio);
//    QPalette palette;
//    palette.setBrush(QPalette::Window, pix);
//    this->setPalette(palette);

    Vehicle *car = new Car();
//    car->setCurrentCoordinates(this->horizontalRoads[0].getStartCoordinates());
    car->setCurrentCoordinates(new int[]{200, 200});
    QPainter painter;
    QPoint point;
    point.setX(car->getCurrentCoordinates()[0]);
    point.setY(car->getCurrentCoordinates()[1]);
    painter.begin(car->getImage());
    painter.drawImage(point, *car->getImage());
    painter.drawRect(200, 200, 50, 50);
    painter.end();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::assignStreets()
{
    horizontalRoads = new Road[7];

    horizontalRoads[0].setStartCoordinates(new int[]{ui->road0hor->x(), ui->road0hor->y()});
    horizontalRoads[0].setEndCoordinates(new int[]{ui->road0hor->x() + ui->road0hor->width(), ui->road0hor->y()});
    horizontalRoads[1].setStartCoordinates(new int[]{ui->road1hor->x(), ui->road1hor->y()});
    horizontalRoads[1].setEndCoordinates(new int[]{ui->road1hor->x() + ui->road1hor->width(), ui->road1hor->y()});
    horizontalRoads[2].setStartCoordinates(new int[]{ui->road2hor->x(), ui->road2hor->y()});
    horizontalRoads[2].setEndCoordinates(new int[]{ui->road2hor->x() + ui->road2hor->width(), ui->road2hor->y()});
    horizontalRoads[3].setStartCoordinates(new int[]{ui->road3hor->x(), ui->road3hor->y()});
    horizontalRoads[3].setEndCoordinates(new int[]{ui->road3hor->x() + ui->road3hor->width(), ui->road3hor->y()});
    horizontalRoads[4].setStartCoordinates(new int[]{ui->road4hor->x(), ui->road4hor->y()});
    horizontalRoads[4].setEndCoordinates(new int[]{ui->road4hor->x() + ui->road4hor->width(), ui->road4hor->y()});

    verticalRoads[0].setStartCoordinates(new int[]{ui->road0ver->x(), ui->road0ver->y()});
    verticalRoads[0].setEndCoordinates(new int[]{ui->road0ver->x(), ui->road0ver->y() + ui->road0ver->height()});

    qDebug() << horizontalRoads[0].getStartCoordinates()[0];
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    this->traffic.setTrafficIntensity(value);
    qDebug() << this->traffic.getTrafficIntensity();
}

void MainWindow::paintEvent(QPaintEvent *event) {

}

