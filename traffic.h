#ifndef TRAFFIC_H
#define TRAFFIC_H

#include "road.h"
#include "vehicle.h"

#include <QSharedPointer>
#include <QSharedPointer>
#include <QTime>
class Traffic
{

private:
    int trafficIntensity;
    QVector<QSharedPointer<Vehicle>> vehiclesOnRoads;
    QVector<RoadPointer> spawningVerticalRoads;
    QVector<RoadPointer> spawningHorizontalRoads;
    QVector<RoadPointer> endingVerticalRoads;
    QVector<RoadPointer> endingHorizontalRoads;

public:
    Traffic();
    void changeTraffficIntensity(int);
    void generateTraffic(VehiclePointer car);


    int getTrafficIntensity() const;
    void setTrafficIntensity(int newTrafficIntensity);

    void addVehiclesOnRoads(QSharedPointer<Vehicle> newVehicleOnRoads);
    void addSpawiningVerticalRoad(RoadPointer newSpawningVerticalRoad);
    void addSpawiningHorizontalRoad(RoadPointer newSpawningHorizontalRoad);
    void addEndingVerticalRoad(RoadPointer newEndingVerticalRoad);
    void addEndingHorizontalRoad(RoadPointer newEndingHorizontalRoad);

    const QVector<QSharedPointer<Vehicle>> &getVehiclesOnRoads() const;
    const QVector<RoadPointer> &getSpawningVerticalRoads() const;
    const QVector<RoadPointer> &getSpawningHorizontalRoads() const;
    const QVector<RoadPointer> &getEndingVerticalRoads() const;
    const QVector<RoadPointer> &getEndingHorizontalRoads() const;
};

#endif // TRAFFIC_H
