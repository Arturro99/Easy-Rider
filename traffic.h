#ifndef TRAFFIC_H
#define TRAFFIC_H

#include "road.h"
#include "vehicle.h"

#include <QSharedPointer>
#include <QTime>
class Traffic
{

private:
    int trafficIntensity;
    QVector<QSharedPointer<Vehicle>> vehiclesOnRoads;

public:
    Traffic();
    void changeTraffficIntensity(int);


    int getTrafficIntensity() const;
    void setTrafficIntensity(int newTrafficIntensity);

    void addVehiclesOnRoads(QSharedPointer<Vehicle> newVehicleOnRoads);

    const QVector<QSharedPointer<Vehicle>> &getVehiclesOnRoads() const;
};

#endif // TRAFFIC_H
