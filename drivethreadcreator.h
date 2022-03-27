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
    ThreadManager manager;
public:
    explicit DriveThreadCreator(RoadRepositoryPointer rr, ThreadManager tm) : roadRepository(rr), manager(tm) {};
    void run();
};

#endif // DRIVETHREADCREATOR_H
