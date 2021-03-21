#ifndef RAVINAGAR_ENVIRONMENT_H
#define RAVINAGAR_ENVIRONMENT_H

#include "Trap.h"
#include "Coin.h"
#include "Player.h"
#include <vector>

class Environment {
public:
    std::vector<Trap> traps;
    std::vector<Coin> coins;
    std::vector<Player> players;

    void merge(const Environment& other);
};


#endif //RAVINAGAR_ENVIRONMENT_H
