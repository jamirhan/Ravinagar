#pragma once
#include "../Trap.h"

class TrapFactory {
public:
    virtual Trap* Create(const Point& coords, Player* owner) const = 0;
    virtual ~TrapFactory() {}

};
