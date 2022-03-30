#ifndef ROADREPOSITORY_H
#define ROADREPOSITORY_H

#include "road.h"

class RoadRepository
{
private:
    inline static QVector<RoadPointer> allRoads;

    inline static QVector<RoadPointer> horizontalRoads;
    inline static QVector<RoadPointer> verticalRoads;

    inline static QVector<RoadPointer> spawningVerticalUpRoads;
    inline static QVector<RoadPointer> spawningVerticalDownRoads;
    inline static QVector<RoadPointer> spawningHorizontalRoads;
    inline static QVector<RoadPointer> endingVerticalRoads;
    inline static QVector<RoadPointer> endingHorizontalRoads;

    inline static QVector<RoadPointer> verticalDownRoads;
    inline static QVector<RoadPointer> verticalUpRoads;
    inline static QVector<RoadPointer> horizontalLeftRoads;
    inline static QVector<RoadPointer> horizontalRightRoads;

    static std::string extractNumber(Direction direction, std::string name);
public:
    RoadRepository();

    static RoadPointer findByCoordinates(int* startCoordinates, Direction currentDirection);
    static RoadPointer findByNumberAndDirection(std::string number, Direction direction);
    static void addRoads(QVector<RoadPointer> road);

    static const QVector<RoadPointer> &getVerticalRoads();
    static const RoadPointer &getVerticalRoad(int i);
    static const QVector<RoadPointer> &getHorizontalRoads();
    static const RoadPointer &getHorizontalRoad(int i);
    static void addVerticalRoad(RoadPointer road);
    static void addHorizontalRoad(RoadPointer road);

    static const QVector<RoadPointer> &getSpawningVerticalUpRoads();
    static const QVector<RoadPointer> &getSpawningVerticalDownRoads();
    static const QVector<RoadPointer> &getSpawningHorizontalRoads();
    static const QVector<RoadPointer> &getEndingVerticalRoads();
    static const QVector<RoadPointer> &getEndingHorizontalRoads();
    static void addSpawningVerticalUpRoad(RoadPointer road);
    static void addSpawningVerticalDownRoad(RoadPointer road);
    static void addSpawningHorizontalRoad(RoadPointer road);
    static void addEndingVerticalRoad(RoadPointer road);
    static void addEndingHorizontalRoad(RoadPointer road);

    static const QVector<RoadPointer> &getVerticalDownRoads();
    static const QVector<RoadPointer> &getVerticalUpRoads();
    static const QVector<RoadPointer> &getHorizontalLeftRoads();
    static const QVector<RoadPointer> &getHorizontalRightRoads();
    static void addVerticalDownRoad(RoadPointer verticalDownRoad);
    static void addVerticalUpRoad(RoadPointer verticalUpRoad);
    static void addHorizontalLeftRoad(RoadPointer horizontalLeftRoad);
    static void addHorizontalRightRoad(RoadPointer horizontalRightRoad);

    static void assignSignToRoad(RoadPointer road, SignPointer sign);
};

typedef QSharedPointer<RoadRepository> RoadRepositoryPointer;

#endif // ROADREPOSITORY_H
