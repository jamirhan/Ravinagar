#pragma once
#include "Point.h"
#include <random>

class Coin {
protected:
    int val;
    Point cords;
public:
    int get_val();
    Point get_cords();
    virtual ~Coin();
};
