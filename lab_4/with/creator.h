#ifndef CREATOR_H
#define CREATOR_H

#include "entry.h"

// The interface create classes

class Creator {
public:
    virtual ~Creator() = default;
    virtual Entry* create() = 0;
};

#endif // CREATOR_H
