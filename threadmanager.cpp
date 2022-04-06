#include "threadmanager.h"
#include <QDebug>
#include <QTimer>

ThreadManager::ThreadManager(QObject *parent)
    : QObject{parent}
{
    QThreadPool::globalInstance()->setMaxThreadCount(QThread::idealThreadCount());
}

void ThreadManager::start(VehiclePointer vehicle)
{
    DriveThread *thread = new DriveThread(vehicle);
    thread->setAutoDelete(true);

    connect(thread, &DriveThread::finished, this, &ThreadManager::finished, Qt::QueuedConnection);

    QThreadPool::globalInstance()->start(thread);
}

void ThreadManager::finished()
{
    DriveThread* thread = qobject_cast<DriveThread*>(sender());
    if(!thread) return;
    delete thread;
}
