#pragma once
#include "../Trap.h"

class Mine : public Trap {
public:
    Mine(Point coords, Player* owner);
};
