#include "mainwindow.h"
#include "drivethreadcreator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RoadRepositoryPointer roadRepository = RoadRepositoryPointer(new RoadRepository());
    VehicleRepositoryPointer vehicleRepository = VehicleRepositoryPointer(new VehicleRepository());



    MainWindow w(roadRepository, vehicleRepository);
    w.show();

    ThreadManager manager(vehicleRepository);
    DriveThreadCreator thread(roadRepository, vehicleRepository, manager);
    thread.run();
    thread.setAutoDelete(true);

    return a.exec();
}
