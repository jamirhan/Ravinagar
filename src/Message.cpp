#include "Message.h"
#include <utility>

Message::~Message() = default;

EnvMsg::EnvMsg(Environment* env) : env(env) {}

CommandMsg::CommandMsg(std::string msg) : msg(std::move(msg)) {};

RawCommand::RawCommand(std::string msg, int player_id) : cmd(std::move(msg)), player_id(player_id) {}

CreateGraph::CreateGraph(Poly polynom, int p_id, std::string request) : polynom(std::move(polynom)), player_id(p_id),
                                                                        request(request) {}

CreateCoins::CreateCoins() {};

CreateTrap::CreateTrap(std::string type, const Point& coords, int p_id, std::string request) : type(type),
                                                                                               coord(coords),
                                                                                               player_id(p_id),
                                                                                               request(request) {}

CreateUnit::CreateUnit(int p_id, int g_n, std::string name, std::string request) : player_id(p_id), graph_num(g_n),
                                                                                   unit_name(std::move(name)),
                                                                                   request(request) {}

PrintMsg::PrintMsg(std::string msg, Player* player) : msg(msg), player(player) {}

ExitIntoSpaceMsg::ExitIntoSpaceMsg(Point coord, int p_id, std::string request) : coord(coord), player_id(p_id),
                                                                                 request(request) {}

CaptureMsg::CaptureMsg(const Poly& polynom, int playerId, const std::string& request) : polynom(polynom),
                                                                                        player_id(playerId),
                                                                                        request(request) {}

DestroyCapturedGraphMsg::DestroyCapturedGraphMsg(int player_id, int captured_graph_num, const std::string& request)
        : player_id(player_id), captured_graph_num(captured_graph_num), request(request) {}

DestroyOwnGraphMsg::DestroyOwnGraphMsg(int player_id, int graph_num, const std::string& request)
        : player_id(player_id), graph_num(graph_num), request(request) {}

SayHelloMsg::SayHelloMsg(int player_id, int captured_graph_num, const std::string& request) : player_id(player_id),
                                                                                              captured_graph_num(
                                                                                                      captured_graph_num),
                                                                                              request(request) {}

MoveMsg::MoveMsg(int player_id, int graph_num, const std::string& request) : player_id(player_id),
                                                                             graph_num(graph_num),
                                                                             request(request) {}

EndMsg::EndMsg() {

<<<<<<< HEAD
CreateUnit::CreateUnit(int p_id, int g_n, std::string name): player_id(p_id), graph_num(g_n), unit_name(std::move(name)) {}

OutputMessage::OutputMessage(int p_n, std::string msg): player_num(p_n), msg(std::move(msg)) { }
=======
}
>>>>>>> dev_2
