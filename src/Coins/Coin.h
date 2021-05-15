#pragma once

#include "Point.h"
#include <random>

class Coin {
protected:
    int val;
    Point coords;

    Coin(int val, Point coords);

public:

    int GetVal();

    Point GetCords();

    virtual ~Coin();
};
