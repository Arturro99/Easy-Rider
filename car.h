#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

/**
 * @brief Klasa Car reprezentująca samochód w aplikacji
 *
 * Klasa dziedzicząca po Vehicle odpowiedzialna za zarządzanie instancjami samochodu w aplikacji
 */
class Car : public Vehicle
{
private:
    /**
     * @brief Metoda sterująca samochodem
     * @param direction - Docelowy kierunek poruszania się samochodu
     * @return 0 w przypadku wykrycia możliwości kolizji/znaku pierwszeństwa lub zakończenia drogi lub 1 w przypadku kontynuacji jazdy
     *
     * Metoda odpowiedzialna za sterowanie samochodem - zmianę jego położenia oraz kierunku
     */
    int operateCar(Direction direction);

public:
    /**
     * @brief Konstruktor klasy Car
     * @param initialDirection - zainicjowana wartość kierunku pojazdu
     *
     * Konstruktor odpowiedzialny jest za początkowe odpowiednie obrócenie pojazdu zgodnie z kierunkiem jazdy, wygenerowanie id
     * oraz odpowiednie ustawienie i przeskalowanie przypisanego do samochodu obrazu
     */
    Car(Direction initialDirection) : Vehicle(initialDirection)
    {
        this->id = QUuid::createUuid();
        QImage *image = new QImage(":/img/img/car.png");
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
        *image = image->scaled(80, 80, Qt::AspectRatioMode::KeepAspectRatio);
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



#endif // CAR_H
