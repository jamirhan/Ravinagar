#pragma once

#include "../Trap.h"
#include "TrapFactory.h"

class GraphCatcherCreator : public TrapFactory {
public:
    Trap* Create(const Point& coords, Player* owner) const override;
};
