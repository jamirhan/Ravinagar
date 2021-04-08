#pragma once
#include <random>
#include "Builder/CoinsBuilder.h"
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
    static int get_size();
    static Message* decompose(std::string, int);
    void end();

public:

    static Game* get_instance();

    [[maybe_unused]] void start();

};
