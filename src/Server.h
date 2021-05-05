#pragma once

#include <string>
#include <queue>
#include "Message.h"

class RawCommand;

class Server {
    std::queue<std::string> queries;
    inline static Server* inst;

    Server();

public:
    int temp = 0;

    RawCommand Get();

    static Server* GetInstance();
};
