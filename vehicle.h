#ifndef VEHICLE_H
#define VEHICLE_H

#include <QImage>

typedef enum  {
    WEST,
    EAST,
    SOUTH,
    NORTH
} Direction;

class Vehicle
{   
protected:
    QImage *image;
    int basicVelocity;
    int *currentCoordinates;
    Direction currentDirection;
    virtual void drive(Direction direction) = 0;

public:
    QImage *getImage() const;
    void setImage(QImage *newImage);
    int getBasicVelocity() const;
    void setBasicVelocity(int newBasicVelocity);
    int *getCurrentCoordinates() const;
    void setCurrentCoordinates(int *newCurrentCoordinates);
    Direction getCurrentDirection() const;
    void setCurrentDirection(Direction newCurrentDirection);
};

#endif // VEHICLE_H
