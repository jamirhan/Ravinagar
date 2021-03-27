#include "SuperCoin.h"

SuperCoin::SuperCoin(Point cords) {
    val = (10 + (rand() % 10)) % 10;
    this->cords = cords;
}
