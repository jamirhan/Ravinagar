#include "UnitsComposer.h"


UnitsComposer::UnitsComposer() = default;

void UnitsComposer::add_unit(Unit* new_unit) {
    units.push_back(new_unit);
}
