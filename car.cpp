#include "car.h"

Car::Car()
{
    QImage *image = new QImage(":/img/img/car.png");
    *image = image->scaled(80, 80, Qt::AspectRatioMode::KeepAspectRatio);
    this->image = image;
    this->basicVelocity = 10;
    this->currentDirection = WEST;
}
