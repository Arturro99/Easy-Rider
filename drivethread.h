#ifndef DRIVETHREAD_H
#define DRIVETHREAD_H

#include <QThread>
#include "vehicle.h"


class DriveThread : public QThread
{
private:
    VehiclePointer vehicle;
public:
    DriveThread(VehiclePointer vehicle);
    void run();

};

#endif // DRIVETHREAD_H
