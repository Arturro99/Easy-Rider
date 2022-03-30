#ifndef SIGN_H
#define SIGN_H

#include <QSharedPointer>

typedef enum {
    GIVE_WAY,
    PRIORITY_ROAD
} SignType;

class Sign
{
private:
    const SignType type;
public:
    Sign(SignType type): type(type) {};
};

typedef QSharedPointer<Sign> SignPointer;

#endif // SIGN_H
