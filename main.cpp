#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(0));
    QApplication a(argc, argv);
    RoadRepositoryPointer roadRepository = RoadRepositoryPointer(new RoadRepository());
    VehiclePointer car = VehiclePointer(new Car(RIGHT, roadRepository));
    MainWindow w(car, roadRepository);
    w.show();
    DriveThread thread(car);
    thread.run();
    return a.exec();
}
