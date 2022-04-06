#ifndef DRIVETHREADCREATOR_H
#define DRIVETHREADCREATOR_H

#include <QRunnable>
#include <QThread>

#include "roadrepository.h"
#include "vehiclerepository.h"
#include "threadmanager.h"
#include "car.h"
#include "bicycle.h"

/**
 * @brief Klasa DriveThreadCreator reprezentująca obiekt tworzący wątki
 *
 * Klasa odpowiedzialna jest za tworzenie nowych wątków typu DriveThread w przypadku,
 * gdy istniejące zostaną zniszczone lub aktualna pula wątków jest większa niż
 * ich obecna ilość w aplikacji
 */
class DriveThreadCreator : public QObject {
    Q_OBJECT

private:
    /**
     * @brief manager - Atrybut przechowujący instancję menedżera wyjątków
     */
    ThreadManager manager;
    /**
     * @brief threadsNumber - Atrybut przechowujący docelową ilość wątków
     *
     * Atrybut jest zainicjowany wartością domyślną - połową idealnej liczby wątków
     * możliwych do powołania przez system
     */
    int threadsNumber = QThread::idealThreadCount() / 2;

public:
    /**
     * @brief Domyślny konstruktor klasy DriveThreadCreator
     */
    DriveThreadCreator() {};
    /**
     * @brief Konstruktor kopiujący klasy DriveThreadCreator
     * @param threadCreator - obiekt kopiowany
     */
    DriveThreadCreator(DriveThreadCreator& threadCreator) {
            this->manager = threadCreator.manager;
            this->threadsNumber = threadCreator.threadsNumber;
    };
    /**
     * @brief Przeciążenie operatora przypisania
     * @param threadCreator - obiekt służący do przypisania
     * @return Nowy obiekt typu DriveThreadCreator
     */
    DriveThreadCreator operator=(DriveThreadCreator& threadCreator) {
        this->manager = threadCreator.manager;
        this->threadsNumber = threadCreator.threadsNumber;
        return *this;
    };
    /**
     * @brief Konstruktor klasy DriveThreadCreator z menadżerem wątków
     * @param tm - menadżer wątków
     */
    explicit DriveThreadCreator(ThreadManager tm) : manager(tm) {};
    /**
     * @brief Metoda inkrementująca liczbę wątków
     */
    void addThread();
    /**
     * @brief Metoda dekrementująca liczbę wątków
     */
    void removeThread();
    /**
     * @brief Metoda zwracająca maksymalną liczbę wątków
     * @return Maksymalna liczba wątków
     */
    int getThreadsNumber() const;
    /**
     * @brief Metoda ustawiająca menadżera wątków
     * @param newManager - menadżer wątków
     */
    void setManager(ThreadManager &newManager);

public slots:
    /**
     * @brief Metoda definiująca akcje wykonywane przez instancję klasy
     *
     * Metoda odpowiedzialna jest za wykonywanie sekwencji operacji prowadzących
     * do utworzenia nowego pojazdu, wątku DriveThread, przypisania niezbędnych atrybutów
     * oraz uruchomienia utworzonego wątku.
     * Wywołanie metody następuje w tle przez instancję DriveThreadCreatorService
     */
    void run();

};

#endif // DRIVETHREADCREATOR_H
