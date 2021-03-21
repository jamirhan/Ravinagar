#ifndef RAVINAGAR_PLAYER_H
#define RAVINAGAR_PLAYER_H
#include "Point.h"
#include "Graph.h"
#include "Trap.h"
#include <vector>

class Player {
public:
    Point cords;
    std::vector<Graph> graphs;
    std::vector<Graph> controlled_graphs;
    std::vector<Trap> traps;
    Graph last_graph;
    int points;

    Player();
    Player(const Point&);
    void set_coins();
    void create_trap();
    void make_graph();
    void make_unit();
    Graph get_last_graph();
    Point get_cords();
    void make_guess();
    void send();
    void destroy_graph();
};


#endif //RAVINAGAR_PLAYER_H
