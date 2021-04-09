#include "Config.h"

Config::Config() {
    int amountCreatedCoins = size;
    Config::amountCreatedClassicCoins = (amountCreatedCoins + 1) / 2;
    Config::amountCreatedAntiCoins = (amountCreatedCoins + 3) / 4;
    Config::amountCreatedSuperCoins = (amountCreatedCoins + 3) / 4;
}

Config * Config::get_instance() {
    if (!instance) {
        instance = new Config();
    }
    return instance;
}
