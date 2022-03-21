#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RoadRepositoryPointer roadRepository = RoadRepositoryPointer(new RoadRepository());
    VehicleRepositoryPointer vehicleRepository = VehicleRepositoryPointer(new VehicleRepository());



    MainWindow w(roadRepository, vehicleRepository);
    w.show();

    return a.exec();
}
