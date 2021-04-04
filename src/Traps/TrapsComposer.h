#pragma once
#include "Trap.h"
#include <deque>

class TrapsComposer {
    std::deque<Trap*> traps;
public:
    TrapsComposer();
    TrapsComposer(std::deque<Trap*>&);
    void add_trap(Trap*);
    void check(Graph*);
    void remove_trap(Trap*);
};
