#include "Coin.h"

int Coin::get_val() {
    return val;
}

Coin::~Coin() = default;

Point Coin::get_cords() {
    return cords;
}
