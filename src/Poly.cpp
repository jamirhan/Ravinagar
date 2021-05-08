#include "Poly.h"


bool is_digit(char a) {
    if (static_cast<int>(a) >= 48 && static_cast<int>(a) <= 57)
        return true;
    else
        return false;
}

Poly::Poly(std::string raw) {
    std::vector<int> new_coefs;
    std::string last_num = "";
    int coef = 1;
    int deg;
    int sign = 1;
//    bool last_up = false;
//    bool last_x = false;
//    bool is_last_num = false;
    bool is_deg = false;
    bool is_coef = true;

    if (raw.size() == 0)
        throw BadGraph();

    for (char i : raw) {
        if (is_coef) {
            if (is_digit(i)) {
                last_num += i;
            }
            else if (i == 'x') {
                is_coef = false;
                is_deg = true;
                if (last_num != "")
                    coef = std::stoi(last_num);
                else
                    coef = 1;
                last_num = "";
            }
            else {
                throw BadGraph();
            }
        }
        else if (is_deg) {
            if (i == '-' || i == '+') {
                if (last_num != "")
                    deg = std::stoi(last_num);
                else
                    deg = 1;
                if (deg >= new_coefs.size()) {
                    new_coefs.resize(deg + 1);
                }
                new_coefs[deg] = sign*coef;
                is_deg = false;
                is_coef = true;
                if (i=='-')
                    sign = -1;
                else
                    sign = 1;
                last_num = "";
            }
            else if (is_digit(i)) {
                last_num += i;
            }
        }
        else {
            throw BadGraph();
        }
    }

    if (is_coef) {
        deg = 0;
        if (last_num != "")
            coef = std::stoi(last_num);
        else
            coef = 1;
        if (deg >= new_coefs.size() ) {
            new_coefs.resize(deg + 1);
        }
        new_coefs[deg] = sign * coef;
        is_deg = false;
        is_coef = true;
    }

    else if (is_deg) {
        deg = std::stoi(last_num);
        if (deg >= new_coefs.size() ) {
            new_coefs.resize(deg + 1);
        }
        new_coefs[deg] = sign * coef;
        is_deg = false;
        is_coef = true;
    }
    poly.data() = new_coefs;
    coefs = new_coefs;
}
