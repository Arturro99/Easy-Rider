#ifndef CAR_H
#define CAR_H

#include "vehicle.h"



class Car : public Vehicle
{
public:
    Car();
    virtual void drive(Direction direction) {

    }
};



#endif // CAR_H
