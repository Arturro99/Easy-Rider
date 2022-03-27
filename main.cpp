#include "mainwindow.h"
#include "drivethreadcreator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RoadRepositoryPointer roadRepository = RoadRepositoryPointer(new RoadRepository());



    MainWindow w(roadRepository);
    w.show();

    ThreadManager manager;
    DriveThreadCreator thread(roadRepository, manager);
    thread.run();
    thread.setAutoDelete(true);

    return a.exec();
}
