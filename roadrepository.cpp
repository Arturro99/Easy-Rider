#include "roadrepository.h"
#include <cstdlib>

RoadRepository::RoadRepository()
{

}

RoadPointer RoadRepository::findByCoordinates(int* startCoordinates, Direction currentDirection) {
    QVector<RoadPointer> roads;
    switch (currentDirection) {
        case UP: {
//            std::copy(verticalUpRoads.begin(), verticalUpRoads.end(), std::back_inserter(roads));
            for (int i = 0; i < verticalUpRoads.size(); i++) {
                if (abs(verticalUpRoads.at(i)->getStartCoordinates()[0]-startCoordinates[0]) <= 100 && abs(verticalUpRoads.at(i)->getEndCoordinates()[1] - startCoordinates[1]) <= 100) {
                    return verticalUpRoads.at(i);
                }
            }
            return *new RoadPointer(new Road(nullptr, nullptr));
        }
        case DOWN: {
//            std::copy(verticalDownRoads.begin(), verticalDownRoads.end(), std::back_inserter(roads));
            for (int i = 0; i < verticalDownRoads.size(); i++) {
                if (abs(verticalDownRoads.at(i)->getStartCoordinates()[0]-startCoordinates[0]) <= 100 && abs(verticalDownRoads.at(i)->getStartCoordinates()[1] - startCoordinates[1]) <= 100) {
                    return verticalDownRoads.at(i);
                }
            }
            return *new RoadPointer(new Road(nullptr, nullptr));
        }
        case RIGHT: {
//            std::copy(horizontalRightRoads.begin(), horizontalRightRoads.end(), std::back_inserter(roads));
            for (int i = 0; i < horizontalRightRoads.size(); i++) {
                if (abs(horizontalRightRoads.at(i)->getStartCoordinates()[0]-startCoordinates[0]) <= 100 && abs(horizontalRightRoads.at(i)->getStartCoordinates()[1] - startCoordinates[1]) <= 100) {
                    return horizontalRightRoads.at(i);
                }
            }
            return *new RoadPointer(new Road(nullptr, nullptr));
        }
        case LEFT: {
//            std::copy(horizontalLeftRoads.begin(), horizontalLeftRoads.end(), std::back_inserter(roads));
            for (int i = 0; i < horizontalLeftRoads.size(); i++) {
                if (abs(horizontalLeftRoads.at(i)->getEndCoordinates()[0]-startCoordinates[0]) <= 100 && abs(horizontalLeftRoads.at(i)->getStartCoordinates()[1] - startCoordinates[1]) <= 100) {
                    return horizontalLeftRoads.at(i);
                }
            }
            return *new RoadPointer(new Road(nullptr, nullptr));
        }
        default:
            return *new RoadPointer(new Road(nullptr, nullptr));
    }
}

void RoadRepository::addRoads(QVector<RoadPointer> roads) {
    std::copy(roads.begin(), roads.end(), std::back_inserter(allRoads));
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

const QVector<RoadPointer> &RoadRepository::getSpawningVerticalUpRoads() const
{
    return spawningVerticalUpRoads;
}


const QVector<RoadPointer> &RoadRepository::getSpawningVerticalDownRoads() const
{
    return spawningVerticalDownRoads;
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
void RoadRepository::addSpawningVerticalUpRoad(RoadPointer road) {
    spawningVerticalUpRoads.append(road);
}
void RoadRepository::addSpawningVerticalDownRoad(RoadPointer road) {
    spawningVerticalDownRoads.append(road);
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
