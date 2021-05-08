#include "Config.h"

Config::Config() {
    int amountCreatedCoins = size;
    Config::kAmountCreatedClassicCoins = (amountCreatedCoins + 1) / 2;
    Config::kAmountCreatedAntiCoins = (amountCreatedCoins + 3) / 4;
    Config::kAmountCreatedSuperCoins = (amountCreatedCoins + 3) / 4;
}

Config* Config::GetInstance() {
    if (!instance) {
        instance = new Config();
    }
    return instance;
}
