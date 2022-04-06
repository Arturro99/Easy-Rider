#ifndef VEHICLE_H
#define VEHICLE_H

#include <QImage>
#include <QSharedPointer>
#include <sstream>
#include <QUuid>
#include <QDebug>
#include "roadrepository.h"
#include "randgenerator.h"

class Vehicle : public QObject
{
    Q_OBJECT
private:
    bool isTooClose(int* coordinatesA, int* coordinatesB, Direction direction);
protected:
    bool waiting = true;
    QImage *image;
    QUuid id;
    int basicVelocity;
    int *currentCoordinates;
    RoadPointer currentRoad = *new RoadPointer(new Road);
    Direction currentDirection;
    const Direction initialDirection;
    explicit Vehicle(Direction initialDirection) : initialDirection(initialDirection) {};
    bool giveWaySignDetected(Vehicle* vehicle);

public:
    QImage *getImage() const;
    void setImage(QImage *newImage);
    int getBasicVelocity() const;
    void setBasicVelocity(int newBasicVelocity);
    int *getCurrentCoordinates() const;
    void setCurrentCoordinates(int *newCurrentCoordinates);
    Direction getCurrentDirection() const;
    void setCurrentDirection(Direction newCurrentDirection);
    Direction getInitialDirection() const;
    virtual void drive() = 0;
//    virtual ~Vehicle();

    bool collisionDetected(Vehicle* vehicle);
    void stop();



    void rotateVehicle(Direction targetDirection);
    Direction randomDirection(Direction currentDirection);
    RoadPointer getCurrentRoad() const;
    void setCurrentRoad(RoadPointer newCurrentRoad);
    const QUuid &getId() const;

    void setWaiting(bool newWaiting);

    bool getWaiting() const;

signals:
    void finished();
};

typedef QSharedPointer<Vehicle> VehiclePointer;

#endif // VEHICLE_H
