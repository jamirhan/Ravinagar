#include "Commutator.h"
#include <iostream>

void Commutator::receive(Message* message) {

    if (dynamic_cast<EnvMsg*>(message)) {
        EnvMsg* emsg = dynamic_cast<EnvMsg*>(message);
        GameStat::get_instance()->set(emsg->env);
    }

    else if (dynamic_cast<CreateGraph*> (message)) {
        CreateGraph* msg = dynamic_cast<CreateGraph*>(message);
        Graph* new_graph = new Graph(msg->polynom, GameStat::get_instance()->get_player(msg->player_id));
        int catched = GameStat::get_instance()->get_coins().harvest(new_graph);
        GameStat::get_instance()->get_player(msg->player_id)->update_coins(catched);
        GameStat::get_instance()->get_traps().check(new_graph);
        GameStat::get_instance()->get_graphs().add_graph(new_graph);
    }
}

Commutator::Commutator() = default;

Commutator* Commutator::get_instance() {
    if (!obj)
        obj = new Commutator();
    return obj;
}
