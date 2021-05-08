#pragma once

#include "Coin.h"

class CoinsFactory {
public:
    virtual Coin* Create() const = 0;

    virtual ~CoinsFactory() {}
};
