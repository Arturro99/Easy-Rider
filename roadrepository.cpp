#include "roadrepository.h"
#include <cstdlib>

RoadRepository::RoadRepository()
{

}

RoadPointer RoadRepository::findByCoordinates(int* startCoordinates, Direction currentDirection) {
    switch (currentDirection) {
        case UP: {
            for (int i = 0; i < verticalUpRoads.size(); i++) {
                if (abs(verticalUpRoads.at(i)->getStartCoordinates()[0]-startCoordinates[0]) <= 100 && abs(verticalUpRoads.at(i)->getEndCoordinates()[1] - startCoordinates[1]) <= 100) {
                    return verticalUpRoads.at(i);
                }
            }
            return *new RoadPointer(new Road(nullptr, nullptr, "nullptr"));
        }
        case DOWN: {
            for (int i = 0; i < verticalDownRoads.size(); i++) {
                if (abs(verticalDownRoads.at(i)->getStartCoordinates()[0]-startCoordinates[0]) <= 100 && abs(verticalDownRoads.at(i)->getStartCoordinates()[1] - startCoordinates[1]) <= 100) {
                    return verticalDownRoads.at(i);
                }
            }
            return *new RoadPointer(new Road(nullptr, nullptr, "nullptr"));
        }
        case RIGHT: {
            for (int i = 0; i < horizontalRightRoads.size(); i++) {
                if (abs(horizontalRightRoads.at(i)->getStartCoordinates()[0]-startCoordinates[0]) <= 100 && abs(horizontalRightRoads.at(i)->getStartCoordinates()[1] - startCoordinates[1]) <= 100) {
                    return horizontalRightRoads.at(i);
                }
            }
            return *new RoadPointer(new Road(nullptr, nullptr, "nullptr"));
        }
        case LEFT: {
            for (int i = 0; i < horizontalLeftRoads.size(); i++) {
                if (abs(horizontalLeftRoads.at(i)->getEndCoordinates()[0]-startCoordinates[0]) <= 100 && abs(horizontalLeftRoads.at(i)->getStartCoordinates()[1] - startCoordinates[1]) <= 100) {
                    return horizontalLeftRoads.at(i);
                }
            }
            return *new RoadPointer(new Road(nullptr, nullptr, "nullptr"));
        }
        default:
            return *new RoadPointer(new Road(nullptr, nullptr, "nullptr"));
    }
}

RoadPointer RoadRepository::findByNumberAndDirection(std::string number, Direction direction)
{
    QVector<RoadPointer> roads;
    switch (direction) {
        case UP: {
            roads = verticalUpRoads;
            break;
        }
        case DOWN: {
            roads = verticalDownRoads;
            break;
        }
        case LEFT: {
            roads = horizontalLeftRoads;
            break;
        }
        case RIGHT: {
            roads = horizontalRightRoads;
            break;
        }
    }
    for (auto road : roads) {
        if (RoadRepository::extractNumber(direction, road.get()->getName()) == number) {
            return road;
        }
    }
    return *new RoadPointer(new Road());
}

std::string RoadRepository::extractNumber(Direction direction, std::string name) {
    std::string number;
    if (direction == RIGHT) {
        if (name.size() == 13) return name.substr(4, 1);
        else if (name.size() == 14) return name.substr(4, 2);
        else if (name.size() == 15) return name.substr(4, 3);
        else if (name.size() == 16) return name.substr(4, 4);
    }
    else if (direction == LEFT) {
        if (name.size() == 12) return name.substr(4, 1);
        else if (name.size() == 13) return name.substr(4, 2);
        else if (name.size() == 14) return name.substr(4, 3);
        else if (name.size() == 15) return name.substr(4, 4);
    }
    return "0";
}

void RoadRepository::addRoads(QVector<RoadPointer> roads) {
    std::copy(roads.begin(), roads.end(), std::back_inserter(allRoads));
}

const QVector<RoadPointer> &RoadRepository::getVerticalRoads()
{
    return verticalRoads;
}
const RoadPointer &RoadRepository::getVerticalRoad(int i)
{
    return verticalRoads.at(i);
}
const QVector<RoadPointer> &RoadRepository::getHorizontalRoads()
{
    return horizontalRoads;
}
const RoadPointer &RoadRepository::getHorizontalRoad(int i)
{
    return horizontalRoads.at(i);
}
void RoadRepository::addVerticalRoad(RoadPointer road) {
    verticalRoads.append(road);
}
void RoadRepository::addHorizontalRoad(RoadPointer road) {
    horizontalRoads.append(road);
}

const QVector<RoadPointer> &RoadRepository::getSpawningVerticalUpRoads()
{
    return spawningVerticalUpRoads;
}


const QVector<RoadPointer> &RoadRepository::getSpawningVerticalDownRoads()
{
    return spawningVerticalDownRoads;
}

const QVector<RoadPointer> &RoadRepository::getSpawningHorizontalRoads()
{
    return spawningHorizontalRoads;
}

const QVector<RoadPointer> &RoadRepository::getEndingVerticalRoads()
{
    return endingVerticalRoads;
}

const QVector<RoadPointer> &RoadRepository::getEndingHorizontalRoads()
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

const QVector<RoadPointer> &RoadRepository::getVerticalDownRoads()
{
    return verticalDownRoads;
}

const QVector<RoadPointer> &RoadRepository::getVerticalUpRoads()
{
    return verticalUpRoads;
}

const QVector<RoadPointer> &RoadRepository::getHorizontalLeftRoads()
{
    return horizontalLeftRoads;
}

const QVector<RoadPointer> &RoadRepository::getHorizontalRightRoads()
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

void RoadRepository::assignSignToRoad(RoadPointer road, SignPointer sign, Direction direction)
{
    QVector<RoadPointer> roads = direction == LEFT ? horizontalLeftRoads : horizontalRightRoads;
    for (auto &r : roads) {
        if (r->getName() == road->getName()) {
            r->addSign(sign);
            return;
        }
    }
}
