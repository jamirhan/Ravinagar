#include "CoinsComposer.h"


CoinsComposer::CoinsComposer() = default;

CoinsComposer::CoinsComposer(std::deque<Coin*>& initial_coins) {
    coins = initial_coins;
}

int CoinsComposer::Harvest(Graph* graph) {
    std::deque<Coin*> new_coins;
    int res = 0;
    for (auto coin : coins) {
        if (graph->Distance(coin->GetCords()) < Config::kEps) {
            res += coin->GetVal();
            delete coin;
        } else {
            new_coins.push_back(coin);
        }
    }
    std::swap(coins, new_coins);
    return res;
}

void CoinsComposer::Append(std::deque<Coin*> to_add) {
    for (auto new_coin: to_add) {
        coins.push_back(new_coin);
    }
}
