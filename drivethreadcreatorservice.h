#ifndef DRIVETHREADCREATORSERVICE_H
#define DRIVETHREADCREATORSERVICE_H

#include <QObject>

#include "drivethreadcreator.h"

/**
 * @brief Klasa DriveThreadCreatorService odpowiedzialna za powołanie wątku DriveThreadCreator
 */
class DriveThreadCreatorService : public QObject
{
    Q_OBJECT
private:
    /**
     * @brief thread - Atrybut przechowujący tworzony wątek
     */
    QThread *thread;
    /**
     * @brief threadCreator - Atrybut przechowujący instancję DriveThreadCreator
     *
     * Instancja będzie wykonywała swoje zadania w nowo utworzonym wątku
     */
    DriveThreadCreator *threadCreator;

public:
    /**
     * @brief Konstruktor klasy DriveThreadCreatorService
     * @param threadCreator - instancja klasy DriveThreadCreator
     * @param parent - rodzic dla instancji klasy QObject
     *
     * Konstruktor tworzy nowy wątek oraz przenosi do niego operacje instancji DriveThreadCreator.
     * Ponadto łączy ze sobą odpowiednio sloty i sygnały atrybutów thread i threadCreator celem
     * działania wątku w tle aplikacji
     */
    explicit DriveThreadCreatorService(DriveThreadCreator *threadCreator, QObject *parent = nullptr);
    ~DriveThreadCreatorService() {
        thread->quit();
        thread->wait();
    }

signals:
    /**
     * @brief Sygnał run
     *
     * Sygnał, który po wywołaniu spowoduje wykonanie analogicznej metody przez threadCreator
     */
    void run();
};

#endif // DRIVETHREADCREATORSERVICE_H
