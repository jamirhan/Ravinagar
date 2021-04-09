#include "Poly.h"

bool is_digit(char a) {
        if (static_cast<int>(a) >= 48 && static_cast<int>(a) <= 57)
            return true;
        else
            return false;
}

Poly::Poly(std::string raw) {
    std::vector<int> new_coefs;
    std::string last_num;
    int sign = 1;
    bool is_deg = false;
    std::string deg;
    raw += " ";
    bool last_space = true;
    bool is_x = false;
    for (char i : raw) {
        if (i != ' ')
            last_space = false;
        if (is_digit(i)) {
            if (!is_deg)
                last_num += i;
            else
                deg += i;
        }
        if (i == 'x') {
            is_x = true;
            continue;
        }
        else if (i == '^') {
            is_deg = true;
        }
        else if (i == '+') {
            sign = 1;
            last_space = true;
        }
        else if (i == '-') {
            sign = -1;
            last_space = true;
        }
        else if (i == ' ') {
            if (last_space)
                continue;
            last_space = true;
            int coef;
            if (!last_num.empty())
                coef = std::stoi(last_num);
            else 
                coef = 1;
            int degree;
            if (!deg.empty())
                degree = std::stoi(deg);
            else {
                if (is_x)
                    degree = 1;
                else
                    degree = 0;
            }

            if (new_coefs.empty())
                new_coefs.resize(degree + 1);
            
            new_coefs[degree] = coef * sign;

            is_deg = false;
            is_x = false;
            last_num = "";
            deg = "";
        }
    }
    coefs = new_coefs;
}
