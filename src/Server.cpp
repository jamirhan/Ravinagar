#include "Server.h"

RawCommand Server::get() {
    if (temp == 0) {
        ++temp;
        return RawCommand("Graph x^5 + x^2 - 2x + 1", 1);
    }
    else if (temp == 1) {
        return RawCommand("Unit Spy 1", 1);
    }
    return RawCommand(".", 1);
}

Server::Server() = default;

Server* Server::get_instance() {
    if (!inst)
        inst = new Server();
    return inst;
}
