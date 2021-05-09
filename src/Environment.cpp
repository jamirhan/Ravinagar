#include "Environment.h"

Environment::Environment(int size) {
    this->size = size;
    MakeCoins();
    SetPlayers();
}

void Environment::MakeCoins() {
    int a_c = Config::kInitialAmountAntiCoins;
    int c_c = Config::kInitialAmountClassicCoins;
    int s_c = Config::kInitialAmountSuperCoins;
    CoinsBuilder* cb = new CoinsBuilder();
    cb->SetAntiCoin(a_c)->SetClassicCoin(c_c)->SetSuperCoin(s_c);
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
