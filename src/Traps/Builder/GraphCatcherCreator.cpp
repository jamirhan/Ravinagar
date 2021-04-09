#include "GraphCatcherCreator.h"

Trap * GraphCatcherCreator::Create(const Point& coords, Player* owner) const {
    return new GraphCatcher(coords, owner);
}