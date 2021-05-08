#include "Environment.h"

Environment::Environment(int size) {
    this->size = size;
    MakeCoins();
    SetPlayers();
}

void Environment::MakeCoins() {
    int a_c = 10;
    int c_c = 20;
    int s_c = 10;
    CoinsBuilder* cb = new CoinsBuilder();
    cb->SetAntiCoin(a_c)->SetAntiCoin(c_c)->SetAntiCoin(s_c);
    coins = cb->GetResult();
}

void Environment::SetPlayers() {
    p1 = SetPlayer();
    p2 = SetPlayer();
}

Player* Environment::SetPlayer() {
    int x_cord = (size + (rand() % size)) % size;
    int y_cord = (size + (rand() % size)) % size;
    Player* player = new Player(x_cord, y_cord);
    player->UpdateCoins(initial_player_coins);
    return player;
}
