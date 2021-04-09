#include "Game.h"


std::string get_prefix(std::string val) {
    int i = 0;
    while (val[i] == ' ')
        ++i;
    std::string ans;
    while (i < val.size() && val[i] != ' ') {
        ans += val[i];
        ++i;
    }
    return ans;
}


std::string remove_prefix(std::string val) {
    int i = 0;
    while (val[i] == ' ')
        ++i;
    while (i < val.size() && val[i] != ' ') {
        ++i;
    }
    std::string ans;
    while (i < val.size()) {
        ans += val[i];
        ++i;
    }
    return ans;
}


void Game::start() {
    runs = true;
    server = Server::get_instance();
    create_env();
    run();
}

void Game::create_env() {
    auto env = new Environment(Config::get_instance()->size);
    Commutator::receive(new EnvMsg(env));
}


void Game::run() {
    while (runs) {
        RawCommand command = server->get();
        Commutator::receive(decompose(command.cmd, command.player_id));
        Commutator::receive(new CreateCoins());
    }
}


Message* Game::decompose(std::string raw, int player_id) {
    std::string first_word = get_prefix(raw);
    raw = remove_prefix(raw);
    if (first_word == "Graph") {
        auto cmd = new CreateGraph(Poly(raw), player_id);
        return cmd;
    } else if (first_word == "Unit") {
        std::string unit_name = get_prefix(raw);
        raw = remove_prefix(raw);
        int graph_num = std::stoi(raw);
        return new CreateUnit(player_id, graph_num, unit_name);
    } else if (first_word == "CreationTrap") {
        std::string type = get_prefix(raw);
        raw = remove_prefix(raw);
        std::string coords = raw.substr(1);
        return new CreateTrap(type, coords, player_id);
    }
    return new Message;
}


Game* Game::get_instance() {
    if (!instance)
        instance = new Game();
    return instance;
}
