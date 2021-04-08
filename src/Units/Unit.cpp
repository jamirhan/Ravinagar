#include "Unit.h"


Unit::Unit(Graph* graph): location(graph) { };


Graph* Unit::get_graph() {
    return location;
}


Spy::Spy(Graph *graph): Unit(graph) { };

CCTV::CCTV(Graph *graph): Unit(graph) { };

BestFriend::BestFriend(Graph *graph): Unit(graph) { };

Farmer::Farmer(Graph *graph): Unit(graph) { };


// Empty until task 3, where we will add actions
void Spy::check() {

}

void CCTV::check() {

}

void BestFriend::check() {

}

void Farmer::check() {

}
