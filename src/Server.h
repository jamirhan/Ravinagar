#pragma once
#include <string>
#include <queue>


class Server {
    std::queue<std::string> queries;
    inline static Server* inst;
    Server();
public:
    std::string get();
    static Server* get_instance();
};
