#ifndef RAVINAGAR_GAME_H
#define RAVINAGAR_GAME_H
#include "Commutator.h"
#include "EnvironmentBuilder.h"
#include "Message.h"

class Game {
public:
    Commutator commute;

    void start();
    void send(const Message& message);
    void create(EnvironmentBuilder);
    void end();
};


#endif //RAVINAGAR_GAME_H
