#include "Point.h"
#include <regex>

Point::Point(int x, int y): x(x), y(y) {};

Point::Point() = default;

std::vector<std::string> split(const std::string& s) {
    std::regex re(" ");
    std::sregex_token_iterator
            first{s.begin(), s.end(), re, -1},
            last;
    return {first, last};
}


Point::Point(std::string cords_string) {
    std::vector<std::string> cords = split(cords_string);
    x = std::stoi(cords[0]);
    y = std::stoi(cords[1]);
}

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
