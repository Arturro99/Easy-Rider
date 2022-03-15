#ifndef TRAFFICRULES_H
#define TRAFFICRULES_H

#include "road.h"
#include "sign.h"
#include "trafficlight.h"

#include <QVector>

class TrafficRules
{
private:
    QVector<Sign> signs;
    QVector<TrafficLight> trafficLights;

public:
    TrafficRules();

    const QVector<Sign> &getSigns() const;
    const QVector<TrafficLight> &getTrafficLights() const;
};

#endif // TRAFFICRULES_H
