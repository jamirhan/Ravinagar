#pragma once

#include <random>
#include "../Server.h"
#include "Builder/CoinsBuilder.h"
#include "Config.h"
#include "../Commutator.h"
#include "../Message.h"
#include <string>

class Message;

class Server;

class Game {
    inline static Game* instance;
    bool runs = false;
    Server* server;

    void Run();

    static void CreateEnv();

    Game() = default;

    static Message* Decompose(std::string raw, int player_id);

    void End();

public:

    static Game* GetInstance();

    [[maybe_unused]] void Start();

};
