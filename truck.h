#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"



class Truck : Vehicle
{
public:
    explicit Truck(Direction initialDirection, RoadRepositoryPointer roadRepository);
    virtual void drive(Direction direction) {

    }
};

#endif // TRUCK_H
