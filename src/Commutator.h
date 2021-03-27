#pragma once
#include "Message.h"
#include "Game/Game.h"
#include "Player.h"
#include "Environment.h"
#include "Game/GameStat.h"


class Commutator {
    inline static Commutator* obj;
    Commutator();
public:
    void receive(Message*);
    static Commutator* get_instance();
};
