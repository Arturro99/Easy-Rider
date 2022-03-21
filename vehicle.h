#ifndef VEHICLE_H
#define VEHICLE_H

#include <QImage>
#include <QSharedPointer>
#include <sstream>
#include <QUuid>
#include <QDebug>

#include "roadrepository.h"
#include "roadrepository.h"

class Vehicle : public QObject
{   
    Q_OBJECT
protected:
    QImage *image;
    QUuid id;
    int basicVelocity;
    int *currentCoordinates;
    RoadPointer currentRoad = *new RoadPointer(new Road);
    RoadRepositoryPointer roadRepository;
    Direction currentDirection;
    const Direction initialDirection;
    explicit Vehicle(Direction initialDirection, RoadRepositoryPointer roadRepository) : initialDirection(initialDirection), roadRepository(roadRepository) {};

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



    void rotateVehicle(Direction targetDirection);
    Direction randomDirection(Direction currentDirection);
    RoadPointer getCurrentRoad() const;
    void setCurrentRoad(RoadPointer newCurrentRoad);
    const QUuid &getId() const;

signals:
    void finished();
};

typedef QSharedPointer<Vehicle> VehiclePointer;

#endif // VEHICLE_H
