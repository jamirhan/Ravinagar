#include "SuperCoin.h"

SuperCoin::SuperCoin(Point coord) : Coin((10 + (rand() % 10)) % 10, coord) {}
