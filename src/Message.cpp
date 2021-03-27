#include "Message.h"

Message::~Message() = default;

EnvMsg::EnvMsg(Environment* env): env(env) {};

EndMsg::EndMsg(std::string msg, Player* p): msg(msg), winner(p) {};

CommandMsg::CommandMsg(std::string msg): msg(msg) {};
