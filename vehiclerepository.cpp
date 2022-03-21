#include "vehiclerepository.h"

VehicleRepository::VehicleRepository()
{

}

void VehicleRepository::addVehicle(VehiclePointer vehicle)
{
    this->vehiclesOnRoads.append(vehicle);
}

void VehicleRepository::removeVehicle(QUuid id)
{
    for (auto vehicle: vehiclesOnRoads) {
        if (vehicle.get()->getId() == id) {
            this->vehiclesOnRoads.removeAt(this->vehiclesOnRoads.indexOf(vehicle));
            delete vehicle.get();
            return;
        }
    }
}

const QVector<VehiclePointer> VehicleRepository::getVehicles()
{
    return vehiclesOnRoads;
}
