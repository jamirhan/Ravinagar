#pragma once
#include "Poly.h"
#include "Point.h"
#include "Player.h"


class Graph {
    Poly polynom;
    Player* owner;
public:
    Graph(Poly, Player*);
    bool includes_point(Point);
};
