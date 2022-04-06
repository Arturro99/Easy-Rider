#ifndef VEHICLE_H
#define VEHICLE_H

#include <QImage>
#include <QSharedPointer>
#include <sstream>
#include <QUuid>
#include <QDebug>
#include "roadrepository.h"
#include "randgenerator.h"

/**
 * @brief Klasa Vehicle reprezentująca pojazd w aplikacji
 */
class Vehicle : public QObject
{
    Q_OBJECT
private:
    /**
     * @brief Metoda sprawdzająca otoczenie pojazdu
     * @param coordinatesA - Współrzędne sprawdzanego pojazdu
     * @param coordinatesB - Współrzędne innego pojazdu
     * @param direction - Kierunek przemieszczania się pojazdu
     * @return True, gdy pojazdy znajdują się zbyt blisko siebie, w przeciwnym wypadku false
     *
     * Metoda wykorzystuje współrzędne dwóch pojazdów celem określenia, czy istnieje niebezpieczeństwo kolizji
     */
    bool isTooClose(int* coordinatesA, int* coordinatesB, Direction direction);
protected:
    /**
     * @brief waiting - Atrybut przechowujący informację o stanie oczekiwania pojazdu
     *
     * Atrybut domyślnie ustawiony jest na true. W przypadku, gdy pojazd zostanie zatrzymany
     * wskutek wykrycia innego pojazdu bądź odpowiedniego znaku wartość nie ulegnie zmianie.
     * W momencie, gdy pojazd porusza się wartość atrybutu wynosi false
     */
    bool waiting = true;
    /**
     * @brief image - Atrybut przechowujący obraz przypisany do pojazdu
     */
    QImage *image;
    /**
     * @brief id - Unikalny identyfikator pojazdu
     */
    QUuid id;
    /**
     * @brief currentCoordinates - Aktualne współrzędne pojazdu
     */
    int *currentCoordinates;
    /**
     * @brief currentRoad - Aktualna droga, po której porusza się pojazd
     */
    RoadPointer currentRoad = *new RoadPointer(new Road);
    /**
     * @brief currentDirection - Aktualny kierunek przemieszczania się pojazdu
     */
    Direction currentDirection;
    /**
     * @brief initialDirection - VehiclePointer
     */
    const Direction initialDirection;
    /**
     * @brief Konstruktor klasy Vehicle
     * @param initialDirection - Aktualny kierunek przemieszczania się pojazdu
     */
    explicit Vehicle(Direction initialDirection) : initialDirection(initialDirection) {};
    /**
     * @brief Metoda wykrywająca znak ustąpienia pierwszeństwa
     * @param vehicle - Aktualny pojazd
     * @return True, gdy wykryto znak, w przeciwnym wypadku false
     *
     * Metoda wykorzystuje aktualne współrzędne pojazdu, drogę, po której się przemieszcza celem określenia,
     * czy znak występuje na danej drodze. Jeśli tak - pojazd zatrzymuje się na pół sekundy na skraju skrzyżowania
     * przepuszczając jednocześnie inne pojazdy, jeżeli poruszają się one na drodze z pierwszeństwem przejazdu
     */
    bool giveWaySignDetected(Vehicle* vehicle);
    /**
     * @brief Metoda wykrywająca możliwość wystąpienia kolizji
     * @param vehicle - Aktualny pojazd
     * @return True, gdy wykryto możliwość kolizji, w przeciwnym wypadku false
     *
     * Metoda wykorzystuje metodę isTooClose() celem zbadania otoczenia. W przypadku wystąpienia
     * pojazdu znajdującego się zbyt blisko obecnego zostanie zwrócona wartość true
     */
    bool collisionDetected(Vehicle* vehicle);
public:
    /**
     * @brief Metoda pobierająca obraz pojazdu
     * @return Obraz pojazdu
     */
    QImage *getImage() const;
    /**
     * @brief Metoda ustawiająca obraz pojazdu
     * @param newImage - Nowy obraz pojazdu
     */
    void setImage(QImage *newImage);
    /**
     * @brief Metoda pobierająca aktualne współrzędne pojazdu
     * @return Aktualne współrzędne pojazdu
     */
    int *getCurrentCoordinates() const;
    /**
     * @brief Metoda ustawiająca aktualne współrzędne pojazdu
     * @param newCurrentCoordinates - Nowe współrzędne pojazdu
     */
    void setCurrentCoordinates(int *newCurrentCoordinates);
    /**
     * @brief Metoda pobierająca aktualny kierunek przemieszczania się pojazdu
     * @return Aktualny kierunek przemieszczania się pojazdu
     */
    Direction getCurrentDirection() const;
    /**
     * @brief Metoda ustawiająca aktualny kierunek przemieszczania się pojazdu
     * @param newCurrentDirection - Nowy kierunek przemieszczania się pojazdu
     */
    void setCurrentDirection(Direction newCurrentDirection);
    /**
     * @brief Metoda pobierająca początkowy kierunek przemieszczania się pojazdu
     * @return Początkowy kierunek przemieszczania się pojazdu
     */
    Direction getInitialDirection() const;
    /**
     * @brief Wirtualna metoda sterująca pojazdem
     */
    virtual void drive() = 0;
    /**
     * @brief Metoda obsługująca zatrzymanie się pojazdu
     *
     * Metoda zostaje wywoływana w momencie ykrycia kolizji bądź odpowiedniego znaku drogowego
     */
    void stop();
    /**
     * @brief Metoda obracająca pojazd
     * @param targetDirection - Docelowy kierunek przemieszczania się pojazdu
     *
     * Metoda zmienia kierunek przemiszczania się pojazdu aktualizując jednocześnie
     * jego obraz
     */
    void rotateVehicle(Direction targetDirection);
    /**
     * @brief Metoda losująca kierunek przemieszczania się pojazdu
     * @param currentDirection - Obecny kierunek
     * @return Docelowy kierunek
     */
    Direction randomDirection(Direction currentDirection);
    /**
     * @brief Metoda pobierająca aktualną drogę
     * @return Aktualna droga
     */
    RoadPointer getCurrentRoad() const;
    /**
     * @brief Metoda ustawiająca aktualną drogę
     * @param newCurrentRoad - Nowa droga, po której przemieszcza się pojazd
     */
    void setCurrentRoad(RoadPointer newCurrentRoad);
    /**
     * @brief Metoda pobierająca id pojazdu
     * @return Id pojazdu
     */
    const QUuid &getId() const;
    /**
     * @brief Metoda ustawiająca atrybut waiting pojazdu
     * @param newWaiting - Nowa wartość atrybutu
     */
    void setWaiting(bool newWaiting);
    /**
     * @brief Metoda pobierająca atrybut waiting pojazdu
     * @return Atrybut waiting
     */
    bool getWaiting() const;
};

/**
 * @brief Definicja VehiclePointer
 *
 * Definicja typu VehiclePointer tworząca współdzielony wskaźnik pojazdu
 */
typedef QSharedPointer<Vehicle> VehiclePointer;

#endif // VEHICLE_H
