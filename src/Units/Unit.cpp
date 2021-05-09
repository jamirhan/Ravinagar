#include "Unit.h"

Unit::Unit(Graph* graph) : location(graph) {};


Graph* Unit::GetGraph() {
    return location;
}


Spy::Spy(Graph* graph) : Unit(graph) {};

CCTV::CCTV(Graph* graph) : Unit(graph) {};

BestFriend::BestFriend(Graph* graph) : Unit(graph) {};

Farmer::Farmer(Graph* graph) : Unit(graph) {};

bool Spy::Check(Trap* trap) {
    Commutator::Receive(new PrintMsg{
            "Spy, расположенный на кривой, соответствующей " + location->FormulaFormat() +
            " засёк ловушку противника", location->GetOwner()});
    return true;
}

bool CCTV::Check(Trap* trap) {
}

bool BestFriend::Check(Trap* trap) {
    if (dynamic_cast<Clone*>(trap)) {
        Commutator::Receive(new PrintMsg{
                "BestFriend, расположенный на кривой, соответствующей " + location->FormulaFormat() +
                " засёк ловушку противника типа Clone", location->GetOwner()});
        return true;
    }
    return false;
}

bool Farmer::Check(Trap* trap) {
    if (dynamic_cast<Mine*>(trap)) {
        Commutator::Receive(new PrintMsg{
                "Farmer, расположенный на кривой, соответствующей " + location->FormulaFormat() +
                " засёк ловушку типа Mine cо следующими координатами: " + trap->CoordTrapFormat(),
                location->GetOwner()});
        return true;
    }
    return false;
}
