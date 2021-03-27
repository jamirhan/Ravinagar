#pragma once
#include <deque>
#include "../Player.h"
#include "../Traps/Trap.h"
#include "Coin.h"
#include "../Graph.h"
#include "Unit.h"
#include "../Message.h"
#include "../Environment.h"
#include "../tools.h"

class GameStat {
private:
    inline static GameStat* instance;
    Player* p1;
    Player* p2;
    int size;
    std::deque<Trap*> traps;
    std::deque<Coin*> coins;
    std::deque<Graph*> graphs;
    std::deque<Unit*> units;
    GameStat();
public:
    void update_graphs(GraphUpdMsg*);
    void update_units(UnitUpdMsg*);
    void update_coins(CoinUpdMsg*);
    void update_traps(TrapUpdMsg*);
    static GameStat* get_instance();
    void set(Environment*);
};
