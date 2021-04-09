#include "Game.h"

void Game::start() {
    runs = true;
    server = Server::get_instance();
    create_env();
    run();
}

void Game::create_env() {
    Environment* env = new Environment(Config::get_instance()->size);
    Commutator::get_instance()->receive(new EnvMsg(env));
}

void Game::run() {
    while (runs) {
        RawCommand command = server->get();
        Commutator::get_instance()->receive(decompose(command.cmd, command.player_id));
        Commutator::get_instance()->receive(new CreateCoins());
    }
}

Message* Game::decompose(std::string raw, int player_id) {
    std::string first_word;
    int i = 0; 
    while (i < raw.size() && raw[i] != ' ') {
        first_word += raw[i];
        i++;
    }
    std::string rest = raw.substr(first_word.size() + 1);
    Message *cmd = nullptr;
    if (first_word == "Graph") {
        cmd = new CreateGraph(Poly(rest), player_id);
    } else if (first_word == "CreationTrap") {
        std::string second_word;
        i = 0;
        while (i < rest.size() && rest[i] != ' ') {
            second_word += rest[i];
            i++;
        }
        cmd = new CreateTrap(second_word, rest.substr(second_word.size() + 1), player_id);
    }
    return cmd;
}

Game* Game::get_instance() {
    if (!instance)
        instance = new Game();
    return instance;
}
