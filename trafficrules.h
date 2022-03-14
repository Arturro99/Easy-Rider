#ifndef TRAFFICRULES_H
#define TRAFFICRULES_H

#include "road.h"
#include "sign.h"
#include "trafficlight.h"

#include <QVector>

class TrafficRules
{
private:
    QVector<RoadPointer> verticalDownRoads;
    QVector<RoadPointer> verticalUpRoads;
    QVector<RoadPointer> horizontalLeftRoads;
    QVector<RoadPointer> horizontalRightRoads;
    QVector<Sign> signs;
    QVector<TrafficLight> trafficLights;

public:
    TrafficRules();


    const QVector<RoadPointer> &getVerticalDownRoads() const;
    const QVector<RoadPointer> &getVerticalUpRoads() const;
    const QVector<RoadPointer> &getHorizontalLeftRoads() const;
    const QVector<RoadPointer> &getHorizontalRightRoads() const;
    const QVector<Sign> &getSigns() const;
    const QVector<TrafficLight> &getTrafficLights() const;

    void addVerticalDownRoad(RoadPointer verticalDownRoad);
    void addVerticalUpRoad(RoadPointer verticalUpRoad);
    void addHorizontalLeftRoad(RoadPointer horizontalLeftRoad);
    void addHorizontalRightRoad(RoadPointer horizontalRightRoad);
};

#endif // TRAFFICRULES_H
