#include <dos.h>
#include <QTime>
#include <QCoreApplication>
#include "vehicle.h"
#include "vehiclerepository.h"

Direction Vehicle::getInitialDirection() const
{
    return initialDirection;
}

bool Vehicle::collisionDetected(Vehicle* vehicle) {
    for (auto &veh : VehicleRepository::getVehicles()) {
        if (veh->getId() != vehicle->getId() &&
                veh->getCurrentDirection() == vehicle->getCurrentDirection() &&
                isTooClose(vehicle->getCurrentCoordinates(), veh->getCurrentCoordinates(), vehicle->getCurrentDirection()))
            return true;
    }
    return false;
}

bool Vehicle::giveWaySignDetected(Vehicle* vehicle) {
    RoadPointer road = *new RoadPointer(new Road);
    road = RoadRepository::findByNumberAndDirection(RoadRepository::extractNumber(vehicle->getCurrentDirection(), vehicle->getCurrentRoad()->getName()), vehicle->getCurrentDirection());
    if (road->getSigns().size() != 0) {
        QTime dieTime= QTime::currentTime().addMSecs(500);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        for (auto &road : RoadRepository::getVerticalRoads()) {
            if ((abs(vehicle->getCurrentCoordinates()[0] - road->getStartCoordinates()[0]) <= 150 &&
                    abs(vehicle->getCurrentCoordinates()[1] - road->getStartCoordinates()[1]) <= 150) ||
                    (abs(vehicle->getCurrentCoordinates()[0] - road->getEndCoordinates()[0]) <= 150 &&
                    abs(vehicle->getCurrentCoordinates()[1] - road->getEndCoordinates()[1]) <= 150) &&
                    road->getName() != vehicle->getCurrentRoad()->getName()) {
                for(auto &v : VehicleRepository::getVehicles()) {
                    if (road->getName() == v->getCurrentRoad()->getName()) {
                        return true;
                    }
                }
            }
        }
    }
    vehicle->currentDirection == LEFT ?
                vehicle->setCurrentCoordinates(new int[] {++getCurrentCoordinates()[0], getCurrentCoordinates()[1]}) :
                vehicle->setCurrentCoordinates(new int[] {--getCurrentCoordinates()[0], getCurrentCoordinates()[1]});
    return false;
}

void Vehicle::stop()
{
    while(giveWaySignDetected(this) || collisionDetected(this)) {

    }
    return;
}

bool Vehicle::isTooClose(int* currentVehicleCoordinates, int* anotherVehicleCoordinates, Direction direction) {
    if ((direction == DOWN) &&
            anotherVehicleCoordinates[1] - currentVehicleCoordinates[1] <= 200 &&
            anotherVehicleCoordinates[1] - currentVehicleCoordinates[1] > 0 &&
            abs(anotherVehicleCoordinates[0] - currentVehicleCoordinates[0]) <= 30) return true;
    else if ((direction == UP) &&
            currentVehicleCoordinates[1] - anotherVehicleCoordinates[1] <= 200 &&
             currentVehicleCoordinates[1] - anotherVehicleCoordinates[1] > 0 &&
             abs(anotherVehicleCoordinates[0] - currentVehicleCoordinates[0]) <= 30) return true;
    else if ((direction == RIGHT) &&
             anotherVehicleCoordinates[0] - currentVehicleCoordinates[0] <= 200 &&
             anotherVehicleCoordinates[0] - currentVehicleCoordinates[0] > 0 &&
             abs(anotherVehicleCoordinates[1] - currentVehicleCoordinates[1]) <= 30) return true;
    else if ((direction == LEFT) &&
             currentVehicleCoordinates[0] - anotherVehicleCoordinates[0] <= 200 &&
             currentVehicleCoordinates[0] - anotherVehicleCoordinates[0] > 0 &&
             abs(anotherVehicleCoordinates[1] - currentVehicleCoordinates[1]) <= 30) return true;
    else return false;
}

bool Vehicle::getWaiting() const
{
    return waiting;
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
        targetDirection = static_cast<Direction>(RandGenerator::generate(0, 3));
    }
    return targetDirection;
}

RoadPointer Vehicle::getCurrentRoad() const
{
    return currentRoad;
}

void Vehicle::setCurrentRoad(RoadPointer newCurrentRoad)
{
    currentRoad = newCurrentRoad;
}

const QUuid &Vehicle::getId() const
{
    return id;
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
