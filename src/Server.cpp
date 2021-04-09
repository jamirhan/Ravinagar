#include "Server.h"

RawCommand Server::get() {
//    return RawCommand("Graph x^2 + 2x + 1", 1);
    return RawCommand("CreationTrap Clone 2 2", 1);
}

Server::Server() = default;

Server* Server::get_instance() {
    if (!inst)
        inst = new Server();
    return inst;
}
