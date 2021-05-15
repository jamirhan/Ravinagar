#include "CoinsBuilder.h"

void CoinsBuilder::Generate(int num, CoinsFactory* coin_factory) {
    for (int i = 0; i < num; ++i) {
        coins.push_back(coin_factory->Create());
    }
}

CoinsBuilder* CoinsBuilder::SetAntiCoin(int num) {
    Generate(num, new AntiCoinCreator());
    return this;
}

CoinsBuilder* CoinsBuilder::SetClassicCoin(int num) {
    Generate(num, new ClassicCoinCreator());
    return this;
}

CoinsBuilder* CoinsBuilder::SetSuperCoin(int num) {
    Generate(num, new SuperCoinCreator());
    return this;
}

std::deque<Coin*> CoinsBuilder::GetResult() {
    return coins;
}
