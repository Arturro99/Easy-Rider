#include "car.h"

#include <QDebug>
#include <QTime>
#include <QCoreApplication>

void Car::drive() {
    while (true) {
        if (this->getCurrentDirection() == RIGHT) {
            while (this->getCurrentCoordinates()[0] < currentRoad->getEndCoordinates()[0]) {
                setCurrentCoordinates(new int[] {++getCurrentCoordinates()[0], getCurrentCoordinates()[1]});
                QTime dieTime= QTime::currentTime().addMSecs(1);
    //            while (QTime::currentTime() < dieTime)
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
                if (this->getCurrentCoordinates()[0] == currentRoad->getEndCoordinates()[0]) {
                    rotateVehicle(randomDirection(currentDirection));
                    while (!roadRepository->findByCoordinates(this->getCurrentCoordinates(), currentDirection, currentRoad)) {
                        rotateVehicle(randomDirection(currentDirection));
                    }
                    break;
                }
            }
        }
        if (this->getCurrentDirection() == DOWN) {
            while (this->getCurrentCoordinates()[1] < currentRoad->getEndCoordinates()[1]) {
                setCurrentCoordinates(new int[] {getCurrentCoordinates()[0], ++getCurrentCoordinates()[1]});
                QTime dieTime= QTime::currentTime().addMSecs(1);
    //            while (QTime::currentTime() < dieTime)
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
                    if (this->getCurrentCoordinates()[1] == currentRoad->getEndCoordinates()[1]) {
                        rotateVehicle(randomDirection(currentDirection));
                        while (!roadRepository->findByCoordinates(this->getCurrentCoordinates(), currentDirection, currentRoad)) {
                            rotateVehicle(randomDirection(currentDirection));
                        }
                        break;
                    }
            }
        }
        if (this->getCurrentDirection() == UP) {
            while (this->getCurrentCoordinates()[1] > currentRoad->getStartCoordinates()[1]) {
                setCurrentCoordinates(new int[] {getCurrentCoordinates()[0], --getCurrentCoordinates()[1]});
                QTime dieTime= QTime::currentTime().addMSecs(1);
    //            while (QTime::currentTime() < dieTime)
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
                    if (this->getCurrentCoordinates()[1] == currentRoad->getStartCoordinates()[1]) {
                        rotateVehicle(randomDirection(currentDirection));
                        while (!roadRepository->findByCoordinates(this->getCurrentCoordinates(), currentDirection, currentRoad)) {
                            rotateVehicle(randomDirection(currentDirection));
                        }
                        break;
                    }
            }
        }
        if (this->getCurrentDirection() == LEFT) {
            while (this->getCurrentCoordinates()[0] > currentRoad->getStartCoordinates()[0]) {
                setCurrentCoordinates(new int[] {--getCurrentCoordinates()[0], getCurrentCoordinates()[1]});
                QTime dieTime= QTime::currentTime().addMSecs(1);
    //            while (QTime::currentTime() < dieTime)
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
                    if (this->getCurrentCoordinates()[0] == currentRoad->getStartCoordinates()[0]) {
                        rotateVehicle(randomDirection(currentDirection));
                        while (!roadRepository->findByCoordinates(this->getCurrentCoordinates(), currentDirection, currentRoad)) {
                            rotateVehicle(randomDirection(currentDirection));
                        }
                        break;
                    }
            }
        }
    }
}
