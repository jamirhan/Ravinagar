#pragma once
#include "Unit.h"
#include <deque>


class UnitsComposer {
    std::deque<Unit*> units;
public:
    UnitsComposer();
    void add_unit(Unit*);
};
