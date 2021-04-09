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
    int sign = 1;
    bool is_deg = false;
    std::string deg = "";
    raw += " ";
    bool last_space = false;
    for (size_t i = 0; i < raw.size(); ++i) {
        if (raw[i] != ' ')
            last_space = false;
        if (is_digit(raw[i])) {
            if (!is_deg)
                last_num += raw[i];
            else
                deg += raw[i];
        }
        if (raw[i] == 'x')
            continue;
        if (raw[i] == '^')
            is_deg = true;
        if (raw[i] == '+')
            sign = 1;
        if (raw[i] == '-')
            sign = -1;
        if (raw[i] == ' ') {
            if (last_space)
                continue;
            last_space = true;
            int coef;
            if (last_num != "")
                coef = std::stoi(last_num);
            else 
                coef = 1;
            int degree;
            if (deg != "")
                degree = std::stoi(deg);
            else
                degree = 0;

            if (new_coefs.size() == 0)
                new_coefs.resize(degree + 1);
            
            new_coefs[degree] = coef * sign;

            is_deg = false;
            last_num = "";
            deg = "";
        }
    }
    last_space = true;
}
