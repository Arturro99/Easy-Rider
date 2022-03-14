#include "trafficrules.h"

const QVector<RoadPointer> &TrafficRules::getVerticalDownRoads() const
{
    return verticalDownRoads;
}

const QVector<RoadPointer> &TrafficRules::getVerticalUpRoads() const
{
    return verticalUpRoads;
}

const QVector<RoadPointer> &TrafficRules::getHorizontalLeftRoads() const
{
    return horizontalLeftRoads;
}

const QVector<RoadPointer> &TrafficRules::getHorizontalRightRoads() const
{
    return horizontalRightRoads;
}

const QVector<Sign> &TrafficRules::getSigns() const
{
    return signs;
}

const QVector<TrafficLight> &TrafficRules::getTrafficLights() const
{
    return trafficLights;
}

void TrafficRules::addVerticalDownRoad(RoadPointer verticalDownRoad)
{
    verticalDownRoads.append(verticalDownRoad);
}

void TrafficRules::addVerticalUpRoad(RoadPointer verticalUpRoad)
{
    verticalUpRoads.append(verticalUpRoad);
}

void TrafficRules::addHorizontalLeftRoad(RoadPointer horizontalLeftRoad)
{
    horizontalLeftRoads.append(horizontalLeftRoad);
}

void TrafficRules::addHorizontalRightRoad(RoadPointer horizontalRightRoad)
{
       horizontalRightRoads.append(horizontalRightRoad);
}

TrafficRules::TrafficRules()
{

}
