#pragma once

#include "Unit.h"
#include <deque>
#include "Traps/Trap.h"

class Unit;

class UnitsComposer {
    std::deque<Unit*> units;
public:
    UnitsComposer();

    void Check(Trap* trap);

    void AddUnit(Unit* new_unit);

    bool HasLastUnit(Unit*);
};
