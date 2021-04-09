#include "Message.h"

#include <utility>

Message::~Message() = default;

EnvMsg::EnvMsg(Environment* env): env(env) {};

EndMsg::EndMsg(std::string msg, Player* p): msg(std::move(msg)), winner(p) {};

CommandMsg::CommandMsg(std::string msg): msg(std::move(msg)) {};

RawCommand::RawCommand(std::string msg, int player_id): cmd(std::move(msg)), player_id(player_id) {}

CreateGraph::CreateGraph(Poly polynom, int p_id): polynom(std::move(polynom)), player_id(p_id) {};

CreateCoins::CreateCoins() {};

CreateTrap::CreateTrap(std::string type, std::string cords, int p_id) : type(type), cords(cords), player_id(p_id) {};

CreateUnit::CreateUnit(int p_id, int g_n, std::string name): player_id(p_id), graph_num(g_n), unit_name(std::move(name)) {}
