#include "drivethreadcreator.h"

#include <windows.h>

int DriveThreadCreator::getThreadsNumber() const
{
    return threadsNumber;
}

void DriveThreadCreator::run()
{
    while(1) {
        for (int i = VehicleRepository::getAll().size(); i < threadsNumber; i++) {
            QVector<VehiclePointer> vehicles;
            Direction randomDirection = LEFT;
            while (randomDirection == LEFT) {
                randomDirection = static_cast<Direction>(RandGenerator::generate(0, 3));
            }

            int randomInt = RandGenerator::generate(0, 1);
            VehiclePointer vehicle;
            randomInt == 0 ?
                        vehicle = *new VehiclePointer(new Car(randomDirection)) :
                        vehicle = *new VehiclePointer(new Bicycle(randomDirection));
            int randomRoad;

            if (randomDirection == RIGHT) {
                randomRoad = RandGenerator::generate(0, RoadRepository::getSpawningHorizontalRoads().length() - 1);
                vehicle->setCurrentCoordinates(new int[] {RoadRepository::getSpawningHorizontalRoads().at(randomRoad)->getStartCoordinates()[0],
                            RoadRepository::getSpawningHorizontalRoads().at(randomRoad)->getStartCoordinates()[1]});
            } else if (randomDirection == UP) {
                randomRoad = RandGenerator::generate(0, RoadRepository::getSpawningVerticalUpRoads().length() - 1);
                vehicle->setCurrentCoordinates(new int[] {RoadRepository::getSpawningVerticalUpRoads().at(randomRoad)->getStartCoordinates()[0],
                            RoadRepository::getSpawningVerticalUpRoads().at(randomRoad)->getEndCoordinates()[1]});
            } else if (randomDirection == DOWN) {
                randomRoad = RandGenerator::generate(0, RoadRepository::getSpawningVerticalDownRoads().length() - 1);
                vehicle->setCurrentCoordinates(new int[] {RoadRepository::getSpawningVerticalDownRoads().at(randomRoad)->getStartCoordinates()[0],
                            RoadRepository::getSpawningVerticalDownRoads().at(randomRoad)->getStartCoordinates()[1]});
            }
            vehicle->setCurrentRoad(RoadRepository::findByCoordinates(vehicle->getCurrentCoordinates(), vehicle->getCurrentDirection()));
            VehicleRepository::addObject(vehicle);
            vehicles.append(vehicle);
            manager.start(vehicle);
        }
    }
}

void DriveThreadCreator::setManager(ThreadManager &newManager)
{
    manager = newManager;
}

void DriveThreadCreator::addThread()
{
    this->threadsNumber++;
}

void DriveThreadCreator::removeThread()
{
    this->threadsNumber--;
}
