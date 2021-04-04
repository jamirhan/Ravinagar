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
    void create_env();
    Game() = default;
    Environment* get_mode();
    Player* set_player(int);
    int get_size();
    Message* decompose(std::string, int);

public:

    static Game* get_instance();
    void start();

};
