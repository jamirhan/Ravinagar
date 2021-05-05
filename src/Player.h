#pragma once

#include "Point.h"
#include <deque>


class Player {
    Point coord;
    bool moved = false;
public:
    bool IsMoved() const;

    void Move();

public:
    const Point& GetCoord() const;

private:
    int points = 0;
public:
    int GetPoints() const;

    Player() = delete;

    Player(int, int);

    void UpdateCoins(int);

    void Move(Point);
};
