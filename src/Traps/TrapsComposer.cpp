#include "TrapsComposer.h"


TrapsComposer::TrapsComposer() = default;

TrapsComposer::TrapsComposer(std::deque<Trap*>& ar) : traps(ar) {}

void TrapsComposer::AddTrap(Trap* new_trap) {
    traps.push_back(new_trap);
}

void TrapsComposer::Check(Graph* graph) {
    for (auto trap: traps) {
        if (trap->GetOwner() != graph->GetOwner() && graph->Distance(trap->GetCoord()) < Config::kEps) {
            trap->Check(graph);
        }
    }
}

void TrapsComposer::Check(Unit* unit) {
    for (auto trap: traps) {
        if (trap->GetOwner() != unit->GetGraph()->GetOwner() &&
            unit->GetGraph()->Distance(trap->GetCoord()) < Config::kEps) {
            trap->Check(unit);
        }
    }
}

void TrapsComposer::RemoveTrap(Trap* to_remove) {
    for (auto trap = traps.begin(); trap != traps.end(); ++trap) {
        if (*trap == to_remove) {
            traps.erase(trap);
        }
    }
}

void TrapsComposer::Search(Unit* unit) {
    for (auto trap : traps) {
        if (trap->GetOwner() != unit->GetGraph()->GetOwner() &&
            unit->GetGraph()->Distance(trap->GetCoord()) < Config::kEps) {
            unit->Check(trap);
        }
    }
}
