#include "CoinsBuilder.h"

void CoinsBuilder::generate(int num, CoinsFactory* coin_factory) {
    for (int i = 0; i < num; ++i) {
        coins.push_back(coin_factory->Create());
    }
}

CoinsBuilder* CoinsBuilder::set_AntiCoin(int num) {
    generate(num, new AntiCoinCreator());
    return this;
}

CoinsBuilder* CoinsBuilder::set_ClassicCoin(int num) {
    generate(num, new ClassicCoinCreator());
    return this;
}

CoinsBuilder* CoinsBuilder::set_SuperCoin(int num) {
    generate(num, new SuperCoinCreator());
    return this;
}

std::deque<Coin*> CoinsBuilder::get_result() {
    return coins;
}
