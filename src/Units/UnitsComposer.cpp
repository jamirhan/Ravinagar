#include "UnitsComposer.h"


UnitsComposer::UnitsComposer() = default;

void UnitsComposer::AddUnit(Unit* new_unit) {
    units.push_back(new_unit);
}

void UnitsComposer::Check(Trap* trap) {
    for (auto unit: units) {
        if (unit->GetGraph()->GetOwner() != trap->GetOwner() &&
            unit->GetGraph()->Distance(trap->GetCoord()) < Config::kEps) {
            unit->Check(trap);
        }
    }
}

bool UnitsComposer::HasLastUnit(Unit* unit) {
    return !units.empty() && units.back() == unit;
}
