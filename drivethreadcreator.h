#ifndef DRIVETHREADCREATOR_H
#define DRIVETHREADCREATOR_H

#include <QRunnable>

#include "roadrepository.h"
#include "vehiclerepository.h"
#include "threadmanager.h"
#include "car.h"


class DriveThreadCreator : public QRunnable {
private:
    RoadRepositoryPointer roadRepository;
    VehicleRepositoryPointer vehicleRepository;
    ThreadManager manager;
public:
    explicit DriveThreadCreator(RoadRepositoryPointer rr, VehicleRepositoryPointer vr, ThreadManager tm) : roadRepository(rr), vehicleRepository(vr), manager(tm) {};
    void run();
};

#endif // DRIVETHREADCREATOR_H
