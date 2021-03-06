#include "drivethread.h"

VehiclePointer DriveThread::getVehicle() const
{
    return vehicle;
}

DriveThread::DriveThread(VehiclePointer vehicle, QObject *parent) : QObject(parent) {
    this->vehicle = vehicle;
}

DriveThread::~DriveThread()
{

}

void DriveThread::run()
{
    while (true) {
        this->vehicle->drive();
        this->vehicle->stop();
        if (!vehicle->getWaiting()) break;
    }
    this->vehicle->setImage(nullptr);
    emit finished();
}
