#include "Commutator.h"
#include "Traps/Builder/TrapsBuilder.h"

void Commutator::receive(Message* message) {
    if (dynamic_cast<EnvMsg*>(message)) {
        EnvMsg* emsg = dynamic_cast<EnvMsg*>(message);
        GameStat::get_instance()->set(emsg->env);
    } else if (dynamic_cast<CreateGraph*> (message)) {
        CreateGraph *msg = dynamic_cast<CreateGraph *>(message);
        Graph *new_graph = new Graph(msg->polynom, GameStat::get_instance()->get_player(msg->player_id));
        int catched = GameStat::get_instance()->get_coins().harvest(new_graph);
        GameStat::get_instance()->get_player(msg->player_id)->update_coins(catched);
        GameStat::get_instance()->get_traps().check(new_graph);
        GameStat::get_instance()->get_graphs().add_graph(new_graph);
    } else if (dynamic_cast<CreateCoins*> (message)) {
        CoinsBuilder* cb = new CoinsBuilder();
        Config* config = Config::get_instance();
        cb->set_AntiCoin(config->amountCreatedAntiCoins);
        cb->set_ClassicCoin(config->amountCreatedClassicCoins);
        cb->set_SuperCoin(config->amountCreatedSuperCoins);
        GameStat::get_instance()->get_coins().append(cb->get_result());
    } else if (dynamic_cast<CreateTrap*> (message)) {
        CreateTrap* msg = dynamic_cast<CreateTrap*>(message);
        TrapsBuilder* tb = new TrapsBuilder();
        Trap* new_trap = tb->generate(msg->type, msg->cords, GameStat::get_instance()->get_player(msg->player_id));
        GameStat::get_instance()->get_traps().add_trap(new_trap);
    }
}

Commutator::Commutator() = default;

Commutator* Commutator::get_instance() {
    if (!obj)
        obj = new Commutator();
    return obj;
}
