#include "ClassicCoin.h"

ClassicCoin::ClassicCoin(Point coord) : Coin((5 + (rand() % 5)) % 5, coord) {}
