#include "mainwindow.h"
#include "drivethreadcreatorservice.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ThreadManager manager;
    DriveThreadCreator *threadCreator = new DriveThreadCreator();
    threadCreator->setManager(manager);

    MainWindow w(threadCreator);
    w.show();

    DriveThreadCreatorService service(threadCreator);
    service.run();
    return a.exec();
}
