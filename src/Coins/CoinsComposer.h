#pragma once
#include "Coin.h"
#include "Graph.h"
#include <deque>


class CoinsComposer {
    std::deque<Coin*> coins;
public:
    CoinsComposer();
    CoinsComposer(std::deque<Coin*>&);
    void append(std::deque<Coin*>);
    int harvest(Graph*);
};
