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
    for (int i = 0; i < 1; i++) {
        DriveThread *thread = new DriveThread(vehicle);
        thread->setAutoDelete(true);

        connect(thread, &DriveThread::started, this, &ThreadManager::started, Qt::QueuedConnection);
        connect(thread, &DriveThread::finished, this, &ThreadManager::finished, Qt::QueuedConnection);
        connect(this, &ThreadManager::work, thread, &DriveThread::work, Qt::QueuedConnection);

        QThreadPool::globalInstance()->start(thread);
    }
}

void ThreadManager::started()
{
    DriveThread* thread = qobject_cast<DriveThread*>(sender());
    if(!thread) return;

}

void ThreadManager::finished()
{
    DriveThread* thread = qobject_cast<DriveThread*>(sender());
    if(!thread) return;
    delete thread;
}
