#pragma once
#include <string>
#include <queue>
#include "Message.h"


class Server {
    std::queue<std::string> queries;
    inline static Server* inst;
    Server();
public:
    RawCommand get();
    static Server* get_instance();
};
