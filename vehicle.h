#ifndef VEHICLE_H
#define VEHICLE_H

#include <QImage>
#include <QSharedPointer>

#include "road.h"

typedef enum  {
    UP,
    LEFT,
    DOWN,
    RIGHT
} Direction;

class Vehicle
{   
protected:
    QImage *image;
    int basicVelocity;
    int *currentCoordinates;
    RoadPointer currentRoad;
    Direction currentDirection;
    const Direction initialDirection;
    explicit Vehicle(Direction initialDirection) : initialDirection(initialDirection) {};

public:
    QImage *getImage() const;
    void setImage(QImage *newImage);
    int getBasicVelocity() const;
    void setBasicVelocity(int newBasicVelocity);
    int *getCurrentCoordinates() const;
    void setCurrentCoordinates(int *newCurrentCoordinates);
    Direction getCurrentDirection() const;
    void setCurrentDirection(Direction newCurrentDirection);
    Direction getInitialDirection() const;
    virtual void drive() = 0;


    void rotateVehicle(Direction targetDirection);
    RoadPointer getCurrentRoad() const;
    void setCurrentRoad(RoadPointer newCurrentRoad);
};

typedef QSharedPointer<Vehicle> VehiclePointer;

#endif // VEHICLE_H
