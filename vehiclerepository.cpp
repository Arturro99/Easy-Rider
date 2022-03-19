#include "vehiclerepository.h"

VehicleRepository::VehicleRepository()
{

}

void VehicleRepository::addVehicle(VehiclePointer vehicle)
{
    this->vehiclesOnRoads.append(vehicle);
}

void VehicleRepository::removeVehicle(std::string id)
{
    for (auto vehicle: vehiclesOnRoads) {
        if (vehicle.get()->getId().compare(id) == 0) {
            this->vehiclesOnRoads.removeAt(this->vehiclesOnRoads.indexOf(vehicle));
            delete vehicle.get();
            return;
        }
    }
}
