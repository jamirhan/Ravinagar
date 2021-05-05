#include "Point.h"

Point::Point(int x, int y) : x(x), y(y) {};

Point::Point() = default;

Point& Point::operator=(const Point& op) {
    x = op.x;
    y = op.y;
    return *this;
}

std::string Point::CoordPointFormat() const {
    return boost::lexical_cast<std::string>(x) + ' ' + boost::lexical_cast<std::string>(y);
}

bool Point::operator==(const Point& op) {
    return (std::abs(op.x - x) * std::abs(op.x - x) + std::abs(op.y - y) * std::abs(op.y - y) < epsilon);
}
