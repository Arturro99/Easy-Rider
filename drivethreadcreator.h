#ifndef DRIVETHREADCREATOR_H
#define DRIVETHREADCREATOR_H

#include <QRunnable>
#include <QThread>

#include "roadrepository.h"
#include "vehiclerepository.h"
#include "threadmanager.h"
#include "car.h"


class DriveThreadCreator : public QObject {
    Q_OBJECT

private:
    RoadRepositoryPointer roadRepository;
    ThreadManager manager;
    int threadsNumber = QThread::idealThreadCount() / 2;
    bool running = true;

public:
    DriveThreadCreator() {};
    DriveThreadCreator(DriveThreadCreator& threadCreator) {
            this->roadRepository = threadCreator.roadRepository;
            this->manager = threadCreator.manager;
            this->threadsNumber = threadCreator.threadsNumber;
    };
    DriveThreadCreator operator=(DriveThreadCreator& threadCreator) {
        this->roadRepository = threadCreator.roadRepository;
        this->manager = threadCreator.manager;
        this->threadsNumber = threadCreator.threadsNumber;
        return *this;
    };
    explicit DriveThreadCreator(RoadRepositoryPointer rr, ThreadManager tm) : roadRepository(rr), manager(tm) {};
    void addThread();
    void removeThread();
    int getThreadsNumber() const;
    void setRunning(bool newRunning);

    void setRoadRepository(RoadRepositoryPointer newRoadRepository);

    void setManager(ThreadManager &newManager);

public slots:
    void run();

};

#endif // DRIVETHREADCREATOR_H
