#pragma once
#include "Point.h"
#include <deque>


class Player {
    Point cords;
    int points = 0;
public:
    Player() = delete;
    Player(int, int);
    void update_coins(int);
    void move(Point);
};
