#ifndef ROADREPOSITORY_H
#define ROADREPOSITORY_H

#include "road.h"

/**
 * @brief Klasa RoadRepository reprezentująca repozytorium dróg
 */
class RoadRepository : public Repository<RoadPointer>
{
private:
    /**
     * @brief horizontalRoads - Wektor przechowujący drogi poziome
     */
    inline static QVector<RoadPointer> horizontalRoads;
    /**
     * @brief horizontalRoads - Wektor przechowujący drogi pionowe
     */
    inline static QVector<RoadPointer> verticalRoads;
    /**
     * @brief horizontalRoads - Wektor przechowujący początkowe drogi z kierunkiem górnym
     */
    inline static QVector<RoadPointer> spawningVerticalUpRoads;
    /**
     * @brief horizontalRoads - Wektor przechowujący początkowe drogi z kierunkiem dolnym
     */
    inline static QVector<RoadPointer> spawningVerticalDownRoads;
    /**
     * @brief horizontalRoads - Wektor przechowujący początkowe drogi poziome
     */
    inline static QVector<RoadPointer> spawningHorizontalRoads;
    /**
     * @brief horizontalRoads - Wektor przechowujący końcowe drogi pionowe
     */
    inline static QVector<RoadPointer> endingVerticalRoads;
    /**
     * @brief horizontalRoads - Wektor przechowujący końcowe drogi poziome
     */
    inline static QVector<RoadPointer> endingHorizontalRoads;

    /**
     * @brief horizontalRoads - Wektor przechowujący drogi z kierunkiem dolnym
     */
    inline static QVector<RoadPointer> verticalDownRoads;
    /**
     * @brief horizontalRoads - Wektor przechowujący drogi z kierunkiem górnym
     */
    inline static QVector<RoadPointer> verticalUpRoads;
    /**
     * @brief horizontalRoads - Wektor przechowujący drogi z kierunkiem lewym
     */
    inline static QVector<RoadPointer> horizontalLeftRoads;
    /**
     * @brief horizontalRoads - Wektor przechowujący drogi z kierunkiem prawym
     */
    inline static QVector<RoadPointer> horizontalRightRoads;

public:
    /**
     * @brief Metoda wyszukująca drogę po współrzędnych
     * @param startCoordinates - Współrzęde początku drogi
     * @param currentDirection - Kierunek poruszania się pojazdu przemieszczającego się po danej drodze
     * @return Szukana droga
     */
    static RoadPointer findByCoordinates(int* startCoordinates, Direction currentDirection);
    /**
     * @brief Metoda wyszukująca drogę po jej numerze i kierunku
     * @param number - Numer drogi
     * @param direction - Kierunek drogi
     * @return Szukana droga
     */
    static RoadPointer findByNumberAndDirection(std::string number, Direction direction);
    /**
     * @brief Metoda wyłuskująca numer drogi z jej nazwy
     * @param direction - Kierunek drogi
     * @param name - Nazwa drogi
     * @return Numer drogi
     */
    static std::string extractNumber(Direction direction, std::string name);
    /**
     * @brief Metoda dodająca drogi do repozytorium
     * @param road - Drogi dodawane do repozytorium
     */
    static void addRoads(QVector<RoadPointer> roads);
    /**
     * @brief Metoda przypisująca znak do drogi
     * @param road - Dana droga
     * @param sign - Przypisywany znak
     * @param direction - Kierunek drogi
     */
    static void assignSignToRoad(RoadPointer road, SignPointer sign, Direction direction);


    /**
     * @brief Metoda zwracająca drogi pionowe
     * @return Drogi pionowe
     */
    static const QVector<RoadPointer> &getVerticalRoads();
    /**
     * @brief Metoda zwracająca drogę pionową po indeksie
     * @param i - Indeks
     * @return Droga pionowa
     */
    static const RoadPointer &getVerticalRoad(int i);
    /**
     * @brief Metoda zwracająca drogi poziome
     * @return Drogi poziome
     */
    static const QVector<RoadPointer> &getHorizontalRoads();
    /**
     * @brief Metoda zwracająca drogę poziomą po indeksie
     * @param i - Indeks
     * @return Droga pozioma
     */
    static const RoadPointer &getHorizontalRoad(int i);
    /**
     * @brief Metoda dodająca drogę pionową do repozytorium
     * @param road - Nowa droga
     */
    static void addVerticalRoad(RoadPointer road);
    /**
     * @brief Metoda dodająca drogę poziomą do repozytorium
     * @param road - Nowa droga
     */
    static void addHorizontalRoad(RoadPointer road);
    /**
     * @brief Metoda zwracająca drogi początkowe z kierunkiem górnym
     * @return Drogi
     */
    static const QVector<RoadPointer> &getSpawningVerticalUpRoads();
    /**
     * @brief Metoda zwracająca drogi początkowe z kierunkiem dolnym
     * @return Drogi
     */
    static const QVector<RoadPointer> &getSpawningVerticalDownRoads();
    /**
     * @brief Metoda zwracająca drogi początkowe poziome
     * @return Drogi
     */
    static const QVector<RoadPointer> &getSpawningHorizontalRoads();
    /**
     * @brief Metoda zwracająca drogi końcowe pionowe
     * @return Drogi
     */
    static const QVector<RoadPointer> &getEndingVerticalRoads();
    /**
     * @brief Metoda zwracająca drogi końcowe poziome
     * @return Drogi
     */
    static const QVector<RoadPointer> &getEndingHorizontalRoads();
    /**
     * @brief Metoda dodająca drogę początkową z kierunkiem górnym
     * @param road - Nowa droga
     */
    static void addSpawningVerticalUpRoad(RoadPointer road);
    /**
     * @brief Metoda dodająca drogę początkową z kierunkiem dolnym
     * @param road - Nowa droga
     */
    static void addSpawningVerticalDownRoad(RoadPointer road);
    /**
     * @brief Metoda dodająca drogę początkową poziomą
     * @param road - Nowa droga
     */
    static void addSpawningHorizontalRoad(RoadPointer road);
    /**
     * @brief Metoda dodająca drogę końcową pionową
     * @param road - Nowa droga
     */
    static void addEndingVerticalRoad(RoadPointer road);
    /**
     * @brief Metoda dodająca drogę końcową poziomą
     * @param road - Nowa droga
     */
    static void addEndingHorizontalRoad(RoadPointer road);
    /**
     * @brief Metoda zwracająca drogi z kierunkiem dolnym
     * @return Drogi
     */
    static const QVector<RoadPointer> &getVerticalDownRoads();
    /**
     * @brief Metoda zwracająca drogi z kierunkiem górnym
     * @return Drogi
     */
    static const QVector<RoadPointer> &getVerticalUpRoads();
    /**
     * @brief Metoda zwracająca drogi z kierunkiem lewym
     * @return Drogi
     */
    static const QVector<RoadPointer> &getHorizontalLeftRoads();
    /**
     * @brief Metoda zwracająca drogi z kierunkiem prawym
     * @return Drogi
     */
    static const QVector<RoadPointer> &getHorizontalRightRoads();
    /**
     * @brief Metoda dodająca drogę z kierunkiem dolnym
     * @param verticalDownRoad - Nowa droga
     */
    static void addVerticalDownRoad(RoadPointer verticalDownRoad);
    /**
     * @brief Metoda dodająca drogę z kierunkiem górnym
     * @param verticalDownRoad - Nowa droga
     */
    static void addVerticalUpRoad(RoadPointer verticalUpRoad);
    /**
     * @brief Metoda dodająca drogę z kierunkiem lewym
     * @param verticalDownRoad - Nowa droga
     */
    static void addHorizontalLeftRoad(RoadPointer horizontalLeftRoad);
    /**
     * @brief Metoda dodająca drogę z kierunkiem prawym
     * @param verticalDownRoad - Nowa droga
     */
    static void addHorizontalRightRoad(RoadPointer horizontalRightRoad);
};

#endif // ROADREPOSITORY_H
