#pragma once
#include "../Graph.h"

class Trap {
    Point coords;
    Player* owner;
protected:
    Trap(Point coords, Player* owner);
public:
    void check(Graph*);
    virtual ~Trap();
};
