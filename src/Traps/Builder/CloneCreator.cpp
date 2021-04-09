#include "CloneCreator.h"

Trap * CloneCreator::Create(const Point& coords, Player* owner) const {
    return new Clone(coords, owner);
}