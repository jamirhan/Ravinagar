#include "Game/Game.h"


int main(int argc, char* argv[]) {
    if (argc >= 2) {
        std::string str_addr = argv[1];
        std::string str_port = argv[2];
        std::cout << str_addr << " " << str_port << '\n';
        quint16 port = std::stoi(str_port);
        QHostAddress addr = QHostAddress(str_addr.c_str());
<<<<<<< HEAD
        Game::get_instance()->set_config(addr, port);
        Game::get_instance()->start();
=======
        Game::GetInstance()->set_config(addr, port);
        Game::GetInstance()->Start();
>>>>>>> dev_2
    }
    else {
        exit(1);
    }
}
