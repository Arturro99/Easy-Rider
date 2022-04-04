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

const QVector<SignPointer> &Road::getSigns() const
{
    return signs;
}

void Road::addSign(SignPointer sign)
{
    signs.append(sign);
}

const std::string &Road::getName() const
{
    return name;
}
void Road::setSigns(const QVector<SignPointer> &newSigns)
{
    signs = newSigns;
}
Road::Road()
{

}

Road::Road(int *startCoordinates, int *endCoordinates, std::string name)
{
    this->startCoordinates = startCoordinates;
    this->endCoordinates = endCoordinates;
    this->name = name;
}
