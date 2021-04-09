#pragma once
#include "../Trap.h"
#include "../Types/Clone.h"
#include "TrapFactory.h"

class CloneCreator : public TrapFactory {
public:
    Trap* Create(const Point& coords, Player* owner) const override;
};