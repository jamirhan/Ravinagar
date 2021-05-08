#include "Coin.h"

int Coin::GetVal() {
    return val;
}

Coin::Coin(int val, Point coord) : val(val), coords(coord) {}

Coin::~Coin() = default;

Point Coin::GetCords() {
    return coords;
}
