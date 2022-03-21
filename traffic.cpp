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

const QVector<QSharedPointer<Vehicle>> &Traffic::getVehiclesOnRoads() const
{
    return vehiclesOnRoads;
}

Traffic::Traffic()
{
    this->setTrafficIntensity(50);
}
