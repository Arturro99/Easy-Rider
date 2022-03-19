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
    } else if (static_cast<int>(currentDirection) > static_cast<int>(targetDirection)){
        transform.rotate(90);
    }

    QImage rotatedImage = this->image->transformed(transform);
    *this->image = (rotatedImage);
    currentDirection = targetDirection;
}

Direction Vehicle::randomDirection(Direction currentDirection)
{
    Direction excludedDirection;
    switch (currentDirection) {
    case UP: {
        excludedDirection = DOWN;
        break;
    }
    case DOWN: {
        excludedDirection = UP;
        break;
    }
    case RIGHT: {
        excludedDirection = LEFT;
        break;
    }
    case LEFT: {
        excludedDirection = RIGHT;
        break;
    }
    }

    Direction targetDirection = excludedDirection;
    while(targetDirection == excludedDirection) {
        targetDirection = static_cast<Direction>(rand() % 4);
    }
    return targetDirection;
//    return DOWN;
}

RoadPointer Vehicle::getCurrentRoad() const
{
    return currentRoad;
}

void Vehicle::setCurrentRoad(RoadPointer newCurrentRoad)
{
    currentRoad = newCurrentRoad;
}

const std::string &Vehicle::getId() const
{
    return id;
}

void Vehicle::setId(const std::string &newId)
{
    id = newId;
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
