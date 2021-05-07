#include "Game.h"


template <typename Out>
void Split(const std::string& s, char sep, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, sep)) {
        *result++ = item;
    }
}

std::vector<std::string> Split(const std::string& s, char sep = ';') {
    std::vector<std::string> res;
    Split(s, sep, std::back_inserter(res));
    return res;
}

bool Game::set_config(const QHostAddress &addr, quint16 port) {
    Server::set_addr(addr, port);
    server = Server::get_instance();
    if (!server->is_running()) {
        runs = false;
        return false;
    }
    runs = true;
    return true;
}

void Game::Start() {
    CreateEnv();
    Run();
}

void Game::CreateEnv() {
    auto env = new Environment(Config::GetInstance()->size);
    Commutator::Receive(new EnvMsg(env));
}


void Game::Run() {
    server->start();
    Commutator::Receive(new PrintMsg("Your position is " +
    GameStat::GetInstance()->GetPlayer(1)->GetCoord().CoordPointFormat(), GameStat::GetInstance()->GetPlayer(1)));
    Commutator::Receive(new PrintMsg("Your position is " +
                                     GameStat::GetInstance()->GetPlayer(2)->GetCoord().CoordPointFormat(), GameStat::GetInstance()->GetPlayer(2)));
    while (runs) {
        RawCommand command = server->get();
        try {
            Commutator::Receive(Decompose(command.cmd, command.player_id));
            Commutator::Receive(new CreateCoins());
        } catch (const EmptyCommand&) {

        }
        catch (const BadGraph&) {
            Commutator::Receive(new PrintMsg("Bad graph", GameStat::GetInstance()->GetPlayer(command.player_id)));
        }
        catch (...) {
            Commutator::Receive(new PrintMsg("Unresolved Error occured", GameStat::GetInstance()->GetPlayer(command.player_id)));
        }
    }
}


Message* Game::Decompose(std::string raw, int player_id) {
    std::vector<std::string> tokens = Split(raw);
    if (tokens.size() == 0)
        throw EmptyCommand();
    std::string type_command = tokens[0];
    if (type_command == "CreateGraph") {
        return new CreateGraph(Poly(tokens[1]), player_id, type_command);
    } else if (type_command == "CreateUnit") {
        std::string unit_name = tokens[1];
        int graph_num = std::stoi(tokens[2]);
        return new CreateUnit(player_id, graph_num, unit_name, type_command + ';' + unit_name);
    } else if (type_command == "CreateTrap") {
        std::string trap_type = tokens[1];
        int x_coord = std::stoi(tokens[2]);
        int y_coord = std::stoi(tokens[3]);
        return new CreateTrap(trap_type, Point(x_coord, y_coord), player_id, type_command + ';' + trap_type);
    } else if (type_command == "ExitIntoSpace") {
        int x_coord = std::stoi(tokens[1]);
        int y_coord = std::stoi(tokens[2]);
        return new ExitIntoSpaceMsg(Point(x_coord, y_coord), player_id, type_command);
    } else if (type_command == "Capture") {
        return new CaptureMsg(Poly(tokens[1]), player_id, type_command);
    } else if (type_command == "DestroyCapturedGraph") {
        return new DestroyCapturedGraphMsg(player_id, std::stoi(tokens[1]), type_command);
    } else if (type_command == "DestroyOwnGraph") {
        return new DestroyOwnGraphMsg(player_id, std::stoi(tokens[1]), type_command);
    } else if (type_command == "SayHello") {
        return new SayHelloMsg(player_id, std::stoi(tokens[1]), type_command);
    } else if (type_command == "Move") {
        return new MoveMsg(player_id, std::stoi(tokens[1]), type_command);
    }
    return nullptr;
}

void Game::write(const PrintMsg& msg) {
    server->write(GameStat::GetInstance()->get_player_num(msg.player), msg.msg.c_str());
}

Game* Game::GetInstance() {
    if (!instance)
        instance = new Game();
    return instance;
}
