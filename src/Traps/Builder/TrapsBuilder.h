#pragma once
#include "TrapFactory.h"

class TrapsBuilder {
public:
    Trap* generate(TrapFactory* trap_factory, const Point& coords, Player* owner);
    Trap* generate(std::string type, const Point& coords, Player* owner);
    TrapsBuilder();
};
