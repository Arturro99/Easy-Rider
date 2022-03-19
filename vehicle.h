#ifndef VEHICLE_H
#define VEHICLE_H

#include <QImage>
#include <QSharedPointer>
#include <random>
#include <sstream>

#include "roadrepository.h"

class Vehicle
{   
protected:
    QImage *image;
    UUID id
    int basicVelocity;
    int *currentCoordinates;
    RoadPointer currentRoad;
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


    void rotateVehicle(Direction targetDirection);
    Direction randomDirection(Direction currentDirection);
    RoadPointer getCurrentRoad() const;
    void setCurrentRoad(RoadPointer newCurrentRoad);
};

typedef QSharedPointer<Vehicle> VehiclePointer;

#endif // VEHICLE_H

namespace uuid {
    static std::random_device              rd;
    static std::mt19937                    gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    static std::uniform_int_distribution<> dis2(8, 11);

    std::string generate_uuid_v4() {
        std::stringstream ss;
        int i;
        ss << std::hex;
        for (i = 0; i < 8; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 4; i++) {
            ss << dis(gen);
        }
        ss << "-4";
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        ss << dis2(gen);
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 12; i++) {
            ss << dis(gen);
        };
        return ss.str();
    }
}
