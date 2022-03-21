#include "threadmanager.h"
#include <QDebug>

ThreadManager::ThreadManager(VehicleRepositoryPointer vehicleRepository, QObject *parent)
    : QObject{parent}
{
    this->vehicleRepository = vehicleRepository;
}

void ThreadManager::start(VehiclePointer vehicle)
{
    for (int i = 0; i < 1; i++) {
        DriveThread *thread = new DriveThread(vehicle);
        thread->setAutoDelete(true);

        connect(thread, &DriveThread::started, this, &ThreadManager::started, Qt::QueuedConnection);
        connect(thread, &DriveThread::finished, this, &ThreadManager::finished, Qt::QueuedConnection);
        connect(this, &ThreadManager::work, thread, &DriveThread::work, Qt::QueuedConnection);
//        connect(vehicle.get(), &Vehicle::finished, thread, &DriveThread::finish, Qt::QueuedConnection);

        QThreadPool::globalInstance()->start(thread);
    }
}

void ThreadManager::started()
{
    DriveThread* thread = qobject_cast<DriveThread*>(sender());
    if(!thread) return;

}

void ThreadManager::finished()
{
    DriveThread* thread = qobject_cast<DriveThread*>(sender());
    if(!thread) return;

    vehicleRepository->removeVehicle(thread->getVehicle()->getId());
    delete thread;
}
