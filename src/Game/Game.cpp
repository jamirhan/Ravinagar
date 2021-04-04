#include "Game.h"

void Game::start() {
    runs = true;
    server = Server::get_instance();
    create_env();
    run();
}

int Game::get_size() {
    return 100;
}

void Game::create_env() {
    Environment* env = new Environment(get_size());
    Commutator::get_instance()->receive(new EnvMsg(env));
}

void Game::run() {
    while (runs) {
        RawCommand command = server->get();
        Commutator::get_instance()->receive(decompose(command.cmd, command.player_id));
    }
}

Message* Game::decompose(std::string raw, int player_id) {
    std::string first_word;
    int i = 0; 
    while (i < raw.size() && raw[i] != ' ') {
        first_word += raw[i];
    }
    if (first_word == "Graph") {
        std::string raw_poly = raw.substr(5);
        CreateGraph* cmd = new CreateGraph(Poly(raw_poly), player_id);
        return cmd;
    }
    return new Message;
}

Game* Game::get_instance() {
    if (!instance)
        instance = new Game();
    return instance;
}
