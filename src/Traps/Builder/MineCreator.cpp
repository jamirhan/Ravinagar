#include "MineCreator.h"

Trap * MineCreator::Create() const {
    return new Mine();
}