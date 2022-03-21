#include "roadrepository.h"
#include <cstdlib>

RoadRepository::RoadRepository()
{

}

bool RoadRepository::findByCoordinates(int* startCoordinates, Direction currentDirection, RoadPointer &currentRoad) {
    QVector<RoadPointer> roads;
    switch (currentDirection) {
        case UP: {
//            std::copy(verticalUpRoads.begin(), verticalUpRoads.end(), std::back_inserter(roads));
            for (auto &road: this->verticalUpRoads) {
                if (abs(road->getStartCoordinates()[0]-startCoordinates[0]) <= 100 && abs(road->getEndCoordinates()[1] - startCoordinates[1]) <= 100) {
                    currentRoad = road;
                    return true;
                }
            }
            return false;
        }
        case DOWN: {
//            std::copy(verticalDownRoads.begin(), verticalDownRoads.end(), std::back_inserter(roads));
            for (auto &road: this->verticalDownRoads) {
                if (abs(road->getStartCoordinates()[0]-startCoordinates[0]) <= 100 && abs(road->getStartCoordinates()[1] - startCoordinates[1]) <= 100) {
                    currentRoad = road;
                    return true;
                }
            }
            return false;
        }
        case RIGHT: {
//            std::copy(horizontalRightRoads.begin(), horizontalRightRoads.end(), std::back_inserter(roads));
            for (auto &road: this->horizontalRightRoads) {
                if (abs(road->getStartCoordinates()[0]-startCoordinates[0]) <= 100 && abs(road->getStartCoordinates()[1] - startCoordinates[1]) <= 100) {
                    currentRoad = road;
                    return true;
                }
            }
            return false;
        }
        case LEFT: {
//            std::copy(horizontalLeftRoads.begin(), horizontalLeftRoads.end(), std::back_inserter(roads));
            for (auto &road: this->horizontalLeftRoads) {
                if (abs(road->getEndCoordinates()[0]-startCoordinates[0]) <= 100 && abs(road->getStartCoordinates()[1] - startCoordinates[1]) <= 100) {
                    currentRoad = road;
                    return true;
                }
            }
            return false;
        }
        default:
            return false;
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
