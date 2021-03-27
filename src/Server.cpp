#include "Server.h"

std::string Server::get() {
    return "Wish you were here by Pink Floyd";
}

Server::Server() = default;

Server* Server::get_instance() {
    if (!inst)
        inst = new Server();
    return inst;
}
