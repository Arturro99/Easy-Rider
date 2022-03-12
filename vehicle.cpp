#include "vehicle.h"

QImage *Vehicle::getImage() const
{
    return image;
}

void Vehicle::setImage(QImage *newImage)
{
    image = newImage;
}

int Vehicle::getBasicVelocity() const
{
    return basicVelocity;
}

void Vehicle::setBasicVelocity(int newBasicVelocity)
{
    basicVelocity = newBasicVelocity;
}

int *Vehicle::getCurrentCoordinates() const
{
    return currentCoordinates;
}

void Vehicle::setCurrentCoordinates(int *newCurrentCoordinates)
{
    currentCoordinates = newCurrentCoordinates;
}

Direction Vehicle::getCurrentDirection() const
{
    return currentDirection;
}

void Vehicle::setCurrentDirection(Direction newCurrentDirection)
{
    currentDirection = newCurrentDirection;
}
