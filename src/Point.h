#pragma once
#include <cmath>
#include <random>

class Point {
    int x;
    int y;
    static const int epsilon = 1e-5;
public:
    Point();
    Point(int x, int y);
    bool operator==(const Point&);
    Point& operator=(const Point&);
    int get_x();
    int get_y();
};
