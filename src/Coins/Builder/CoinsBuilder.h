#pragma once

#include <deque>
#include "Coin.h"
#include "CoinsFactory.h"
#include "ClassicCoinCreator.h"
#include "AntiCoinCreator.h"
#include "SuperCoinCreator.h"

class CoinsBuilder {
    std::deque<Coin*> coins;

    void Generate(int num, CoinsFactory* coin_factory);

public:
    CoinsBuilder() = default;

    CoinsBuilder* SetAntiCoin(int);

    CoinsBuilder* SetClassicCoin(int);

    CoinsBuilder* SetSuperCoin(int);

    std::deque<Coin*> GetResult();
};
