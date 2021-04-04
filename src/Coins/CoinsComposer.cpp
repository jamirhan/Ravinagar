#include "CoinsComposer.h"


CoinsComposer::CoinsComposer() = default;

CoinsComposer::CoinsComposer(std::deque<Coin*>& initial_coins) {
    coins = initial_coins;
}

int CoinsComposer::harvest(Graph*) {
    return 5; // TODO // should also delete coins on graph
}

void CoinsComposer::append(std::deque<Coin*> to_add) {
    for (auto new_coin: to_add) {
        coins.push_back(new_coin);
    }
}
