#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VehiclePointer car = VehiclePointer(new Car(RIGHT));
    MainWindow w(car);
    w.show();
    DriveThread thread(car);
    thread.run();
    return a.exec();
}
