#include <QVector>
#ifndef REPOSITORYTEMPLATE_H
#define REPOSITORYTEMPLATE_H

#endif // REPOSITORYTEMPLATE_H

/**
 * @brief Szablon Repository
 *
 * Szablon wykorzystywany do klas repozytoriów dla znaków, dróg oraz pojazdów
 */
template <class T>
class Repository {

protected:
    /**
     * @brief objects - Atrybut przechowujący wszystkie obiekty danego typu
     */
    inline static QVector<T> objects;

public:
    /**
     * @brief Metoda zwracająca wszystkie obiekty danego typu
     * @return Wektor obiektów typu T
     */
    static const QVector<T> getAll() {
        return objects;
    }
    /**
     * @brief Metoda dodająca obiekt danego typu do wektora objects
     * @param object - Obiekt typu T
     */
    static void addObject(T object) {
        objects.append(object);
    };
};
