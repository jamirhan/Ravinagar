#pragma once

#include "Coin.h"
#include "CoinsFactory.h"

class ClassicCoinCreator : public CoinsFactory {
public:
    Coin* Create() const override;
};
