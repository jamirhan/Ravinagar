#include "GameStat.h"


GameStat::GameStat() = default;

GameStat* GameStat::get_instance() {
    if (!instance)
        instance = new GameStat();
    return instance;
}

TrapsComposer& GameStat::get_traps() {
    return traps;
}

CoinsComposer& GameStat::get_coins() {
    return coins;
}

GraphsComposer& GameStat::get_graphs() {
    return graphs;
}

UnitsComposer& GameStat::get_units() {
    return units;
}

void GameStat::set(Environment* env) {
    coins.append(env->coins);
    size = env->size;
    p1 = env->p1;
    p2 = env->p2;
}

Player* GameStat::get_player(int num) {
    if (num == 1)
        return p1;
    else
        return p2;
}
