#ifndef ROAD_H
#define ROAD_H


class Road
{
private:
    int *startCoordinates;
    int *endCoordinates;

public:
    Road();


    int *getStartCoordinates() const;
    void setStartCoordinates(int *newStartCoordinates);
    int *getEndCoordinates() const;
    void setEndCoordinates(int *newEndCoordinates);
};

#endif // ROAD_H
