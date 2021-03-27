#include "AntiCoinCreator.h"
#include "AntiCoin.h"

Coin* AntiCoinCreator::Create(int n) const {
    int x_cord = (n + (rand() % n)) % n;
    int y_cord = (n + (rand() % n)) % n;
    return new AntiCoin(Point(x_cord, y_cord));
}
