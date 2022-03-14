#include "vehicle.h"

Direction Vehicle::getInitialDirection() const
{
    return initialDirection;
}

void Vehicle::rotateVehicle(Direction targetDirection)
{
    QTransform transform;

    //if currentDirection is UP and target is LEFT then rotate 90 degrees(right)
    //else if current direction is to the right of the target direction then rotate 270 degrees(left)
    //else rotate 90 degrees(right)
    if (static_cast<int>(currentDirection) == 0 && static_cast<int>(targetDirection) == 3) {
        transform.rotate(90);
    } else if (static_cast<int>(currentDirection) == 3 && static_cast<int>(targetDirection) == 0) {
        transform.rotate(270);
    }
    else if (static_cast<int>(currentDirection) < static_cast<int>(targetDirection)){
        transform.rotate(270);
    } else {
        transform.rotate(90);
    }

    QImage rotatedImage = this->image->transformed(transform);
    *this->image = (rotatedImage);
}

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
    this->currentCoordinates = newCurrentCoordinates;
}

Direction Vehicle::getCurrentDirection() const
{
    return currentDirection;
}

void Vehicle::setCurrentDirection(Direction newCurrentDirection)
{
    currentDirection = newCurrentDirection;
}
