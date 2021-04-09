#include "Message.h"

Message::~Message() = default;

EnvMsg::EnvMsg(Environment* env): env(env) {};

EndMsg::EndMsg(std::string msg, Player* p): msg(msg), winner(p) {};

CommandMsg::CommandMsg(std::string msg): msg(msg) {};

RawCommand::RawCommand(std::string msg, int player_id): cmd(msg), player_id(player_id) {}

CreateGraph::CreateGraph(Poly polynom, int p_id): polynom(polynom), player_id(p_id) {};

CreateCoins::CreateCoins() {};

CreateTrap::CreateTrap(std::string type, std::string cords, int p_id) : type(type), cords(cords), player_id(p_id) {};
