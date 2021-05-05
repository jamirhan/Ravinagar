#pragma once

#include "../Traps/TrapsComposer.h"
#include "../Coins/CoinsComposer.h"
#include "../Units/UnitsComposer.h"
#include <deque>
#include "../Player.h"
#include "../Traps/Trap.h"
#include "Coin.h"
#include "../Graph.h"
#include "Unit.h"
#include "../Message.h"
#include "../Environment.h"
#include "../GraphsComposer.h"

class Environment;

class Trap;

class TrapsComposer;

class CoinsComposer;

class GraphsComposer;

class UnitsComposer;

class GameStat {
private:
    inline static GameStat* instance;
    Player* p1 = nullptr;
    Player* p2 = nullptr;
    TrapsComposer* traps;
    CoinsComposer* coins;
    GraphsComposer* graphs;
    UnitsComposer* units;

    GameStat();

public:
    TrapsComposer* GetTraps();

    CoinsComposer* GetCoins();

    GraphsComposer* GetGraphs();

    UnitsComposer* GetUnits();

    static GameStat* GetInstance();

    void Set(Environment* env);

    Player* GetPlayer(int);

    Player* GetEnemy(Player*);
};

