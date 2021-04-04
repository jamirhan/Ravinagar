#pragma once
#include <deque>
#include "../Traps/Trap.h"
#include "Coin.h"
#include "Player.h"
#include "Builder/CoinsBuilder.h"

class Environment {
    void make_coins();
    void set_players();
    Player* set_player();
    static const int initial_player_coins = 15;
public:
    std::deque<Coin*> coins;
    int size;
    Player* p1;
    Player* p2;
    Environment(int);

};
