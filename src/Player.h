#pragma once
#include "Point.h"
#include "Graph.h"
#include "../Traps/Trap.h"
#include "Unit.h"
#include <deque>


class Player {
    Point cords;
    int points = 0;
    Graph* last_graph;
public:
    Player() = delete;
    Player(int, int);
    void update_coins(int);
    void set_last_graph(Graph*);
    void move(Point);
};
