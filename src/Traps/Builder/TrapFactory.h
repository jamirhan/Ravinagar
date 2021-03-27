#pragma once
#include "../Trap.h"

class TrapFactory {
public:
    virtual Trap* Create() const = 0;
    virtual void Check() = 0;
    virtual ~TrapFactory() {}

};
