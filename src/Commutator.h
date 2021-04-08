#pragma once
#include "Message.h"
#include "Game/Game.h"
#include "Player.h"
#include "Environment.h"
#include "Game/GameStat.h"
#include "Units/Unit.h"

class Commutator {
    inline static Commutator* obj;
    Commutator();
    
public:
    static void receive(Message*);

    static Commutator *get_instance();
};
