#include "GraphCatcherCreator.h"

Trap* GraphCatcherCreator::Create(const Point& coord, Player* owner) const {
    return new GraphCatcher(coord, owner);
}