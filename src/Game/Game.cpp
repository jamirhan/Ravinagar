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
        std::string cmd = server->get();
        Commutator::get_instance()->receive(new CommandMsg(cmd));
    }
}

Game* Game::get_instance() {
    if (!instance)
        instance = new Game();
    return instance;
}
