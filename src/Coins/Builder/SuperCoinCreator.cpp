#include "SuperCoinCreator.h"
#include "SuperCoin.h"
#include "../../Game/Config.h"

Coin* SuperCoinCreator::Create() const {
    int n = Config::GetInstance()->size;
    int x_cord = rand() % n;
    int y_cord = rand() % n;
    return new SuperCoin(Point(x_cord, y_cord));
}
