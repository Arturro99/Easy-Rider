#include "road.h"

int *Road::getStartCoordinates() const
{
    return startCoordinates;
}

void Road::setStartCoordinates(int *newStartCoordinates)
{
    startCoordinates = newStartCoordinates;
}

int *Road::getEndCoordinates() const
{
    return endCoordinates;
}

void Road::setEndCoordinates(int *newEndCoordinates)
{
    endCoordinates = newEndCoordinates;
}

Road::Road()
{

}

Road::Road(int *startCoordinates, int *endCoordinates)
{
    this->startCoordinates = startCoordinates;
    this->endCoordinates = endCoordinates;
}
