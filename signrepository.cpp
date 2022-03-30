#include "signrepository.h"

const QVector<SignPointer> &SignRepository::getSigns()
{
    return signs;
}

void SignRepository::addSign(SignPointer sign)
{
    signs.append(sign);
}

