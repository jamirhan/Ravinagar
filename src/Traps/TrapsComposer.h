#pragma once

#include "Trap.h"
#include <deque>

class Trap;
class Unit;

class TrapsComposer {
    std::deque<Trap*> traps;
public:
    TrapsComposer();

    TrapsComposer(std::deque<Trap*>&);

    void AddTrap(Trap* new_trap);

    void Check(Graph* graph);

    void Check(Unit* unit);

    void RemoveTrap(Trap* to_remove);

    void Search(Unit* unit);
};
