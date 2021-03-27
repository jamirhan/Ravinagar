#include "AntiCoin.h"

AntiCoin::AntiCoin(Point cords) {
    val = -(rand() % 5);
    this->cords = cords;
}
