#include "GameStat.h"

GameStat::GameStat() = default;

GameStat* GameStat::GetInstance() {
    if (!instance)
        instance = new GameStat();
    return instance;
}

TrapsComposer* GameStat::GetTraps() {
    return traps;
}

CoinsComposer* GameStat::GetCoins() {
    return coins;
}

GraphsComposer* GameStat::GetGraphs() {
    return graphs;
}

UnitsComposer* GameStat::GetUnits() {
    return units;
}

void GameStat::Set(Environment* env) {
    traps = new TrapsComposer;
    coins = new CoinsComposer;
    units = new UnitsComposer;
    graphs = new GraphsComposer;
    coins->Append(env->coins);
    Config::GetInstance()->size = env->size;
    p1 = env->p1;
    p2 = env->p2;
}

int GameStat::get_player_num(Player* p) {
    if (p == GetPlayer(1)) return 1;
    else return 2;
}

Player* GameStat::GetPlayer(int num) {
    if (num == 1)
        return p1;
    else
        return p2;
}

Player* GameStat::GetEnemy(Player* player) {
    if (player == p1) {
        return p2;
    }
    return p1;
}
