#include "traffic.h"

int Traffic::getTrafficIntensity() const
{
    return trafficIntensity;
}

void Traffic::setTrafficIntensity(int newTrafficIntensity)
{
    trafficIntensity = newTrafficIntensity;
}

void Traffic::addVehiclesOnRoads(QSharedPointer<Vehicle> newVehicleOnRoads)
{
    vehiclesOnRoads.append(newVehicleOnRoads);
}


void Traffic::addSpawiningVerticalRoad(RoadPointer newSpawningVerticalRoad)
{
    spawningVerticalRoads.append(newSpawningVerticalRoad);
}


void Traffic::addSpawiningHorizontalRoad(RoadPointer newSpawningHorizontalRoads)
{
    spawningHorizontalRoads.append(newSpawningHorizontalRoads);
}

void Traffic::addEndingVerticalRoad(RoadPointer newEndingVerticalRoad)
{
    endingVerticalRoads.append(newEndingVerticalRoad);
}

void Traffic::addEndingHorizontalRoad(RoadPointer newEndingHorizontalRoad)
{
    endingHorizontalRoads.append(newEndingHorizontalRoad);
}

const QVector<QSharedPointer<Vehicle>> &Traffic::getVehiclesOnRoads() const
{
    return vehiclesOnRoads;
}

const QVector<RoadPointer> &Traffic::getSpawningVerticalRoads() const
{
    return spawningVerticalRoads;
}

const QVector<RoadPointer> &Traffic::getSpawningHorizontalRoads() const
{
    return spawningHorizontalRoads;
}

const QVector<RoadPointer> &Traffic::getEndingVerticalRoads() const
{
    return endingVerticalRoads;
}

const QVector<RoadPointer> &Traffic::getEndingHorizontalRoads() const
{
    return endingHorizontalRoads;
}

Traffic::Traffic()
{
    this->setTrafficIntensity(50);
}

void Traffic::generateTraffic(VehiclePointer car)
{
    for (int i = 0; i < 200; i++) {
        QTime dieTime= QTime::currentTime().addMSecs(500);
//        while (QTime::currentTime() < dieTime)
//            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        car->setCurrentCoordinates(new int[]{i, i});

    }
}
