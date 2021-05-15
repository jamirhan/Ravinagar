#pragma once

#include "Coin.h"
#include "CoinsFactory.h"

class AntiCoinCreator : public CoinsFactory {
public:
    Coin* Create() const override;
};
