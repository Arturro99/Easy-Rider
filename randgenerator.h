#ifndef RANDGENERATOR_H
#define RANDGENERATOR_H

#include <random>

/**
 * @brief Klasa RandGenerator
 *
 * Celem klasy jest dostarczenie metody generującą pseudolosową liczbę
 */
class RandGenerator
{
public:
    /**
     * @brief Metoda generująca pseudolosową liczbę
     * @param a - początek zakresu losowanych liczb
     * @param b - koniec zakresu losowanych liczb
     * @return Wylosowana liczba typu całkowitego
     */
    static int generate(int a, int b);
};

#endif // RANDGENERATOR_H
