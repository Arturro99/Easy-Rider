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
            Direction randomDirection = LEFT;
            while (randomDirection == LEFT) {
                randomDirection = static_cast<Direction>(RandGenerator::generate(0, 3));
            }

            VehiclePointer car = *new VehiclePointer(new Car(randomDirection, roadRepository));
            int randomRoad;

            if (randomDirection == RIGHT) {
                randomRoad = RandGenerator::generate(0, roadRepository->getSpawningHorizontalRoads().length() - 1);
                car->setCurrentCoordinates(new int[] {roadRepository->getSpawningHorizontalRoads().at(randomRoad)->getStartCoordinates()[0],
                            roadRepository->getSpawningHorizontalRoads().at(randomRoad)->getStartCoordinates()[1]});
            } else if (randomDirection == UP) {
                randomRoad = RandGenerator::generate(0, roadRepository->getSpawningVerticalUpRoads().length() - 1);
                car->setCurrentCoordinates(new int[] {roadRepository->getSpawningVerticalUpRoads().at(randomRoad)->getStartCoordinates()[0],
                            roadRepository->getSpawningVerticalUpRoads().at(randomRoad)->getEndCoordinates()[1]});
            } else if (randomDirection == DOWN) {
                randomRoad = RandGenerator::generate(0, roadRepository->getSpawningVerticalDownRoads().length() - 1);
                car->setCurrentCoordinates(new int[] {roadRepository->getSpawningVerticalDownRoads().at(randomRoad)->getStartCoordinates()[0],
                            roadRepository->getSpawningVerticalDownRoads().at(randomRoad)->getStartCoordinates()[1]});
            }
            car->setCurrentRoad(roadRepository->findByCoordinates(car->getCurrentCoordinates(), car->getCurrentDirection()));
            VehicleRepository::addVehicle(car);
            DriveThread thread(car);
            manager.start(car);
        }
    }
}

void DriveThreadCreator::setRoadRepository(RoadRepositoryPointer newRoadRepository)
{
    roadRepository = newRoadRepository;
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
