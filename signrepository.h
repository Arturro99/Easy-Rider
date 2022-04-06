#ifndef SIGNREPOSITORY_H
#define SIGNREPOSITORY_H

#include "sign.h"

class SignRepository
{
private:
    inline static QVector<SignPointer> signs;
public:

    static const QVector<SignPointer> &getSigns();
    static void addSign(SignPointer sign);
};

#endif // SIGNREPOSITORY_H
