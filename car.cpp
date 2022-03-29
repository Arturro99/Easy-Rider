#include "car.h"

#include <QDebug>
#include <QTime>
#include <QCoreApplication>
#include <QThread>

void Car::drive() {
    while (true) {
        this->waiting = false;
        if (this->getCurrentDirection() == RIGHT) {
            setCurrentCoordinates(new int[] {getCurrentCoordinates()[0], currentRoad->getStartCoordinates()[1]});
//            qDebug() << "Driving right";
            while (this->getCurrentCoordinates()[0] < currentRoad->getEndCoordinates()[0]) {
                while(collisionDetected(this)) {
                    this->waiting = true;
                    return;
                }
                setCurrentCoordinates(new int[] {++getCurrentCoordinates()[0], getCurrentCoordinates()[1]});
                QTime dieTime= QTime::currentTime().addMSecs(10);
                while (QTime::currentTime() < dieTime)
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                if (this->getCurrentCoordinates()[0] == currentRoad->getEndCoordinates()[0]) {
                    Direction targetDirection = randomDirection(currentDirection);
                    currentRoad = roadRepository->findByCoordinates(this->getCurrentCoordinates(), targetDirection);
                    while (!currentRoad->getStartCoordinates()) {
                        targetDirection = randomDirection(currentDirection);
                        currentRoad = roadRepository->findByCoordinates(this->getCurrentCoordinates(), targetDirection);
                    }
                    rotateVehicle(targetDirection);
                    break;
                }
            }
        }
        if (this->getCurrentDirection() == DOWN) {
            setCurrentCoordinates(new int[] {currentRoad->getStartCoordinates()[0], getCurrentCoordinates()[1]});
//            qDebug() << "Driving down";
            while (this->getCurrentCoordinates()[1] < currentRoad->getEndCoordinates()[1]) {
                while(collisionDetected(this)) {
                    this->waiting = true;
                    return;
                }
                setCurrentCoordinates(new int[] {getCurrentCoordinates()[0], ++getCurrentCoordinates()[1]});
                QTime dieTime= QTime::currentTime().addMSecs(10);
                while (QTime::currentTime() < dieTime)
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                    if (this->getCurrentCoordinates()[1] == currentRoad->getEndCoordinates()[1]) {
                        for (auto road : roadRepository->getEndingVerticalRoads()) {
                            if (*this->getCurrentRoad().get() == *road.get()) {
                                this -> finished();
                                return;
                            }
                        }
                        Direction targetDirection = randomDirection(currentDirection);
                        currentRoad = roadRepository->findByCoordinates(this->getCurrentCoordinates(), targetDirection);
                        while (!currentRoad->getStartCoordinates()) {
                            targetDirection = randomDirection(currentDirection);
                            currentRoad = roadRepository->findByCoordinates(this->getCurrentCoordinates(), targetDirection);
                        }
                        rotateVehicle(targetDirection);
                        break;
                    }
            }
        }
        if (this->getCurrentDirection() == UP) {
            setCurrentCoordinates(new int[] {currentRoad->getStartCoordinates()[0], getCurrentCoordinates()[1]});
//            qDebug() << "Driving up";
            while (this->getCurrentCoordinates()[1] > currentRoad->getStartCoordinates()[1]) {
                while(collisionDetected(this)) {
                    this->waiting = true;
                    return;
                }
                setCurrentCoordinates(new int[] {getCurrentCoordinates()[0], --getCurrentCoordinates()[1]});
                QTime dieTime= QTime::currentTime().addMSecs(10);
                while (QTime::currentTime() < dieTime)
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                    if (this->getCurrentCoordinates()[1] == currentRoad->getStartCoordinates()[1]) {
                        for (auto road : roadRepository->getEndingVerticalRoads()) {
                            if (*this->getCurrentRoad().get() == *road.get()) {
                                this -> finished();
                                return;
                            }
                        }
                        Direction targetDirection = randomDirection(currentDirection);
                        currentRoad = roadRepository->findByCoordinates(this->getCurrentCoordinates(), targetDirection);
                        while (!currentRoad->getStartCoordinates()) {
                            targetDirection = randomDirection(currentDirection);
                            currentRoad = roadRepository->findByCoordinates(this->getCurrentCoordinates(), targetDirection);
                        }
                        rotateVehicle(targetDirection);
                        break;
                    }
            }
        }
        if (this->getCurrentDirection() == LEFT) {
            setCurrentCoordinates(new int[] {getCurrentCoordinates()[0], currentRoad->getStartCoordinates()[1]});
//            qDebug() << "Driving left";
            while (this->getCurrentCoordinates()[0] > currentRoad->getStartCoordinates()[0]) {
                while(collisionDetected(this)) {
                    this->waiting = true;
                    return;
                }
                setCurrentCoordinates(new int[] {--getCurrentCoordinates()[0], getCurrentCoordinates()[1]});
                QTime dieTime= QTime::currentTime().addMSecs(10);
                while (QTime::currentTime() < dieTime)
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                    if (this->getCurrentCoordinates()[0] == currentRoad->getStartCoordinates()[0]) {
                        for (auto road : roadRepository->getEndingHorizontalRoads()) {
                            if (*this->getCurrentRoad().get() == *road.get()) {
                                emit finished();
                                return;
                            }
                        }
                        Direction targetDirection = randomDirection(currentDirection);
                        currentRoad = roadRepository->findByCoordinates(this->getCurrentCoordinates(), targetDirection);
                        while (!currentRoad->getStartCoordinates()) {
                            targetDirection = randomDirection(currentDirection);
                            currentRoad = roadRepository->findByCoordinates(this->getCurrentCoordinates(), targetDirection);
                        }
                        rotateVehicle(targetDirection);
                        break;
                    }
                    }
            }
        }
}

