#pragma once
#include <deque>
#include "../Player.h"
#include "../Traps/Trap.h"
#include "Coin.h"
#include "../Graph.h"
#include "Unit.h"
#include "../Message.h"
#include "../Environment.h"
#include "../Traps/TrapsComposer.h"
#include "../Coins/CoinsComposer.h"
#include "../Units/UnitsComposer.h"
#include "../GraphsComposer.h"


class GameStat {
private:
    inline static GameStat* instance;
    Player* p1;
    Player* p2;
    TrapsComposer traps;
    CoinsComposer coins;
    GraphsComposer graphs;
    UnitsComposer units;
    GameStat();
public:
    TrapsComposer& get_traps();
    CoinsComposer& get_coins();
    GraphsComposer& get_graphs();
    UnitsComposer& get_units();
    static GameStat* get_instance();
    void set(Environment*);
    Player* get_player(int);
};

