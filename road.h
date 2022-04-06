#ifndef ROAD_H
#define ROAD_H

#include <QSharedPointer>
#include "sign.h"

/**
 * @brief Definicja Direction
 *
 * Typ wyliczeniowy przechowujący 4 wartości kierunku, w którym mogą poruszać się pojazdy
 */
typedef enum  {
    UP,
    LEFT,
    DOWN,
    RIGHT
} Direction;

/**
 * @brief Klasa Road
 *
 * Klasa odpowiedzialna za przechowywanie informacji oraz operacji związanych z drogą w aplikacji
 */
class Road
{
private:
    /**
     * @brief name - Nazwa drogi
     */
    std::string name;
    /**
     * @brief startCoordinates - Współrzędne początku drogi
     */
    int *startCoordinates;
    /**
     * @brief endCoordinates - Współrzędne końca drogi
     */
    int *endCoordinates;
    /**
     * @brief signs - Wektor znaków znajdujących się przy danej drodze
     */
    QVector<SignPointer> signs;

public:
    /**
     * @brief Domyślny konstruktor klasy Road
     */
    Road();
    /**
     * @brief Konstruktor klasy Road
     * @param startCoordinates - Współrzędne początku drogi
     * @param endCoordinates - Współrzędne końca drogi
     * @param name - Nazwa drogi
     *
     * Konstruktor ustawiający podstawowe atrybuty drogi
     */
    Road(int *startCoordinates, int *endCoordinates, std::string name);


    /**
     * @brief Metoda pobierająca współrzędne początku drogi
     * @return Tablica współrzędnych początku drogi
     */
    int *getStartCoordinates() const;
    /**
     * @brief Metoda ustawiająca współrzędna początku drogi
     * @param newStartCoordinates - Tablica współrzędnych początku drogi
     */
    void setStartCoordinates(int *newStartCoordinates);
    /**
     * @brief Metoda pobierająca współrzędne końca drogi
     * @return Tablica współrzędnych końca drogi
     */
    int *getEndCoordinates() const;
    /**
     * @brief Metoda ustawiająca współrzędna końca drogi
     * @param newEndCoordinates - Tablica współrzędnych końca drogi
     */
    void setEndCoordinates(int *newEndCoordinates);

    /**
     * @brief Przeciążenie operatora porównania
     * @param road1 - Pierwsza droga do porównania
     * @param road2 - Druga droga do porównania
     * @return true jeśli równe, w przeciwnym razie false
     *
     * Metoda wykorzystuje współrzędne początku i końca dróg do ich porównania
     */
    friend bool operator==(const Road& road1, const Road& road2) {
        return (road1.getStartCoordinates()[0] == road2.getStartCoordinates()[0] &&
            road1.getStartCoordinates()[1] == road2.getStartCoordinates()[1] &&
            road1.getEndCoordinates()[0] == road2.getEndCoordinates()[0] &&
            road1.getEndCoordinates()[1] == road2.getEndCoordinates()[1]);
    }
    /**
     * @brief Metoda pobierająca wektor znaków
     * @return Wektor znaków
     */
    const QVector<SignPointer> &getSigns() const;
    /**
     * @brief Metoda dodająca znak do wektora
     * @param sign - Znak do dodania
     */
    void addSign(SignPointer sign);
    /**
     * @brief Metoda ustawiająca wektor znaków
     * @param newSigns - Wektor znaków do ustawienia
     */
    void setSigns(const QVector<SignPointer> &newSigns);
    /**
     * @brief Metoda pobierająca nazwę drogi
     * @return Nazwa drogi
     */
    const std::string &getName() const;

};

/**
 * @brief Definicja RoadPointer
 *
 * Definicja typu RoadPointer tworząca współdzielony wskaźnik drogi
 */
typedef QSharedPointer<Road> RoadPointer;

#endif // ROAD_H
