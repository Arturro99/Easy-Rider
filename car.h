#ifndef CAR_H
#define CAR_H

#include "vehicle.h"



class Car : public Vehicle
{

public:
    Car(Direction initialDirection, RoadRepositoryPointer roadRepository) : Vehicle(initialDirection, roadRepository)
    {
        this->id = QUuid::createUuid();
        QImage *image = new QImage(":/img/img/car.png");
        QTransform transform;
        switch (initialDirection) {
            case 0: {
                transform.rotate(270);
                break;
            }
            case DOWN: {
                transform.rotate(90);
                break;
            }
            case RIGHT: {
                transform.rotate(0);
                break;
            }
            case LEFT: {
                transform.rotate(180);

            }
        }
        *image = image->transformed(transform);
        *image = image->scaled(80, 80, Qt::AspectRatioMode::KeepAspectRatio);
        this->image = image;
        this->basicVelocity = 10;
        this->currentDirection = initialDirection;
    }
    virtual void drive();
};



#endif // CAR_H
