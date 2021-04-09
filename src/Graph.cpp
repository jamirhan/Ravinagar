#include "Graph.h"

#include <utility>


Graph::Graph(Poly polynom, Player* p): polynom(std::move(polynom)) {
    owner = p;
}

bool Graph::includes_point(Point) {
    return false;
}
