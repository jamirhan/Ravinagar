#pragma once
#include <deque>
#include "Coin.h"
#include "CoinsFactory.h"
#include "ClassicCoinCreator.h"
#include "AntiCoinCreator.h"
#include "SuperCoinCreator.h"

class CoinsBuilder {
    std::deque<Coin*> coins;
    void generate(int, CoinsFactory*);
public:
    CoinsBuilder() = default;
    CoinsBuilder* set_AntiCoin(int);
    CoinsBuilder* set_ClassicCoin(int);
    CoinsBuilder* set_SuperCoin(int);
    std::deque<Coin*> get_result();
};
