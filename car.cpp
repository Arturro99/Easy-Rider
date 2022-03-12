#include "car.h"

Car::Car()
{
    this->image = new QImage(":/img/img/background.png");
    this->basicVelocity = 10;
    this->currentDirection = WEST;
}
