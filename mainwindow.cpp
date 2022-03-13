#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "car.h"

#include <iostream>
#include <QPainter>
#include <QPoint>
#include <QFrame>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSlider->setValue(50);
    assignStreets();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::assignStreets()
{
//    horizontalRoads = new Road[7];

//    horizontalRoads[0].setStartCoordinates(new int[]{ui->road0hor->x(), ui->road0hor->y()});
//    horizontalRoads[0].setEndCoordinates(new int[]{ui->road0hor->x() + ui->road0hor->width(), ui->road0hor->y()});
//    horizontalRoads[1].setStartCoordinates(new int[]{ui->road1hor->x(), ui->road1hor->y()});
//    horizontalRoads[1].setEndCoordinates(new int[]{ui->road1hor->x() + ui->road1hor->width(), ui->road1hor->y()});
//    horizontalRoads[2].setStartCoordinates(new int[]{ui->road2hor->x(), ui->road2hor->y()});
//    horizontalRoads[2].setEndCoordinates(new int[]{ui->road2hor->x() + ui->road2hor->width(), ui->road2hor->y()});
//    horizontalRoads[3].setStartCoordinates(new int[]{ui->road3hor->x(), ui->road3hor->y()});
//    horizontalRoads[3].setEndCoordinates(new int[]{ui->road3hor->x() + ui->road3hor->width(), ui->road3hor->y()});
//    horizontalRoads[4].setStartCoordinates(new int[]{ui->road4hor->x(), ui->road4hor->y()});
//    horizontalRoads[4].setEndCoordinates(new int[]{ui->road4hor->x() + ui->road4hor->width(), ui->road4hor->y()});

//    verticalRoads[0].setStartCoordinates(new int[]{ui->road0ver->x(), ui->road0ver->y()});
//    verticalRoads[0].setEndCoordinates(new int[]{ui->road0ver->x(), ui->road0ver->y() + ui->road0ver->height()});

    QRegularExpression verticalLinesExpression("^.+ver$");
    QRegularExpression horizontalLinesExpression("^.+hor$");
    QList<QFrame*> horizontalLines = ui->centralwidget->findChildren<QFrame*>(horizontalLinesExpression);
    QList<QFrame*> verticalLines = ui->centralwidget->findChildren<QFrame*>(verticalLinesExpression);

    horizontalRoads = new Road[horizontalLines.length()];
    verticalRoads = new Road[verticalLines.length()];

    for (int i = 0; i < verticalLines.length(); i++) {
        verticalRoads[i].setStartCoordinates(new int[]{verticalLines[i]->x(), verticalLines[i]->y()});
        verticalRoads[i].setEndCoordinates(new int[]{verticalLines[i]->x(), verticalLines[i]->y() + verticalLines[i]->height()});
    }
    for (int i = 0; i < horizontalLines.length(); i++) {
        horizontalRoads[i].setStartCoordinates(new int[]{horizontalLines[i]->x(), horizontalLines[i]->y()});
        horizontalRoads[i].setEndCoordinates(new int[]{horizontalLines[i]->x() + horizontalLines[i]->width(), horizontalLines[i]->y()});
        qDebug() << horizontalRoads[i].getStartCoordinates()[0] << "\t" << horizontalRoads[i].getStartCoordinates()[1];
        qDebug() << horizontalRoads[i].getEndCoordinates()[0] << "\t" << horizontalRoads[i].getEndCoordinates()[1] << "\n";
    }
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    this->traffic.setTrafficIntensity(value);
//    qDebug() << this->traffic.getTrafficIntensity();
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Vehicle *car = new Car();
    car->setCurrentCoordinates(this->horizontalRoads[0].getStartCoordinates());

    QPixmap *pixmap = new QPixmap(":/img/img/background.png");
    QPainter painter(pixmap);

    QPoint point;
    point.setX(car->getCurrentCoordinates()[0]);
    point.setY(car->getCurrentCoordinates()[1]);
    painter.drawImage(point, *car->getImage());
    painter.end();
    if (ui->map->pixmap().isNull()) {
        ui->map->setPixmap(*pixmap);
    }
}

void MainWindow::loadVehicles() {

}

QPixmap *MainWindow::getPixmap() const
{
    return pixmap;
}

void MainWindow::setPixmap(QPixmap *newPixmap)
{
    pixmap = newPixmap;
}

