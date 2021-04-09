#pragma once

class Config {
    inline static Config* instance;
    Config();
public:
    inline static int size = 20;
    inline static int amountCreatedAntiCoins;
    inline static int amountCreatedClassicCoins;
    inline static int amountCreatedSuperCoins;
    static Config* get_instance();
};
