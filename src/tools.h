#pragma once
#include <deque>


namespace gtools {
    template <typename T>
    void del(std::deque<T>&a, std::deque<T> b) {
        for (typename std::deque<T>::iterator el = a.begin(); el != a.end(); ++el) {
            for (auto to_del: b) {
                if (*el == to_del)
                    a.erase(el);
            }
        }
    }

    template <typename T>
    void insert(std::deque<T>& a, std::deque<T> b) {
        for (auto el: b) {
            a.push_back(el);
        }
    }
};
