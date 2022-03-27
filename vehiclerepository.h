#ifndef VEHICLEREPOSITORY_H
#define VEHICLEREPOSITORY_H

#include "vehicle.h"

class VehicleRepository
{
private:
    inline static QVector<VehiclePointer> vehiclesOnRoads;
public:

    static void addVehicle(VehiclePointer vehicle);
    static void removeVehicle(QUuid id);
    static const QVector<VehiclePointer> getVehicles();
};

#endif // VEHICLEREPOSITORY_H

typedef QSharedPointer<VehicleRepository> VehicleRepositoryPointer;
