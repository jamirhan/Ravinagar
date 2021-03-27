#include "Environment.h"


Environment::Environment(int size) {
    this->size = size;
    make_coins();
    set_players();
}

void Environment::make_coins() {
    int a_c = 10;
    int c_c = 20;
    int s_c = 10;
    CoinsBuilder* cb = new CoinsBuilder(size);
    cb->set_AntiCoin(a_c)->set_ClassicCoin(c_c)->set_SuperCoin(s_c);
    coins = cb->get_result();
}

void Environment::set_players() {
    p1 = set_player();
    p2 = set_player();
}

Player* Environment::set_player() {
    int x_cord = (size + (rand() % size)) % size;
    int y_cord = (size + (rand() % size)) % size;
    Player* player = new Player(x_cord, y_cord);
    player->update_coins(initial_player_coins);
    return player;
}
