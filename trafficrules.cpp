#include "trafficrules.h"

const QVector<Sign> &TrafficRules::getSigns() const
{
    return signs;
}

const QVector<TrafficLight> &TrafficRules::getTrafficLights() const
{
    return trafficLights;
}

TrafficRules::TrafficRules()
{

}
