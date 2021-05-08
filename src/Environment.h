#pragma once

#include <deque>
#include "../Traps/Trap.h"
#include "Coin.h"
#include "Player.h"
#include "Builder/CoinsBuilder.h"

class Environment {
    void MakeCoins();

    void SetPlayers();

    Player* SetPlayer();

    static const int initial_player_coins = 15;
public:
    std::deque<Coin*> coins;
    int size;
    Player* p1;
    Player* p2;

    Environment(int);

};
