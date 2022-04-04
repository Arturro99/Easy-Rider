#ifndef ROAD_H
#define ROAD_H

#include <QSharedPointer>
#include "sign.h"

typedef enum  {
    UP,
    LEFT,
    DOWN,
    RIGHT
} Direction;

class Road
{
private:
    std::string name;
    int *startCoordinates;
    int *endCoordinates;
    QVector<SignPointer> signs;

public:
    Road();
    Road(int *startCoordinates, int *endCoordinates, std::string name);


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

    const QVector<SignPointer> &getSigns() const;
    void addSign(SignPointer sign);
    const std::string &getName() const;
    void setSigns(const QVector<SignPointer> &newSigns);

};

typedef QSharedPointer<Road> RoadPointer;

#endif // ROAD_H
