#ifndef CREATETEAM_H
#define CREATETEAM_H

#include "creator.h"
#include "team.h"

// The concrete class-creator - CreateTeam

class CreateTeam : public Creator {
public:
    Entry* create() override {
        qDebug() << "CreateTeam::create";
        return new Team{};
    }
};

#endif // CREATETEAM_H


