#pragma once
#include "Coin.h"
#include "CoinsFactory.h"

class SuperCoinCreator : public CoinsFactory {
public:
    Coin* Create() const override;
};
