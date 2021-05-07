#pragma once

#include <map>

class Config {
    inline static Config* instance;

    Config();

public:
    inline static int size = 20;
    inline static int kAmountCreatedAntiCoins;
    inline static int kAmountCreatedClassicCoins;
    inline static int kAmountCreatedSuperCoins;
    inline static int kMaxAmountOwnGraphs = 5;
//    inline static int kMaxAmountCapturedGraphs = 3;

    inline static std::map<std::string, int> kRequestCosts = {
            {"ExitIntoSpace",           5},
            {"DestroyCapturedGraph",    4},
            {"DestroyOwnGraph",         4},
            {"CreateGraph",             4},
            {"LastGraph",               8},
            {"SayHello",                0},
            {"Move",                    30},
            {"CreateTrap;GraphCathcer", 3},
            {"CreateTrap;Clone",        4},
            {"CreateTrap;Mine",         5},
            {"CreateUnit;BestFriend",   5},
            {"CreateUnit;Farmer",       2},
            {"CreateUnit;CCTV",         3},
            {"CreateUnit;Spy",          3},
    };

    inline static int kCostAntiCoin = -1;
    inline static int kCostClassCoin = 1;
    inline static int kCostSuperCoin = 3;

    inline static int kEps = 2;

    static Config* GetInstance();

};
