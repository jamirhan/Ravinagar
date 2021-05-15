#pragma once

#include "Coin.h"
#include "Graph.h"
#include <deque>


class CoinsComposer {
    std::deque<Coin*> coins;
public:
    CoinsComposer();

    CoinsComposer(std::deque<Coin*>&);

    void Append(std::deque<Coin*> to_add);

    int Harvest(Graph*);
};
