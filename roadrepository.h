#ifndef ROADREPOSITORY_H
#define ROADREPOSITORY_H

#include "road.h"

class RoadRepository
{
private:
    QVector<RoadPointer> allRoads;

    QVector<RoadPointer> horizontalRoads;
    QVector<RoadPointer> verticalRoads;

    QVector<RoadPointer> spawningVerticalUpRoads;
    QVector<RoadPointer> spawningVerticalDownRoads;
    QVector<RoadPointer> spawningHorizontalRoads;
    QVector<RoadPointer> endingVerticalRoads;
    QVector<RoadPointer> endingHorizontalRoads;

    QVector<RoadPointer> verticalDownRoads;
    QVector<RoadPointer> verticalUpRoads;
    QVector<RoadPointer> horizontalLeftRoads;
    QVector<RoadPointer> horizontalRightRoads;
public:
    RoadRepository();

    RoadPointer findByCoordinates(int* startCoordinates, Direction currentDirection);
    void addRoads(QVector<RoadPointer> road);

    const QVector<RoadPointer> &getVerticalRoads() const;
    const RoadPointer &getVerticalRoad(int i) const;
    const QVector<RoadPointer> &getHorizontalRoads() const;
    const RoadPointer &getHorizontalRoad(int i) const;
    void addVerticalRoad(RoadPointer road);
    void addHorizontalRoad(RoadPointer road);

    const QVector<RoadPointer> &getSpawningVerticalUpRoads() const;
    const QVector<RoadPointer> &getSpawningVerticalDownRoads() const;
    const QVector<RoadPointer> &getSpawningHorizontalRoads() const;
    const QVector<RoadPointer> &getEndingVerticalRoads() const;
    const QVector<RoadPointer> &getEndingHorizontalRoads() const;
    void addSpawningVerticalUpRoad(RoadPointer road);
    void addSpawningVerticalDownRoad(RoadPointer road);
    void addSpawningHorizontalRoad(RoadPointer road);
    void addEndingVerticalRoad(RoadPointer road);
    void addEndingHorizontalRoad(RoadPointer road);

    const QVector<RoadPointer> &getVerticalDownRoads() const;
    const QVector<RoadPointer> &getVerticalUpRoads() const;
    const QVector<RoadPointer> &getHorizontalLeftRoads() const;
    const QVector<RoadPointer> &getHorizontalRightRoads() const;
    void addVerticalDownRoad(RoadPointer verticalDownRoad);
    void addVerticalUpRoad(RoadPointer verticalUpRoad);
    void addHorizontalLeftRoad(RoadPointer horizontalLeftRoad);
    void addHorizontalRightRoad(RoadPointer horizontalRightRoad);
};

typedef QSharedPointer<RoadRepository> RoadRepositoryPointer;

#endif // ROADREPOSITORY_H
