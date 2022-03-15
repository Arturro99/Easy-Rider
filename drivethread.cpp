#include "drivethread.h"

DriveThread::DriveThread(VehiclePointer vehicle) {
    this->vehicle = vehicle;
}

void DriveThread::run()
{
    this->vehicle->drive();
}
