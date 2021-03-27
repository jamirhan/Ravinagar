#include "GraphCatcherCreator.h"

Trap * GraphCatcherCreator::Create() const {
    return new GraphCatcher();
}