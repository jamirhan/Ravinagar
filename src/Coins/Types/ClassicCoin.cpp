#include "ClassicCoin.h"

ClassicCoin::ClassicCoin(Point cords) {
    val = (5 + (rand() % 5)) % 5;
    this->cords = cords;
}
