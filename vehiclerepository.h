#ifndef VEHICLEREPOSITORY_H
#define VEHICLEREPOSITORY_H

#include "vehicle.h"

/**
 * @brief Klasa VehicleRepository reprezentująca repozytorium pojazdów
 */
class VehicleRepository : public Repository<VehiclePointer>
{
public:
    /**
     * @brief Metoda usuwająca pojazd z repozytorium
     * @param id - Identyfikator pojazdu
     */
    static void removeVehicle(QUuid id);
};

#endif // VEHICLEREPOSITORY_H
