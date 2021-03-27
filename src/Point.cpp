#include "Point.h"

Point::Point(int x, int y): x(x), y(y) {};

Point::Point() = default;

Point& Point::operator=(const Point& op) {
    x = op.x;
    y = op.y;
    return *this;
}

bool Point::operator==(const Point& op) {
    return (std::abs(op.x - x) < epsilon && std::abs(op.y - y) < epsilon);
}

int Point::get_x() {
    return x;
}

int Point::get_y() {
    return y;
}
