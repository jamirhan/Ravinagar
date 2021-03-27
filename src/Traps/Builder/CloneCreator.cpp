#include "CloneCreator.h"

Trap * CloneCreator::Create() const {
    return new Clone();
}