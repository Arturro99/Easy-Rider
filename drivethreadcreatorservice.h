#ifndef DRIVETHREADCREATORSERVICE_H
#define DRIVETHREADCREATORSERVICE_H

#include <QObject>

#include "drivethreadcreator.h"


class DriveThreadCreatorService : public QObject
{
    Q_OBJECT
private:
    QThread *thread;
    DriveThreadCreator *threadCreator;

public:
    explicit DriveThreadCreatorService(DriveThreadCreator *threadCreator, QObject *parent = nullptr);
    ~DriveThreadCreatorService() {
        thread->quit();
        thread->wait();
    }

signals:
    void run();
};

#endif // DRIVETHREADCREATORSERVICE_H
