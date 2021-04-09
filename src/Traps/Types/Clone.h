#pragma once
#include "../Trap.h"

class Clone : public Trap{
public:
    Clone(Point coords, Player* owner);
};
