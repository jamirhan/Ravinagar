#include "GraphsComposer.h"


void GraphsComposer::add_graph(Graph* new_graph) {
    graphs.push_back(new_graph);
}


Graph* GraphsComposer::get_player_graph_num(Player* player, int graph_num) {
    int counter = 0;
    Graph* last_found;
    for (auto graph: graphs) {
        if (graph->get_player() == player) {
            ++counter;
            last_found = graph;
        }
        if (counter == graph_num) {
            return last_found;
        }
    }
    return nullptr;
}
