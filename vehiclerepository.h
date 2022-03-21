#ifndef VEHICLEREPOSITORY_H
#define VEHICLEREPOSITORY_H

#include "vehicle.h"

class VehicleRepository
{
private:
    QVector<VehiclePointer> vehiclesOnRoads;
public:
    VehicleRepository();

    void addVehicle(VehiclePointer vehicle);
    void removeVehicle(QUuid id);
    const QVector<VehiclePointer> getVehicles();
};

#endif // VEHICLEREPOSITORY_H

typedef QSharedPointer<VehicleRepository> VehicleRepositoryPointer;
