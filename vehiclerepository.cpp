#include "vehiclerepository.h"

void VehicleRepository::removeVehicle(QUuid id)
{
    for (auto &vehicle: getAll()) {
        if (vehicle.get()->getId() == id) {
            objects.removeAt(getAll().indexOf(vehicle));
            delete vehicle.get();
            return;
        }
    }
}
