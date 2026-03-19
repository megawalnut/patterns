#ifndef CREATEPLAYER_H
#define CREATEPLAYER_H

#include "creator.h"
#include "player.h"

// The concrete class-creator - CreatePlayer

class CreatePlayer : public Creator {
public:
    Entry* create() override {
        qDebug() << "CreatePlayer::create";
        return new Player{};
    }
};

#endif // CREATEPLAYER_H
