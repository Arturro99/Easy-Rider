#include "drivethreadcreator.h"

#include <windows.h>

int DriveThreadCreator::getThreadsNumber() const
{
    return threadsNumber;
}

void DriveThreadCreator::setRunning(bool newRunning)
{
    running = newRunning;
}

void DriveThreadCreator::run()
{
    while(1) {
        for (int i = VehicleRepository::getVehicles().size(); i < threadsNumber; i++) {
            QVector<VehiclePointer> cars;
//            for (int i = 0; i < 3; i++) {
                Direction randomDirection = LEFT;
                while (randomDirection == LEFT) {
                    randomDirection = static_cast<Direction>(RandGenerator::generate(0, 3));
                }

                VehiclePointer car = *new VehiclePointer(new Car(randomDirection));
                int randomRoad;

                if (randomDirection == RIGHT) {
                    randomRoad = RandGenerator::generate(0, RoadRepository::getSpawningHorizontalRoads().length() - 1);
                    car->setCurrentCoordinates(new int[] {RoadRepository::getSpawningHorizontalRoads().at(randomRoad)->getStartCoordinates()[0],
                                RoadRepository::getSpawningHorizontalRoads().at(randomRoad)->getStartCoordinates()[1]});
                } else if (randomDirection == UP) {
                    randomRoad = RandGenerator::generate(0, RoadRepository::getSpawningVerticalUpRoads().length() - 1);
                    car->setCurrentCoordinates(new int[] {RoadRepository::getSpawningVerticalUpRoads().at(randomRoad)->getStartCoordinates()[0],
                                RoadRepository::getSpawningVerticalUpRoads().at(randomRoad)->getEndCoordinates()[1]});
                } else if (randomDirection == DOWN) {
                    randomRoad = RandGenerator::generate(0, RoadRepository::getSpawningVerticalDownRoads().length() - 1);
                    car->setCurrentCoordinates(new int[] {RoadRepository::getSpawningVerticalDownRoads().at(randomRoad)->getStartCoordinates()[0],
                                RoadRepository::getSpawningVerticalDownRoads().at(randomRoad)->getStartCoordinates()[1]});
                }
                car->setCurrentRoad(RoadRepository::findByCoordinates(car->getCurrentCoordinates(), car->getCurrentDirection()));
                VehicleRepository::addVehicle(car);
                cars.append(car);
//            }
//            DriveThread thread(cars);
            manager.start(car);
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
