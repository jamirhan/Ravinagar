#include "SuperCoinCreator.h"
#include "SuperCoin.h"

Coin * SuperCoinCreator::Create(int n) const {
    int x_cord = (n + (rand() % n)) % n;
    int y_cord = (n + (rand() % n)) % n;
    return new SuperCoin(Point(x_cord, y_cord));
}
