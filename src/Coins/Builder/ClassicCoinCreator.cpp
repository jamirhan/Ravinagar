#include "ClassicCoinCreator.h"
#include "ClassicCoin.h"

Coin * ClassicCoinCreator::Create(int n) const {
    int x_cord = (n + (rand() % n)) % n;
    int y_cord = (n + (rand() % n)) % n;
    return new ClassicCoin(Point(x_cord, y_cord));
}