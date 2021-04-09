#include "MineCreator.h"

Trap * MineCreator::Create(const Point& coords, Player* owner) const {
    return new Mine(coords, owner);
}