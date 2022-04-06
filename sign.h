#ifndef SIGN_H
#define SIGN_H

#include <QSharedPointer>
#include "repository.h"

/**
 * @brief Definicja SignType
 *
 * Typ wyliczeniowy przechowujący 2 rodzaje znaków, które pojawiają się na mapie
 */
typedef enum {
    GIVE_WAY,
    PRIORITY_ROAD
} SignType;

/**
 * @brief Klasa Sign
 *
 * Klasa odpowiedzialna za tworzenie instancji znaku i przechowywanie jego typu
 */
class Sign
{
private:
    /**
     * @brief Typ znaku
     */
    const SignType type;
public:
    /**
     * @brief Konstruktor klasy Sign
     * @param type - Typ znaku
     *
     * Konstruktor ustawiający wartość atrybutu type
     */
    Sign(SignType type): type(type) {};
};

/**
 * @brief Definicja SignPointer
 *
 * Definicja typu SignPointer tworząca współdzielony wskaźnik znaku
 */
typedef QSharedPointer<Sign> SignPointer;

#endif // SIGN_H
