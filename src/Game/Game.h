#pragma once

#include <random>
#include "../Server.h"
#include "Builder/CoinsBuilder.h"
#include "Config.h"
#include "../Commutator.h"
#include "../Message.h"
#include <string>
#include <QUdpSocket>
#include <QDtls>
#include <QtNetwork>

class Message;

class Server;

class PrintMsg;

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

    bool set_config(const QHostAddress& addr, quint16 port);

    [[maybe_unused]] void Start();

    void write(const PrintMsg& msg);

};