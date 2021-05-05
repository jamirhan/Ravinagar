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

void Game::Start() {
    runs = true;
    server = Server::GetInstance();
    CreateEnv();
    Run();
}

void Game::CreateEnv() {
    auto env = new Environment(Config::GetInstance()->size);
    Commutator::Receive(new EnvMsg(env));
}


void Game::Run() {
    while (runs) {
        RawCommand command = server->Get();
        Commutator::Receive(Decompose(command.cmd, command.player_id));
        Commutator::Receive(new CreateCoins());
        {
            server->temp++;
            server->temp %= 3;
        }

    }
}


Message* Game::Decompose(std::string raw, int player_id) {
    std::vector<std::string> tokens = Split(raw);
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


Game* Game::GetInstance() {
    if (!instance)
        instance = new Game();
    return instance;
}
