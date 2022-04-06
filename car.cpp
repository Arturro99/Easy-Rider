#include "car.h"

#include <QDebug>
#include <QTime>
#include <QCoreApplication>

void Car::drive() {
    while (true) {
        this->waiting = false;
        if (operateCar(this->getCurrentDirection()) == 0) {
            return;
        }
    }
}

int Car::operateCar(Direction direction) {
    int significantCoordinate;
    int* endingCoordinates;
    int firstCoordinateToCompare;
    int secondCoordinateToCompare;
    QVector<RoadPointer> roads;
    std::string operation;
    switch(direction) {
        case UP: {
            significantCoordinate = 1;
            endingCoordinates = currentRoad->getStartCoordinates();
            operation = "decrement";
            roads = RoadRepository::getEndingVerticalRoads();
            setCurrentCoordinates(new int[] {currentRoad->getStartCoordinates()[0], getCurrentCoordinates()[1]});
            break;
        }
        case DOWN: {
            significantCoordinate = 1;
            endingCoordinates = currentRoad->getEndCoordinates();
            operation = "increment";
            roads = RoadRepository::getEndingVerticalRoads();
            setCurrentCoordinates(new int[] {currentRoad->getStartCoordinates()[0], getCurrentCoordinates()[1]});
            break;
        }
        case RIGHT: {
            significantCoordinate = 0;
            endingCoordinates = currentRoad->getEndCoordinates();
            operation = "increment";
            roads = RoadRepository::getEndingHorizontalRoads();
            setCurrentCoordinates(new int[] {getCurrentCoordinates()[0], currentRoad->getStartCoordinates()[1]});
            break;
        }
        case LEFT: {
            significantCoordinate = 0;
            endingCoordinates = currentRoad->getStartCoordinates();
            operation = "decrement";
            roads = RoadRepository::getEndingHorizontalRoads();
            setCurrentCoordinates(new int[] {getCurrentCoordinates()[0], currentRoad->getStartCoordinates()[1]});
            break;
        }
    }
    firstCoordinateToCompare = this->getCurrentCoordinates()[significantCoordinate] > endingCoordinates[significantCoordinate] ?
                this->getCurrentCoordinates()[significantCoordinate] : endingCoordinates[significantCoordinate];
    secondCoordinateToCompare = this->getCurrentCoordinates()[significantCoordinate] > endingCoordinates[significantCoordinate] ?
                endingCoordinates[significantCoordinate] : this->getCurrentCoordinates()[significantCoordinate];

    while (firstCoordinateToCompare > secondCoordinateToCompare) {
        while(collisionDetected(this)) {
            this->waiting = true;
            return 0;
        }
        if (operation == "decrement") {
            if (significantCoordinate == 0) {
                setCurrentCoordinates(new int[] {--getCurrentCoordinates()[0], getCurrentCoordinates()[1]});
            } else {
                setCurrentCoordinates(new int[] {getCurrentCoordinates()[0], --getCurrentCoordinates()[1]});
            }
        } else {
            if (significantCoordinate == 0) {
                setCurrentCoordinates(new int[] {++getCurrentCoordinates()[0], getCurrentCoordinates()[1]});
            } else {
                setCurrentCoordinates(new int[] {getCurrentCoordinates()[0], ++getCurrentCoordinates()[1]});
            }
        }
        QTime dieTime= QTime::currentTime().addMSecs(10);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        if (this->getCurrentCoordinates()[significantCoordinate] == endingCoordinates[significantCoordinate]) {
            if (giveWaySignDetected(this)) {
                this->waiting = true;
                return 0;
            }
            for (auto &road : roads) {
                if (*this->getCurrentRoad().get() == *road.get()) {
                    return 0;
                }
            }
            Direction targetDirection = randomDirection(currentDirection);
            currentRoad = RoadRepository::findByCoordinates(this->getCurrentCoordinates(), targetDirection);
            while (!currentRoad->getStartCoordinates()) {
                targetDirection = randomDirection(currentDirection);
                currentRoad = RoadRepository::findByCoordinates(this->getCurrentCoordinates(), targetDirection);
            }
            rotateVehicle(targetDirection);
            break;
        }
    }
    return 1;
}

