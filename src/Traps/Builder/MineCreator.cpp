#include "MineCreator.h"

Trap* MineCreator::Create(const Point& coord, Player* owner) const {
    return new Mine(coord, owner);
}