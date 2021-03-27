#pragma once
#include <deque>
#include "Coin.h"
#include "CoinsFactory.h"
#include "ClassicCoinCreator.h"
#include "AntiCoinCreator.h"
#include "SuperCoinCreator.h"

class CoinsBuilder {
    std::deque<Coin*> coins;
    int field_size;
    void generate(int, CoinsFactory*);
public:
    CoinsBuilder(int);
    CoinsBuilder* set_AntiCoin(int);
    CoinsBuilder* set_ClassicCoin(int);
    CoinsBuilder* set_SuperCoin(int);
    std::deque<Coin*> get_result();
};
