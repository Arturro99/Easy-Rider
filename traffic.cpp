#include "traffic.h"

int Traffic::getTrafficIntensity() const
{
    return trafficIntensity;
}

void Traffic::setTrafficIntensity(int newTrafficIntensity)
{
    trafficIntensity = newTrafficIntensity;
}

Vehicle *Traffic::getVehiclesOnRoads() const
{
    return vehiclesOnRoads;
}

void Traffic::setVehiclesOnRoads(Vehicle *newVehiclesOnRoads)
{
    vehiclesOnRoads = newVehiclesOnRoads;
}

Road *Traffic::getSpawningVerticalRoads() const
{
    return spawningVerticalRoads;
}

void Traffic::setSpawningVerticalRoads(Road *newSpawningVerticalRoads)
{
    spawningVerticalRoads = newSpawningVerticalRoads;
}

Road *Traffic::getSpawningHorizontalRoads() const
{
    return spawningHorizontalRoads;
}

void Traffic::setSpawningHorizontalRoads(Road *newSpawningHorizontalRoads)
{
    spawningHorizontalRoads = newSpawningHorizontalRoads;
}

Traffic::Traffic()
{
    this->setTrafficIntensity(50);
}
