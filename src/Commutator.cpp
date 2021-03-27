#include "Commutator.h"
#include <iostream>

void Commutator::receive(Message* message) {

    if (dynamic_cast<EnvMsg*>(message)) {
        EnvMsg* emsg = dynamic_cast<EnvMsg*>(message);
        GameStat::get_instance()->set(emsg->env);
    }

    else if (dynamic_cast<CommandMsg*> (message)) {
        std::cout << "commmand catched";
    }
}

Commutator::Commutator() = default;

Commutator* Commutator::get_instance() {
    if (!obj)
        obj = new Commutator();
    return obj;
}
