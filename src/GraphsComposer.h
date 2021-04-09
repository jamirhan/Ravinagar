#pragma once
#include <deque>
#include "Graph.h"

class GraphsComposer {
    std::deque<Graph*> graphs;
public:
    void add_graph(Graph*);
    Graph* get_player_graph_num(Player*, int);
};
