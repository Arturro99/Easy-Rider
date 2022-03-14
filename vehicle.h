#ifndef VEHICLE_H
#define VEHICLE_H

#include <QImage>
#include <QSharedPointer>

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
    Direction currentDirection;
    const Direction initialDirection;
    virtual void drive(Direction direction) = 0;
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

    void rotateVehicle(Direction targetDirection);
};

typedef QSharedPointer<Vehicle> VehiclePointer;

#endif // VEHICLE_H
