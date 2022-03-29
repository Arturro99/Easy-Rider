#include "randgenerator.h"

std::default_random_engine generator = std::default_random_engine(time(NULL));

int RandGenerator::generate(int a, int b)
{
    std::uniform_int_distribution<int> value(a, b);
    return value(generator);
}
