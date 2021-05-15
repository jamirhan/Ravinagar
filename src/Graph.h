#pragma once

#include "Poly.h"
#include "Point.h"
#include "Player.h"
#include <boost/math/tools/polynomial.hpp>
#include <boost/lexical_cast.hpp>
#include "../root_finder/include/root_finder/root_finder.hpp"

using boost::lexical_cast;

class Graph {
    Player* owner;
    bool captured = false;
    Poly polynom; // TODO
public:
    Graph(Poly, Player*);

    bool IncludesPoint(Point);

    void RemoveGraph(Graph*);

    double Distance(Point);

    std::string FormulaFormat();

    Player* GetOwner();

    void Capture();

    bool IsCaptured();

    std::vector<Point> GetAffectedPoints();
};
