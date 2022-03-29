#include "mainwindow.h"
#include "drivethreadcreatorservice.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RoadRepositoryPointer roadRepository = RoadRepositoryPointer(new RoadRepository());


    ThreadManager manager;
//    DriveThreadCreator threadCreator(roadRepository, manager);
    DriveThreadCreator *threadCreator = new DriveThreadCreator();
    threadCreator->setManager(manager);
    threadCreator->setRoadRepository(roadRepository);

    MainWindow w(roadRepository, threadCreator);
    w.show();

    DriveThreadCreatorService service(threadCreator);
    service.run();
    return a.exec();
}
