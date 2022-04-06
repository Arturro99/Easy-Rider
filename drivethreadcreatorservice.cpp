#include "drivethreadcreatorservice.h"

DriveThreadCreatorService::DriveThreadCreatorService(DriveThreadCreator *threadCreator, QObject *parent) {
    this->thread = new QThread(this);
    this->threadCreator = threadCreator;
    threadCreator->moveToThread(thread);

    connect(this, &DriveThreadCreatorService::run, threadCreator, &DriveThreadCreator::run);
    connect(thread, &QThread::finished, threadCreator, &QObject::deleteLater);
    thread->start();
}
