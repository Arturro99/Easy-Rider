#ifndef ROAD_H
#define ROAD_H

#include <QSharedPointer>

typedef enum  {
    UP,
    LEFT,
    DOWN,
    RIGHT
} Direction;

class Road
{
private:
    int *startCoordinates;
    int *endCoordinates;

public:
    Road();
    Road(int *startCoordinates, int *endCoordinates);


    int *getStartCoordinates() const;
    void setStartCoordinates(int *newStartCoordinates);
    int *getEndCoordinates() const;
    void setEndCoordinates(int *newEndCoordinates);
};

typedef QSharedPointer<Road> RoadPointer;

#endif // ROAD_H
