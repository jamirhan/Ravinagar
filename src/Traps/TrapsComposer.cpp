#include "TrapsComposer.h"


TrapsComposer::TrapsComposer() = default;

TrapsComposer::TrapsComposer(std::deque<Trap*>& ar): traps(ar) {}

void TrapsComposer::add_trap(Trap* new_trap) {
    traps.push_back(new_trap);
}

void TrapsComposer::check(Graph* graph) {
    for (auto trap: traps) {
        trap->check(graph);
    }
}

void TrapsComposer::remove_trap(Trap* to_remove) {
    for (auto trap = traps.begin(); trap != traps.end(); ++trap) {
        if (*trap == to_remove) {
            traps.erase(trap);
        }
    }
}
