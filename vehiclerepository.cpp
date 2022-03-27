#include "vehiclerepository.h"

void VehicleRepository::addVehicle(VehiclePointer vehicle)
{
    vehiclesOnRoads.append(vehicle);
}

void VehicleRepository::removeVehicle(QUuid id)
{
    for (auto vehicle: vehiclesOnRoads) {
        if (vehicle.get()->getId() == id) {
            vehiclesOnRoads.removeAt(vehiclesOnRoads.indexOf(vehicle));
            delete vehicle.get();
            return;
        }
    }
}

const QVector<VehiclePointer> VehicleRepository::getVehicles()
{
    return vehiclesOnRoads;
}
