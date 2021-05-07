#pragma once

#include <string>
#include <vector>
#include "Point.h"
#include <boost/math/tools/polynomial.hpp>
#include "../Game/Config.h"

struct EmptyCommand: std::exception {

};

struct BadGraph: std::exception {

};

using namespace boost::math::tools;


struct Poly {
    std::vector<int> coefs;
    polynomial<int> poly;

    Poly(std::string);
};
