#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QThreadPool>

#include "drivethread.h"
#include "vehiclerepository.h"

class ThreadManager : public QObject
{
    Q_OBJECT
private:
    VehicleRepositoryPointer vehicleRepository;
public:
    ThreadManager(ThreadManager& tm) {
        this->vehicleRepository = tm.vehicleRepository;
    };
    explicit ThreadManager(VehicleRepositoryPointer vehicleRepository, QObject *parent = nullptr);

signals:
    void work();

public slots:
    void start(VehiclePointer vehicle);
    void started();
    void finished();

};

#endif // THREADMANAGER_H
