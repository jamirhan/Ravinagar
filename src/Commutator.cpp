#include "Commutator.h"
#include <iostream>


void Commutator::receive(Message *message) {
    if (dynamic_cast<EnvMsg*>(message)) {
        auto* msg = dynamic_cast<EnvMsg*>(message);
        GameStat::get_instance()->set(msg->env);
    }
    else if (dynamic_cast<CreateGraph*>(message)) {
        auto* msg = dynamic_cast<CreateGraph*>(message);
        auto* new_graph = new Graph(msg->polynom, GameStat::get_instance()->get_player(msg->player_id));
        int catched = GameStat::get_instance()->get_coins().harvest(new_graph);
        GameStat::get_instance()->get_player(msg->player_id)->update_coins(catched);
        GameStat::get_instance()->get_traps().check(new_graph);
        GameStat::get_instance()->get_graphs().add_graph(new_graph);
    }
    else if (dynamic_cast<CreateUnit*>(message)) {
        auto* msg = dynamic_cast<CreateUnit*>(message);
        Player* cur_player = GameStat::get_instance()->get_player(msg->player_id);
        Graph* required = GameStat::get_instance()->get_graphs().get_player_graph_num(cur_player, msg->graph_num);
        Unit* new_unit = nullptr;
        if (msg->unit_name == "Spy")
            new_unit = new Spy(required);
        else if (msg->unit_name == "BestFriend")
            new_unit = new BestFriend(required);
        else if (msg->unit_name == "Farmer")
            new_unit = new Farmer(required);
        else if (msg->unit_name == "CCTV")
            new_unit = new CCTV(required);
        GameStat::get_instance()->get_units().add_unit(new_unit);
        new_unit->check();
    }
}


Commutator::Commutator() = default;

Commutator* Commutator::get_instance() {
    if (!obj)
        obj = new Commutator();
    return obj;
}
