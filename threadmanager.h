#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QThreadPool>

#include "drivethread.h"
#include "vehiclerepository.h"

/**
 * @brief Klasa ThreadManager
 *
 * Klasa odpowiedzialna za zarządzanie cyklem życia wątku zarządzającego pojazdem
 */
class ThreadManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor kopiujący klasy ThreadManager
     * @param tm - Obiekt kopiowany
     */
    ThreadManager(ThreadManager& tm) {};
    /**
     * @brief Przeciążenie operatora przypisania
     * @return Nowy obiekt typu ThreadManager
     */
    ThreadManager& operator=(ThreadManager&) {
        return *this;
    };
    /**
     * @brief Konstruktor klasy ThreadManager
     * @param parent - Rodzic instancji klasy QObject
     *
     * Konstruktor ustawia maksyalną liczbę wątków aplikacji na idealną liczbę wątków
     * możliwych do powołania przez system
     */
    explicit ThreadManager(QObject *parent = nullptr);

public slots:
    /**
     * @brief Slot start
     * @param vehicle - Pojazd, który zostanie umieszczony w wątku
     *
     * Metoda tworzy nowy wątek przekazując do niego zarządzanie odpowiednim pojazdem, po czym
     * uruchamia utworzony wątek
     */
    void start(VehiclePointer vehicle);
    /**
     * @brief Slot finished
     *
     * Metoda po uruchomieniu usuwa dany wątek
     */
    void finished();

};

#endif // THREADMANAGER_H
