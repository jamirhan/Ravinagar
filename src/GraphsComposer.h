#pragma once

#include <deque>
#include "Graph.h"
#include <algorithm>

class GraphsComposer {
    std::deque<Graph*> graphs;
public:
    void AddGraph(Graph* new_graph);

    bool Capture(Graph* captured_graph);

    void RemoveGraph(Graph*);

    Graph* GetPlayerGraphNum(Player* player, int graph_num);

    Graph* GetCapturedGraphNum(Player* player, int graph_num);


};
