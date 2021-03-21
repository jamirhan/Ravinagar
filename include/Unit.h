#ifndef RAVINAGAR_UNIT_H
#define RAVINAGAR_UNIT_H
#include "Graph.h"
#include "Message.h"

class Unit {
public:
    Graph graph;

    void send(Message);
};


#endif //RAVINAGAR_UNIT_H
