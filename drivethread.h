#ifndef DRIVETHREAD_H
#define DRIVETHREAD_H

#include <QThread>
#include <QRunnable>
#include <QObject>

#include "vehicle.h"

/**
 * @brief Klasa DriveThread reprezentująca wątek pojazdu w aplikacji
 *
 * Zadaniem klasy jest zarządzanie wątkiem przypisanym do każdej instancji typu Vehicle
 */
class DriveThread : public QObject, public QRunnable
{
    Q_OBJECT
private:
    /**
     * @brief vehicle - Atrybut przechowujący instancję pojazdu
     */
    VehiclePointer vehicle;
public:
    /**
     * @brief Konstruktor klasy DriveThread
     * @param vehicle - pojazd przypisany do wątku
     * @param parent - rodzic dla instancji klasy QObject
     *
     * Konstruktor tworzy instancję klasy DriveThread oraz przypisuje jej odpowiedni pojazd
     */
    explicit DriveThread(VehiclePointer vehicle, QObject *parent=nullptr);
    ~DriveThread();

signals:
    /**
     * @brief Sygnał finished
     *
     * Sygnał emitowany w przypadku zakończenia pracy przez wątek
     */
    void finished();

public:
    /**
     * @brief Metoda run wątku
     *
     * Metoda nadpisująca metodę klasy QRunnable. Jej celem jest zdefiniowanie czynności,
     * jakie wątke powinien wykonać
     */
    void run() Q_DECL_OVERRIDE;
    /**
     * @brief Metoda pobierająca pojazd
     * @return Pojazd przypisany do wątku
     */
    VehiclePointer getVehicle() const;
};

#endif // DRIVETHREAD_H
