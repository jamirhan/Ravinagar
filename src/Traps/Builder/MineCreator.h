#pragma once
#include "../Trap.h"
#include "../Types/Mine.h"
#include "TrapFactory.h"

class MineCreator : public TrapFactory{
public:
    Trap* Create() const override;
};
