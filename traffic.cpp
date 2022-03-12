#include "traffic.h"

int Traffic::getTrafficIntensity() const
{
    return trafficIntensity;
}

void Traffic::setTrafficIntensity(int newTrafficIntensity)
{
    trafficIntensity = newTrafficIntensity;
}

Traffic::Traffic()
{
    this->setTrafficIntensity(50);
}
