#pragma once
#include "Player.h"
#include "Graph.h"
#include <deque>
#include "Coin.h"
#include <string>
#include "../Traps/Trap.h"
#include "Unit.h"
#include "Environment.h"
#include "Poly.h"


struct Message { // abstract class
    virtual ~Message();
};


template<typename T>
struct ins_del_class: virtual Message {
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


struct EnvMsg: virtual Message {
    Environment* env;
    EnvMsg(Environment*);
};

struct EndMsg: virtual Message {
    std::string msg;
    Player* winner;
    EndMsg(std::string, Player*);
};

struct CommandMsg: virtual Message {
    std::string msg;
    CommandMsg(std::string);
};

struct CreateGraph: virtual Message {
    CreateGraph(Poly, int);
    Poly polynom;
    int player_id;
};

struct RawCommand: virtual Message {
    RawCommand(std::string, int);
    std::string cmd;
    int player_id;
};
