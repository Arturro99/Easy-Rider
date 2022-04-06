#ifndef BICYCLE_H
#define BICYCLE_H

#include "vehicle.h"


/**
 * @brief Klasa Bicycle reprezentująca rower w aplikacji
 *
 * Klasa dziedzicząca po Vehicle odpowiedzialna za zarządzanie instancjami roweru w aplikacji
 */
class Bicycle : public Vehicle
{
private:
    /**
     * @brief Metoda sterująca rowerem
     * @param direction - Docelowy kierunek poruszania się roweru
     * @return 0 w przypadku wykrycia możliwości kolizji/znaku pierwszeństwa lub zakończenia drogi lub 1 w przypadku kontynuacji jazdy
     *
     * Metoda odpowiedzialna za sterowanie rowerem - zmianę jego położenia oraz kierunku
     */
    int operateBike(Direction direction);
    /**
     * @brief doSpontaneousRotation
     */
    void doSpontaneousRotation();

public:
    /**
     * @brief Konstruktor klasy Bicycle
     * @param initialDirection - zainicjowana wartość kierunku pojazdu
     *
     * Konstruktor odpowiedzialny jest za początkowe odpowiednie obrócenie pojazdu zgodnie z kierunkiem jazdy, wygenerowanie id
     * oraz odpowiednie ustawienie i przeskalowanie przypisanego do roweru obrazu
     */
    explicit Bicycle(Direction initialDirection): Vehicle(initialDirection)
    {
        this->id = QUuid::createUuid();
        QImage *image = new QImage(":/img/img/bike.png");
        QTransform transform;
        switch (initialDirection) {
            case 0: {
                transform.rotate(270);
                break;
            }
            case DOWN: {
                transform.rotate(90);
                break;
            }
            case RIGHT: {
                transform.rotate(0);
                break;
            }
            case LEFT: {
                transform.rotate(180);

            }
        }
        *image = image->transformed(transform);
        *image = image->scaled(60, 60, Qt::AspectRatioMode::KeepAspectRatio);
        this->image = image;
        this->currentDirection = initialDirection;
    }
    /**
     * @brief Metoda zarządzająca ruchem pojazdu
     *
     * Wirtualna metoda, której celem jest zarządzanie ruchem pojazdu
     */
    virtual void drive();
};

#endif // BICYCLE_H
