#include "roadrepository.h"

RoadRepository::RoadRepository()
{

}

RoadPointer RoadRepository::findRoadByStartCoordinates(int* startCoordinates) {
    for (auto road: allRoads) {
        if (road->getStartCoordinates()[0] == startCoordinates[0] && road->getStartCoordinates()[1] == startCoordinates[1]) {
            return road;
        }
    }
    return nullptr;
}
void RoadRepository::addRoad(RoadPointer road) {
    allRoads.append(road);
}

const QVector<RoadPointer> &RoadRepository::getVerticalRoads() const
{
    return verticalRoads;
}
const RoadPointer &RoadRepository::getVerticalRoad(int i) const
{
    return verticalRoads.at(i);
}
const QVector<RoadPointer> &RoadRepository::getHorizontalRoads() const
{
    return horizontalRoads;
}
const RoadPointer &RoadRepository::getHorizontalRoad(int i) const
{
    return horizontalRoads.at(i);
}
void RoadRepository::addVerticalRoad(RoadPointer road) {
    verticalRoads.append(road);
}
void RoadRepository::addHorizontalRoad(RoadPointer road) {
    horizontalRoads.append(road);
}

const QVector<RoadPointer> &RoadRepository::getSpawningVerticalRoads() const
{
    return spawningVerticalRoads;
}

const QVector<RoadPointer> &RoadRepository::getSpawningHorizontalRoads() const
{
    return spawningHorizontalRoads;
}

const QVector<RoadPointer> &RoadRepository::getEndingVerticalRoads() const
{
    return endingVerticalRoads;
}

const QVector<RoadPointer> &RoadRepository::getEndingHorizontalRoads() const
{
    return endingHorizontalRoads;
}
void RoadRepository::addSpawningVerticalRoad(RoadPointer road) {
    spawningVerticalRoads.append(road);
}
void RoadRepository::addSpawningHorizontalRoad(RoadPointer road) {
    spawningHorizontalRoads.append(road);
}
void RoadRepository::addEndingVerticalRoad(RoadPointer road) {
    endingVerticalRoads.append(road);
}
void RoadRepository::addEndingHorizontalRoad(RoadPointer road) {
    endingHorizontalRoads.append(road);
}

const QVector<RoadPointer> &RoadRepository::getVerticalDownRoads() const
{
    return verticalDownRoads;
}

const QVector<RoadPointer> &RoadRepository::getVerticalUpRoads() const
{
    return verticalUpRoads;
}

const QVector<RoadPointer> &RoadRepository::getHorizontalLeftRoads() const
{
    return horizontalLeftRoads;
}

const QVector<RoadPointer> &RoadRepository::getHorizontalRightRoads() const
{
    return horizontalRightRoads;
}
void RoadRepository::addVerticalDownRoad(RoadPointer verticalDownRoad)
{
    verticalDownRoads.append(verticalDownRoad);
}

void RoadRepository::addVerticalUpRoad(RoadPointer verticalUpRoad)
{
    verticalUpRoads.append(verticalUpRoad);
}

void RoadRepository::addHorizontalLeftRoad(RoadPointer horizontalLeftRoad)
{
    horizontalLeftRoads.append(horizontalLeftRoad);
}

void RoadRepository::addHorizontalRightRoad(RoadPointer horizontalRightRoad)
{
       horizontalRightRoads.append(horizontalRightRoad);
}
