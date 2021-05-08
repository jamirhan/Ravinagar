#include "GraphsComposer.h"


void GraphsComposer::AddGraph(Graph* new_graph) {
    graphs.push_back(new_graph);
}

Graph* GraphsComposer::GetPlayerGraphNum(Player* player, int graph_num) {
    int counter = 0;
    Graph* last_found;
    for (auto graph: graphs) {
        if (graph->GetOwner() == player) {
            ++counter;
            last_found = graph;
        }
        if (counter == graph_num) {
            return last_found;
        }
    }
    return nullptr;
}

bool GraphsComposer::Capture(Graph* captured_graph) {
    for (auto graph : graphs) {
        if (captured_graph->GetOwner() != graph->GetOwner() && !graph->IsCaptured() &&
            graph->FormulaFormat() == captured_graph->FormulaFormat()) {
            graph->Capture();
            return true;
        }
    }
    return false;
}

Graph* GraphsComposer::GetCapturedGraphNum(Player* player, int graph_num) {
    int counter = 0;
    Graph* last_found;
    for (auto graph: graphs) {
        if (graph->GetOwner() != player && graph->IsCaptured()) {
            ++counter;
            last_found = graph;
        }
        if (counter == graph_num) {
            return last_found;
        }
    }
    return nullptr;
}

void GraphsComposer::RemoveGraph(Graph* graph) {
    auto it = std::find(graphs.begin(), graphs.end(), graph);
    graphs.erase(it);
}

int GraphsComposer::GetAmountOwnGraphs(Player* player) {
    int res = 0;
    for (auto graph : graphs) {
        if (graph->GetOwner() == player) {
            res++;
        }
    }
    return res;
}

int GraphsComposer::GetAmountCapturedGraphs(Player* player) {
    int res = 0;
    for (auto graph : graphs) {
        if (graph->GetOwner() != player && graph->IsCaptured()) {
            res++;
        }
    }
    return res;
}


