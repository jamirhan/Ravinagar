#pragma once

#include "Message.h"
#include "Game/Game.h"
#include "Player.h"
#include "Environment.h"
#include "Game/GameStat.h"
#include "Units/Unit.h"
#include "Traps/Builder/TrapsBuilder.h"

class Message;

class Trap;

class Commutator {
    inline static Commutator* obj;

    Commutator();

public:
    static void Receive(Message* message);

    static Commutator* GetInstance();
};
