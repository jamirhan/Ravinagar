#include "AntiCoinCreator.h"
#include "AntiCoin.h"
#include "../../Game/Config.h"

Coin* AntiCoinCreator::Create() const {
    int n = Config::GetInstance()->size;
    int x_cord = rand() % n;
    int y_cord = rand() % n;
    return new AntiCoin(Point(x_cord, y_cord));
}
