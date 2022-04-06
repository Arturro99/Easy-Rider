#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "road.h"
#include "drivethread.h"
#include "car.h"
#include "roadrepository.h"
#include "vehiclerepository.h"
#include "threadmanager.h"
#include "drivethreadcreator.h"
#include "signrepository.h"

#include <QMainWindow>
#include <QSharedPointer>
#include <QVector>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Klasa MainWindow odpowiedzialna za widok aplikacji
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy MainWindow
     * @param threadCreator - instancja powołująca nowe wątki pojazdów
     * @param parent - rodzic instancji klasy QMainWindow
     *
     * Zadaniem konstruktora jest odpowiednie ustawienie GUI oraz inicjalizacja dróg i znaków
     * poprzez pobranie ich z mapy
     */
    MainWindow(DriveThreadCreator *threadCreator, QWidget *parent = nullptr);
    ~MainWindow();

private:
    /**
     * @brief ui - Interfejs użytkownika
     */
    Ui::MainWindow *ui;
    /**
     * @brief threadCreator - Instancja tworząca wątki pojazdów
     */
    DriveThreadCreator *threadCreator;
    /**
     * @brief background - Atrybut przechowujący tło widoku
     */
    QSharedPointer<QPixmap> background;
    /**
     * @brief Metoda przypisująca ulice
     *
     * Zadaniem metody jest iteracja po obiekatch typu QFrame znajdujących się na mapie,
     * a następnie odpowiednie tworzenie dróg jako obiektów aplikacji wraz z dodaniem
     * ich do repozytorium
     */
    void assignStreets();
    /**
     * @brief Metoda przypisująca znaki
     *
     * Zadaniem metody jest iteracja po obiekatch typu QFrame znajdujących się na mapie,
     * a następnie odpowiednie tworzenie znaków jako obiektów aplikacji wraz z dodaniem
     * ich do repozytorium
     */
    void assignSigns();
    /**
     * @brief Metoda rysująca elementy w GUI
     * @param event - wydarzenie
     *
     * Zadaniem metody jest dynamiczna aktualizacja pozycji obiektów
     * znajdujących się na mapie wykorzystując do tego celu współrzędne,
     * które dany obiekt zawiera. Ponadto usuwa nieistniejące obiekty pojazdów
     * z repozytorium oraz ustawia tło aplikacji
     */
    void paintEvent(QPaintEvent *event);

private slots:
    /**
     * @brief Slot on_horizontalSlider_valueChanged
     * @param value - docelowa wartość paska
     *
     * Metoda odpowiedzialna jest za zmianę natężenia ruchu. W zależności
     * od wartości paska odpowiednio ustawia liczbę wątków, które aplikacja
     * będzie mogła utworzyć
     */
    void on_horizontalSlider_valueChanged(int value);
};
#endif // MAINWINDOW_H
