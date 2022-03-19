#ifndef BICYCLE_H
#define BICYCLE_H

#include "vehicle.h"



class Bicycle : Vehicle
{
public:
    explicit Bicycle(Direction initialDirection);
    virtual void drive(Direction direction) {

    }
};

#endif // BICYCLE_H
