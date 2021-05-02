#pragma once
#include <random>
#include "Builder/CoinsBuilder.h"
#include "Config.h"
#include "../Commutator.h"
#include "../Message.h"
#include "../Server.h"
#include <string>


class Game {
    inline static Game* instance;
    bool runs = false;
    Server* server;

    void run();
    static void create_env();
    Game() = default;
    static Message* decompose(std::string, int);
    void end();

public:

    static Game* get_instance();

    void start();

    bool set_config(const QHostAddress& addr, quint16 port);

    void write(const OutputMessage& msg);

};
