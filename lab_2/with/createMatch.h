#ifndef CREATEMATCH_H
#define CREATEMATCH_H

#include "creator.h"
#include "match.h"

// The concrete class-creator - CreateMatch

class CreateMatch : public Creator {
public:
    Entry* create() override {
        qDebug() << "CreateMatch::create";
        return new Match{};
    }
};

#endif // CREATEMATCH_H
