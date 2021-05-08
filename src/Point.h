#pragma once

#include <cmath>
#include <random>
#include "boost/lexical_cast.hpp"

struct Point {
    int x;
    int y;
    static const int epsilon = 1e-5;
public:
    Point();

    Point(std::string);

    Point(int x, int y);

    std::string CoordPointFormat() const;

    bool operator==(const Point&);

    Point& operator=(const Point&);
};
