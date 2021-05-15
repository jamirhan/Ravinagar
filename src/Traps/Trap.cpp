#include "Trap.h"

Trap::Trap(Point coord, Player* owner) : coord(coord), owner(owner) {}

const Point& Trap::GetCoord() const {
    return coord;
}

std::string Trap::CoordTrapFormat() {
    return coord.CoordPointFormat();
}

Player* Trap::GetOwner() const {
    return owner;
}

bool Trap::Check(Graph* graph) {
    return false;
}

bool Trap::Check(Unit* unit) {
    return false;
}

Trap::~Trap() = default;

Clone::Clone(Point coords, Player* owner) : Trap(coords, owner) {}

GraphCatcher::GraphCatcher(Point coords, Player* owner) : Trap(coords, owner) {}

bool GraphCatcher::Check(Graph* graph) {
    Commutator::Receive(new PrintMsg("GraphCatcher с координатами " + GetCoord().CoordPointFormat(),
                                     GetOwner()));
    return true;
}

Mine::Mine(Point coord, Player* owner) : Trap(coord, owner) {}

bool Mine::Check(Unit* unit) {
    if (dynamic_cast<Farmer*>(unit)) {
        Commutator::Receive(
                new PrintMsg("Farmer, расположенный на пути " + unit->GetGraph()->FormulaFormat() +
                             " обнаружил ловушку типа Mine с координатами " + GetCoord().CoordPointFormat(),
                             GetOwner()));
    }
    return true;
}
