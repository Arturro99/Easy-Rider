#include "car.h"

#include <QDebug>
#include <QTime>
#include <QCoreApplication>

void Car::drive() {
    for (int i = 0; i < 200; i++) {
        setCurrentCoordinates(new int[] {++getCurrentCoordinates()[0], ++getCurrentCoordinates()[1]});
        QTime dieTime= QTime::currentTime().addMSecs(500);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
