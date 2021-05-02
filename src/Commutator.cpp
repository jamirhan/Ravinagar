#include "Commutator.h"
#include "Traps/Builder/TrapsBuilder.h"

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
    } else if (dynamic_cast<CreateCoins*> (message)) {
        auto* cb = new CoinsBuilder();
        Config* config = Config::get_instance();
        cb->set_AntiCoin(Config::amountCreatedAntiCoins);
        cb->set_ClassicCoin(Config::amountCreatedClassicCoins);
        cb->set_SuperCoin(Config::amountCreatedSuperCoins);
        GameStat::get_instance()->get_coins().append(cb->get_result());
    } else if (dynamic_cast<CreateTrap*> (message)) {
        auto* msg = dynamic_cast<CreateTrap*>(message);
        auto* tb = new TrapsBuilder();
        Trap* new_trap = tb->generate(msg->type, msg->cords, GameStat::get_instance()->get_player(msg->player_id));
        GameStat::get_instance()->get_traps().add_trap(new_trap);
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
    else if (dynamic_cast<OutputMessage*>(message)){
        auto* msg = dynamic_cast<OutputMessage*>(message);
        Game::get_instance()->write(*msg);
    }
}


Commutator::Commutator() = default;

Commutator* Commutator::get_instance() {
    if (!obj)
        obj = new Commutator();
    return obj;
}
