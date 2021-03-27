#include "GameStat.h"


GameStat::GameStat() = default;

GameStat* GameStat::get_instance() {
    if (!instance)
        instance = new GameStat();
    return instance;
}

void GameStat::update_coins(CoinUpdMsg* msg) {
    gtools::insert(coins, msg->ins);
    gtools::del(coins, msg->del);
}

void GameStat::update_graphs(GraphUpdMsg* msg) {
    gtools::insert(graphs, msg->ins);
    gtools::del(graphs, msg->del);
}

void GameStat::update_traps(TrapUpdMsg* msg) {
    gtools::insert(traps, msg->ins);
    gtools::del(traps, msg->del);
}

void GameStat::update_units(UnitUpdMsg* msg) {
    gtools::insert(units, msg->ins);
    gtools::del(units, msg->del);
}

void GameStat::set(Environment* env) {
    update_coins(new CoinUpdMsg(&env->coins, nullptr));
    size = env->size;
    p1 = env->p1;
    p2 = env->p2;
}
