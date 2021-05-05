#include "ClassicCoinCreator.h"
#include "ClassicCoin.h"
#include "../../Game/Config.h"

Coin* ClassicCoinCreator::Create() const {
    int n = Config::GetInstance()->size;
    int x_cord = rand() % n;
    int y_cord = rand() % n;
    return new ClassicCoin(Point(x_cord, y_cord));
}