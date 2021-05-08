#pragma once

#include "Player.h"
#include "Graph.h"
#include <deque>
#include "Coin.h"
#include <string>
#include "../Traps/Trap.h"
#include "Unit.h"
#include "Environment.h"
//#include "Poly.h"

class Trap;

class Coin;

class Graph;

class Unit;

class Environment;

struct Message {
    virtual ~Message();
};


template <typename T>
struct ins_del_class : virtual Message {
    std::deque<T> ins;
    std::deque<T> del;

    ins_del_class(std::deque<T>* ins, std::deque<T>* del) {
        if (ins)
            this->ins = *ins;
        if (del)
            this->del = *del;
    }
};


using CoinUpdMsg = ins_del_class<Coin*>;
using GraphUpdMsg = ins_del_class<Graph*>;
using TrapUpdMsg = ins_del_class<Trap*>;
using UnitUpdMsg = ins_del_class<Unit*>;

struct EnvMsg : virtual Message {
    Environment* env;

    explicit EnvMsg(Environment*);
};

struct EndMsg : virtual Message {
    EndMsg();
};

struct CommandMsg : virtual Message {
    std::string msg;

    explicit CommandMsg(std::string);
};

struct CreateGraph : virtual Message {
    CreateGraph(Poly, int, std::string);

    Poly polynom;
    int player_id;
    std::string request;
};

struct CreateCoins : virtual Message {
    CreateCoins();
};

struct CreateTrap : virtual Message {
    CreateTrap(std::string type, const Point&, int, std::string);

    std::string type;
    int player_id;
    Point coord;
    std::string request;
};

struct OutputMessage: virtual Message {
    OutputMessage(int, std::string);
    int player_num;
    std::string msg;
};

struct CreateUnit : virtual Message {
    CreateUnit(int, int, std::string unit_name, std::string request);

    int player_id;
    int graph_num;
    std::string unit_name;
    std::string request;
};

struct RawCommand : virtual Message {
    RawCommand(std::string, int);
    std::string cmd;
    int player_id;
};

struct PrintMsg : virtual Message {
    PrintMsg(std::string msg, Player* player);

    std::string msg;
    Player* player;
};

struct ExitIntoSpaceMsg : virtual Message {
    ExitIntoSpaceMsg(Point point, int i, std::string request);

    Point coord;
    int player_id;
    std::string request;
};

struct CaptureMsg : virtual Message {
    CaptureMsg(const Poly& polynom, int playerId, const std::string& request);

    Poly polynom;
    int player_id;
    std::string request;
};

struct DestroyCapturedGraphMsg : virtual Message {
    DestroyCapturedGraphMsg(int player_id, int captured_graph_num, const std::string& request);

    int player_id;
    int captured_graph_num;
    std::string request;
};

struct DestroyOwnGraphMsg : virtual Message {
    DestroyOwnGraphMsg(int player_id, int graph_num, const std::string& request);

    int player_id;
    int graph_num;
    std::string request;
};

struct SayHelloMsg : virtual Message {
    SayHelloMsg(int player_id, int captured_graph_num, const std::string& request);

    int player_id;
    int captured_graph_num;
    std::string request;
};

struct MoveMsg : virtual Message {
    MoveMsg(int player_id, int graph_num, const std::string& request);

    int player_id;
    int graph_num;
    std::string request;
};
