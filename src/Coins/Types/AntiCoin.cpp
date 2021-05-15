#include "AntiCoin.h"

AntiCoin::AntiCoin(Point coord) : Coin(-rand() % 5, coord) {}
