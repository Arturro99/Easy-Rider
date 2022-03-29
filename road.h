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

    friend bool operator==(const Road& road1, const Road& road2) {
        return (road1.getStartCoordinates()[0] == road2.getStartCoordinates()[0] &&
            road1.getStartCoordinates()[1] == road2.getStartCoordinates()[1] &&
            road1.getEndCoordinates()[0] == road2.getEndCoordinates()[0] &&
            road1.getEndCoordinates()[1] == road2.getEndCoordinates()[1]);
    }
};

typedef QSharedPointer<Road> RoadPointer;

#endif // ROAD_H
