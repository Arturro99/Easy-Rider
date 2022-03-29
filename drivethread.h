#ifndef DRIVETHREAD_H
#define DRIVETHREAD_H

#include <QThread>
#include <QRunnable>
#include <QObject>
#include "vehicle.h"


class DriveThread : public QObject, public QRunnable
{
    Q_OBJECT
private:
    VehiclePointer vehicle;
public:
    explicit DriveThread(VehiclePointer vehicle, QObject *parent=nullptr);
//    explicit DriveThread(QObject *parent=nullptr);
    ~DriveThread();

signals:
    void started();
    void finished();

public slots:
    void work();

public:
    void run() Q_DECL_OVERRIDE;



    VehiclePointer getVehicle() const;
};

#endif // DRIVETHREAD_H
