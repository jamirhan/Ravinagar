#pragma once

#include "TrapFactory.h"

class Trap;

class TrapFactory;

class TrapsBuilder {
public:
    Trap* Generate(TrapFactory* trap_factory, const Point& coord, Player* owner);

    Trap* Generate(std::string type, const Point& coords, Player* owner);
};
